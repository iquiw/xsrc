/**************************************************************************
 *
 * Copyright 2018 Advanced Micro Devices, Inc.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

#include "util/u_handle_table.h"
#include "util/u_video.h"
#include "va_private.h"

VAStatus
vlVaHandleVAEncPictureParameterBufferTypeHEVC(vlVaDriver *drv, vlVaContext *context, vlVaBuffer *buf)
{
   VAEncPictureParameterBufferHEVC *h265;
   vlVaBuffer *coded_buf;
   int i;

   h265 = buf->data;
   context->desc.h265enc.decoded_curr_pic = h265->decoded_curr_pic.picture_id;

   for (i = 0; i < 15; i++)
      context->desc.h265enc.reference_frames[i] = h265->reference_frames[i].picture_id;

   context->desc.h265enc.pic_order_cnt = h265->decoded_curr_pic.pic_order_cnt;
   coded_buf = handle_table_get(drv->htab, h265->coded_buf);

   if (!coded_buf->derived_surface.resource)
      coded_buf->derived_surface.resource = pipe_buffer_create(drv->pipe->screen, PIPE_BIND_VERTEX_BUFFER,
                                            PIPE_USAGE_STREAM, coded_buf->size);

   context->coded_buf = coded_buf;
   context->desc.h265enc.pic.log2_parallel_merge_level_minus2 = h265->log2_parallel_merge_level_minus2;
   context->desc.h265enc.pic.nal_unit_type = h265->nal_unit_type;
   context->desc.h265enc.rc.quant_i_frames = h265->pic_init_qp;

   switch(h265->pic_fields.bits.coding_type) {
   case 1:
      if (h265->pic_fields.bits.idr_pic_flag)
         context->desc.h265enc.picture_type = PIPE_H265_ENC_PICTURE_TYPE_IDR;
      else
         context->desc.h265enc.picture_type = PIPE_H265_ENC_PICTURE_TYPE_I;
      break;
   case 2:
      context->desc.h265enc.picture_type = PIPE_H265_ENC_PICTURE_TYPE_P;
      break;
   case 3:
   case 4:
   case 5:
      return VA_STATUS_ERROR_UNIMPLEMENTED; //no b frame support
      break;
   }

   context->desc.h265enc.pic.constrained_intra_pred_flag = h265->pic_fields.bits.constrained_intra_pred_flag;

   util_hash_table_set(context->desc.h265enc.frame_idx,
                       UINT_TO_PTR(h265->decoded_curr_pic.picture_id),
                       UINT_TO_PTR(context->desc.h265enc.frame_num));

   return VA_STATUS_SUCCESS;
}

VAStatus
vlVaHandleVAEncSliceParameterBufferTypeHEVC(vlVaDriver *drv, vlVaContext *context, vlVaBuffer *buf)
{
   VAEncSliceParameterBufferHEVC *h265;

   h265 = buf->data;
   context->desc.h265enc.ref_idx_l0 = VA_INVALID_ID;
   context->desc.h265enc.ref_idx_l1 = VA_INVALID_ID;

   for (int i = 0; i < 15; i++) {
      if (h265->ref_pic_list0[i].picture_id != VA_INVALID_ID) {
         if (context->desc.h265enc.ref_idx_l0 == VA_INVALID_ID)
            context->desc.h265enc.ref_idx_l0 = PTR_TO_UINT(util_hash_table_get(context->desc.h265enc.frame_idx,
                                               UINT_TO_PTR(h265->ref_pic_list0[i].picture_id)));
      }
      if (h265->ref_pic_list1[i].picture_id != VA_INVALID_ID && h265->slice_type == 1) {
         if (context->desc.h265enc.ref_idx_l1 == VA_INVALID_ID)
            context->desc.h265enc.ref_idx_l1 = PTR_TO_UINT(util_hash_table_get(context->desc.h265enc.frame_idx,
                                               UINT_TO_PTR(h265->ref_pic_list1[i].picture_id)));
      }
   }

   context->desc.h265enc.slice.max_num_merge_cand = h265->max_num_merge_cand;
   context->desc.h265enc.slice.slice_cb_qp_offset = h265->slice_cb_qp_offset;
   context->desc.h265enc.slice.slice_cr_qp_offset = h265->slice_cr_qp_offset;
   context->desc.h265enc.slice.slice_beta_offset_div2 = h265->slice_beta_offset_div2;
   context->desc.h265enc.slice.slice_tc_offset_div2 = h265->slice_tc_offset_div2;
   context->desc.h265enc.slice.cabac_init_flag = h265->slice_fields.bits.cabac_init_flag;
   context->desc.h265enc.slice.slice_deblocking_filter_disabled_flag = h265->slice_fields.bits.slice_deblocking_filter_disabled_flag;
   context->desc.h265enc.slice.slice_loop_filter_across_slices_enabled_flag = h265->slice_fields.bits.slice_loop_filter_across_slices_enabled_flag;

   return VA_STATUS_SUCCESS;
}

VAStatus
vlVaHandleVAEncSequenceParameterBufferTypeHEVC(vlVaDriver *drv, vlVaContext *context, vlVaBuffer *buf)
{
   VAEncSequenceParameterBufferHEVC *h265 = (VAEncSequenceParameterBufferHEVC *)buf->data;

   if (!context->decoder) {
      context->templat.level = h265->general_level_idc;
      context->decoder = drv->pipe->create_video_codec(drv->pipe, &context->templat);

      if (!context->decoder)
         return VA_STATUS_ERROR_ALLOCATION_FAILED;
   }

   context->desc.h265enc.seq.general_profile_idc = h265->general_profile_idc;
   context->desc.h265enc.seq.general_level_idc = h265->general_level_idc;
   context->desc.h265enc.seq.general_tier_flag = h265->general_tier_flag;
   context->desc.h265enc.seq.intra_period = h265->intra_period;
   context->desc.h265enc.seq.pic_width_in_luma_samples = h265->pic_width_in_luma_samples;
   context->desc.h265enc.seq.pic_height_in_luma_samples = h265->pic_height_in_luma_samples;
   context->desc.h265enc.seq.chroma_format_idc = h265->seq_fields.bits.chroma_format_idc;
   context->desc.h265enc.seq.bit_depth_luma_minus8 = h265->seq_fields.bits.bit_depth_luma_minus8;
   context->desc.h265enc.seq.bit_depth_chroma_minus8 = h265->seq_fields.bits.bit_depth_chroma_minus8;
   context->desc.h265enc.seq.strong_intra_smoothing_enabled_flag = h265->seq_fields.bits.strong_intra_smoothing_enabled_flag;
   context->desc.h265enc.seq.amp_enabled_flag = h265->seq_fields.bits.amp_enabled_flag;
   context->desc.h265enc.seq.sample_adaptive_offset_enabled_flag = h265->seq_fields.bits.sample_adaptive_offset_enabled_flag;
   context->desc.h265enc.seq.pcm_enabled_flag = h265->seq_fields.bits.pcm_enabled_flag;
   context->desc.h265enc.seq.sps_temporal_mvp_enabled_flag = h265->seq_fields.bits.sps_temporal_mvp_enabled_flag;
   context->desc.h265enc.seq.log2_min_luma_coding_block_size_minus3 = h265->log2_min_luma_coding_block_size_minus3;
   context->desc.h265enc.seq.log2_diff_max_min_luma_coding_block_size = h265->log2_diff_max_min_luma_coding_block_size;
   context->desc.h265enc.seq.log2_min_transform_block_size_minus2 = h265->log2_min_transform_block_size_minus2;
   context->desc.h265enc.seq.log2_diff_max_min_transform_block_size = h265->log2_diff_max_min_transform_block_size;
   context->desc.h265enc.seq.max_transform_hierarchy_depth_inter = h265->max_transform_hierarchy_depth_inter;
   context->desc.h265enc.seq.max_transform_hierarchy_depth_intra = h265->max_transform_hierarchy_depth_intra;
   context->desc.h265enc.rc.frame_rate_num = h265->vui_time_scale;
   context->desc.h265enc.rc.frame_rate_den = h265->vui_num_units_in_tick;

   return VA_STATUS_SUCCESS;
}

VAStatus
vlVaHandleVAEncMiscParameterTypeRateControlHEVC(vlVaContext *context, VAEncMiscParameterBuffer *misc)
{
   VAEncMiscParameterRateControl *rc = (VAEncMiscParameterRateControl *)misc->data;

   if (context->desc.h265enc.rc.rate_ctrl_method ==
         PIPE_H265_ENC_RATE_CONTROL_METHOD_CONSTANT)
      context->desc.h265enc.rc.target_bitrate = rc->bits_per_second;
   else
      context->desc.h265enc.rc.target_bitrate = rc->bits_per_second * (rc->target_percentage / 100.0);
   context->desc.h265enc.rc.peak_bitrate = rc->bits_per_second;
   if (context->desc.h265enc.rc.target_bitrate < 2000000)
      context->desc.h265enc.rc.vbv_buffer_size = MIN2((context->desc.h265enc.rc.target_bitrate * 2.75), 2000000);
   else
      context->desc.h265enc.rc.vbv_buffer_size = context->desc.h265enc.rc.target_bitrate;

   return VA_STATUS_SUCCESS;
}

VAStatus
vlVaHandleVAEncMiscParameterTypeFrameRateHEVC(vlVaContext *context, VAEncMiscParameterBuffer *misc)
{
   VAEncMiscParameterFrameRate *fr = (VAEncMiscParameterFrameRate *)misc->data;

   if (fr->framerate & 0xffff0000) {
      context->desc.h265enc.rc.frame_rate_num = fr->framerate       & 0xffff;
      context->desc.h265enc.rc.frame_rate_den = fr->framerate >> 16 & 0xffff;
   } else {
      context->desc.h265enc.rc.frame_rate_num = fr->framerate;
      context->desc.h265enc.rc.frame_rate_den = 1;
   }

   return VA_STATUS_SUCCESS;
}

void getEncParamPresetH265(vlVaContext *context)
{
   //rate control
   context->desc.h265enc.rc.vbv_buffer_size = 20000000;
   context->desc.h265enc.rc.vbv_buf_lv = 48;
   context->desc.h265enc.rc.fill_data_enable = 1;
   context->desc.h265enc.rc.enforce_hrd = 1;
   if (context->desc.h265enc.rc.frame_rate_num == 0 ||
       context->desc.h265enc.rc.frame_rate_den == 0) {
      context->desc.h265enc.rc.frame_rate_num = 30;
      context->desc.h265enc.rc.frame_rate_den = 1;
   }
   context->desc.h265enc.rc.target_bits_picture =
      context->desc.h265enc.rc.target_bitrate *
      ((float)context->desc.h265enc.rc.frame_rate_den /
      context->desc.h265enc.rc.frame_rate_num);
   context->desc.h265enc.rc.peak_bits_picture_integer =
      context->desc.h265enc.rc.peak_bitrate *
      ((float)context->desc.h265enc.rc.frame_rate_den /
      context->desc.h265enc.rc.frame_rate_num);

   context->desc.h265enc.rc.peak_bits_picture_fraction = 0;
}
