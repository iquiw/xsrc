/* $XFree86: xc/programs/Xserver/iplan2p4/iplpack.h,v 3.0 1996/08/18 01:54:57 dawes Exp $ */
/* Modified nov 94 by Martin Schaller (Martin_Schaller@maus.r.de) for use with
interleaved planes */

#define NUM_LONGS(planes, xs, xe)		\
	(((((xe) * (planes) + 31) & ~31) - 	\
	  (((xs) * (planes)) & ~31))/32)

#define NUM_TEMP_BYTES(planes, longs)		\
	(((2 * (longs) + (planes) - 1) / planes + 1) * planes * 2)
