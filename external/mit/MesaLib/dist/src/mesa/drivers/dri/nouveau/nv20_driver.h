/*
 * Copyright (C) 2009 Francisco Jerez.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __NV20_DRIVER_H__
#define __NV20_DRIVER_H__

enum {
	NOUVEAU_STATE_TEX_SHADER = NUM_NOUVEAU_STATE,
	NUM_NV20_STATE
};

#define NV20_TEXTURE_UNITS 4

/* nv20_context.c */
extern const struct nouveau_driver nv20_driver;

/* nv20_render.c */
void
nv20_render_init(GLcontext *ctx);

void
nv20_render_destroy(GLcontext *ctx);

/* nv20_state_fb.c */
void
nv20_emit_framebuffer(GLcontext *ctx, int emit);

void
nv20_emit_viewport(GLcontext *ctx, int emit);

/* nv20_state_polygon.c */
void
nv20_emit_point_mode(GLcontext *ctx, int emit);

/* nv20_state_raster.c */
void
nv20_emit_logic_opcode(GLcontext *ctx, int emit);

/* nv20_state_frag.c */
void
nv20_emit_tex_env(GLcontext *ctx, int emit);

void
nv20_emit_frag(GLcontext *ctx, int emit);

/* nv20_state_tex.c */
void
nv20_emit_tex_obj(GLcontext *ctx, int emit);

void
nv20_emit_tex_shader(GLcontext *ctx, int emit);

/* nv20_state_tnl.c */
void
nv20_emit_clip_plane(GLcontext *ctx, int emit);

void
nv20_emit_color_material(GLcontext *ctx, int emit);

void
nv20_emit_fog(GLcontext *ctx, int emit);

void
nv20_emit_light_model(GLcontext *ctx, int emit);

void
nv20_emit_light_source(GLcontext *ctx, int emit);

void
nv20_emit_material_ambient(GLcontext *ctx, int emit);

void
nv20_emit_material_diffuse(GLcontext *ctx, int emit);

void
nv20_emit_material_specular(GLcontext *ctx, int emit);

void
nv20_emit_material_shininess(GLcontext *ctx, int emit);

void
nv20_emit_modelview(GLcontext *ctx, int emit);

void
nv20_emit_projection(GLcontext *ctx, int emit);

#endif
