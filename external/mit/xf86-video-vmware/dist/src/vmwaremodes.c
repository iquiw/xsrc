/*
 * Copyright 2007 by VMware, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of the copyright holder(s)
 * and author(s) shall not be used in advertising or otherwise to promote
 * the sale, use or other dealings in this Software without prior written
 * authorization from the copyright holder(s) and author(s).
 */

/*
 * vmwaremodes.c --
 *      
 *      Provide the supported modelines for the driver.
 *
 *      VMware does not have virtual monitor and there is no EDID to
 *      automatically report the supported mode. The list of
 *      supported modelines are manually added in the driver.
 */

#include "xf86.h"

#ifndef M_T_DRIVER
# define M_T_DRIVER  0x40	/* Supplied by the driver (EDID, etc) */
#endif

#define MODEPREFIX NULL, NULL, NULL, 0, M_T_DRIVER
#define MODESUFFIX 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,FALSE,FALSE,0,NULL,0,0.0,0.0

/*
 * Most of the modelines copied from DMTModes table of xf86EdidModes.c.
 * For those modes not in DMTModes table are generated by gtf
 */
static DisplayModeRec VMwareModes[] = {
   /* 4:3 modes */
   { MODEPREFIX,  5260,  320,  304,  336,  352, 0,  240,  241,  244,  249, 0, V_NHSYNC | V_NVSYNC, MODESUFFIX }, /* 320x240@60Hz,  GTF */
   { MODEPREFIX,  8660,  400,  392,  432,  464, 0,  300,  301,  304,  311, 0, V_NHSYNC | V_NVSYNC, MODESUFFIX }, /* 400x300@60Hz,  GTF */
   { MODEPREFIX, 14900,  512,  520,  568,  624, 0,  384,  385,  388,  398, 0, V_NHSYNC | V_NVSYNC, MODESUFFIX }, /* 512x384@60Hz,  GTF */
   { MODEPREFIX, 25175,  640,  656,  752,  800, 0,  480,  490,  492,  525, 0, V_NHSYNC | V_NVSYNC, MODESUFFIX }, /* 640x480@60Hz,  DMT */
   { MODEPREFIX, 40000,  800,  840,  968, 1056, 0,  600,  601,  605,  628, 0, V_PHSYNC | V_PVSYNC, MODESUFFIX }, /* 800x600@60Hz,  DMT */
   { MODEPREFIX, 65000, 1024, 1048, 1184, 1344, 0,  768,  771,  777,  806, 0, V_NHSYNC | V_NVSYNC, MODESUFFIX }, /* 1024x768@60Hz, DMT */
   { MODEPREFIX, 81620, 1152, 1216, 1336, 1520, 0,  864,  865,  868,  895, 0, V_NHSYNC | V_NVSYNC, MODESUFFIX }, /* 1152x864@60Hz, GTF */
   { MODEPREFIX,108000, 1280, 1376, 1488, 1800, 0,  960,  961,  964, 1000, 0, V_PHSYNC | V_PVSYNC, MODESUFFIX }, /* 1280x960@60Hz, DMT */
   { MODEPREFIX,121750, 1400, 1488, 1632, 1864, 0, 1050, 1053, 1057, 1089, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1400x1050@60Hz,DMT */
   { MODEPREFIX,162000, 1600, 1664, 1856, 2160, 0, 1200, 1201, 1204, 1250, 0, V_PHSYNC | V_PVSYNC, MODESUFFIX }, /* 1600x1200@60Hz,DMT */
   { MODEPREFIX,234000, 1920, 2048, 2256, 2600, 0, 1440, 1441, 1444, 1500, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1920x1440@60Hz,DMT */
   { MODEPREFIX,266950, 2048, 2200, 2424, 2800, 0, 1536, 1537, 1540, 1589, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 2048x1536@60Hz,GTF */
   { MODEPREFIX,421560, 2560, 2768, 3048, 3536, 0, 1920, 1921, 1924, 1987, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 2560x1920@60Hz,GTF */
   /* 16:9 modes */
   { MODEPREFIX, 31730,  856,  872,  960, 1064, 0,  480,  481,  484,  497, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 856x480@60Hz,  GTF */
   { MODEPREFIX, 74480, 1280, 1336, 1472, 1664, 0,  720,  721,  724,  746, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1280x720@60Hz, GTF */
   { MODEPREFIX, 85860, 1368, 1440, 1584, 1800, 0,  768,  769,  772,  795, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1368x768@60Hz, GTF */
   { MODEPREFIX,172800, 1920, 2040, 2248, 2576, 0, 1080, 1081, 1084, 1118, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1920x1080@60Hz,GTF */
   /* 16:10 modes */
   { MODEPREFIX, 83500, 1280, 1352, 1480, 1680, 0,  800,  803,  809,  831, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1280x800@60Hz, DMT */
   { MODEPREFIX,106500, 1440, 1520, 1672, 1904, 0,  900,  903,  909,  934, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1440x900@60Hz, DMT */
   { MODEPREFIX,146250, 1680, 1784, 1960, 2240, 0, 1050, 1053, 1059, 1089, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1680x1050@60Hz,DMT */
   { MODEPREFIX,193250, 1920, 2056, 2256, 2592, 0, 1200, 1203, 1209, 1245, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1920x1200@60Hz,DMT */
   { MODEPREFIX,348500, 2560, 2752, 3032, 3504, 0, 1600, 1603, 1609, 1658, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 2560x1600@60Hz,DMT */
   /* DVD modes */
   { MODEPREFIX, 26720,  720,  736,  808,  896, 0,  480,  481,  484,  497, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 720x480@60Hz,  GTF */
   { MODEPREFIX, 32670,  720,  744,  816,  912, 0,  576,  577,  580,  597, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 720x576@60Hz,  GTF */
   /* Odd modes */
   { MODEPREFIX,  4190,  320,  304,  328,  336, 0,  200,  201,  204,  208, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 320x200@60Hz,  GTF */
   { MODEPREFIX, 19520,  640,  648,  712,  784, 0,  400,  401,  404,  415, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 640x400@60Hz,  GTF */
   { MODEPREFIX, 29580,  800,  816,  896,  992, 0,  480,  481,  484,  497, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 800x480@60Hz,  GTF */
   { MODEPREFIX, 79500, 1280, 1344, 1472, 1664, 0,  768,  771,  778,  798, 0, V_NHSYNC | V_PVSYNC, MODESUFFIX }, /* 1280x768@60Hz, DMT */
   { MODEPREFIX,108000, 1280, 1328, 1440, 1688, 0, 1024, 1025, 1028, 1066, 0, V_PHSYNC | V_PVSYNC, MODESUFFIX }, /* 1280x1024@60Hz,DMT */
};


/*
 *-----------------------------------------------------------------------------
 *
 * vmwareGetSupportedModelines --
 *
 *    Get the supported modelines.
 *
 * Results:
 *    The supported modelines.
 *
 * Side effects:
 *    None.
 *
 *-----------------------------------------------------------------------------
 */

void
vmwareGetSupportedModelines(DisplayModePtr *monitorModes)
{
    DisplayModePtr modes = NULL, mode = NULL;
    int i = 0;

    if (monitorModes == NULL || *monitorModes == NULL) {
       return;
    }

#ifdef HAVE_XORG_SERVER_1_2_0
    for (i = 0; i < sizeof(VMwareModes)/sizeof(DisplayModeRec); i++) {
       mode = xf86DuplicateMode(&(VMwareModes[i]));
       modes = xf86ModesAdd(modes, mode);
    }

    *monitorModes = xf86ModesAdd(*monitorModes, modes);
#endif
}