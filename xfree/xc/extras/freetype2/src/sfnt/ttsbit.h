/***************************************************************************/
/*                                                                         */
/*  ttsbit.h                                                               */
/*                                                                         */
/*    TrueType and OpenType embedded bitmap support (specification).       */
/*                                                                         */
/*  Copyright 1996-2001, 2002, 2003, 2004 by                               */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/
/* $XFree86: xc/extras/freetype2/src/sfnt/ttsbit.h,v 1.3 2004/04/26 16:15:55 dawes Exp $ */


#ifndef __TTSBIT_H__
#define __TTSBIT_H__


#include <ft2build.h>
#include "ttload.h"


FT_BEGIN_HEADER


  FT_LOCAL( FT_Error )
  tt_face_load_sbit_strikes( TT_Face    face,
                             FT_Stream  stream );

  FT_LOCAL( void )
  tt_face_free_sbit_strikes( TT_Face  face );


  FT_LOCAL( FT_Error )
  tt_face_set_sbit_strike( TT_Face    face,
                           FT_UInt    x_ppem,
                           FT_UInt    y_ppem,
                           FT_ULong  *astrike_index );

  FT_LOCAL( FT_Error )
  tt_find_sbit_image( TT_Face          face,
                      FT_UInt          glyph_index,
                      FT_ULong         strike_index,
                      TT_SBit_Range   *arange,
                      TT_SBit_Strike  *astrike,
                      FT_ULong        *aglyph_offset );

  FT_LOCAL( FT_Error )
  tt_load_sbit_metrics( FT_Stream        stream,
                        TT_SBit_Range    range,
                        TT_SBit_Metrics  metrics );

  FT_LOCAL( FT_Error )
  tt_face_load_sbit_image( TT_Face              face,
                           FT_ULong             strike_index,
                           FT_UInt              glyph_index,
                           FT_UInt              load_flags,
                           FT_Stream            stream,
                           FT_Bitmap           *map,
                           TT_SBit_MetricsRec  *metrics );


FT_END_HEADER

#endif /* __TTSBIT_H__ */


/* END */
