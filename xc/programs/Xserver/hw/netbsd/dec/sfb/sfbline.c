/*	$NetBSD: sfbline.c,v 1.1 2001/09/18 20:02:55 ad Exp $	*/

/***********************************************************

Copyright (c) 1987  X Consortium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from the X Consortium.


Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/
/* XConsortium: cfbline.c,v 1.24 94/07/28 14:33:33 dpw Exp */
/* XFree86: xc/programs/Xserver/cfb/cfbline.c,v 3.0 1996/06/29 09:05:38 dawes Exp */
#include "X.h"

#include "gcstruct.h"
#include "windowstr.h"
#include "pixmapstr.h"
#include "regionstr.h"
#include "scrnintstr.h"
#include "mistruct.h"

#include "dec.h"
#include "sfb.h"
#include "cfb.h"
#include "cfbmskbits.h"
#include "miline.h"

/* single-pixel lines on a color frame buffer

   NON-SLOPED LINES
   horizontal lines are always drawn left to right; we have to
move the endpoints right by one after they're swapped.
   horizontal lines will be confined to a single band of a
region.  the code finds that band (giving up if the lower
bound of the band is above the line we're drawing); then it
finds the first box in that band that contains part of the
line.  we clip the line to subsequent boxes in that band.
   vertical lines are always drawn top to bottom (y-increasing.)
this requires adding one to the y-coordinate of each endpoint
after swapping.

   SLOPED LINES
   when clipping a sloped line, we bring the second point inside
the clipping box, rather than one beyond it, and then add 1 to
the length of the line before drawing it.  this lets us use
the same box for finding the outcodes for both endpoints.  since
the equation for clipping the second endpoint to an edge gives us
1 beyond the edge, we then have to move the point towards the
first point by one step on the major axis.
   eventually, there will be a diagram here to explain what's going
on.  the method uses Cohen-Sutherland outcodes to determine
outsideness, and a method similar to Pike's layers for doing the
actual clipping.

*/

void
#ifdef POLYSEGMENT
sfbSegmentSS (pDrawable, pGC, nseg, pSeg)
    DrawablePtr	pDrawable;
    GCPtr	pGC;
    int		nseg;
    register xSegment	*pSeg;
#else
sfbLineSS (pDrawable, pGC, mode, npt, pptInit)
    DrawablePtr pDrawable;
    GCPtr	pGC;
    int		mode;		/* Origin or Previous */
    int		npt;		/* number of points */
    DDXPointPtr pptInit;
#endif
{
    int nboxInit;
    register int nbox;
    BoxPtr pboxInit;
    register BoxPtr pbox;
#ifndef POLYSEGMENT
    register DDXPointPtr ppt;	/* pointer to list of translated points */
#endif

    unsigned int oc1;		/* outcode of point 1 */
    unsigned int oc2;		/* outcode of point 2 */

    unsigned long *addrl;	/* address of destination pixmap */
    int nlwidth;		/* width in longwords of destination pixmap */
    int xorg, yorg;		/* origin of window */

    int adx;		/* abs values of dx and dy */
    int ady;
    int signdx;		/* sign of dx and dy */
    int signdy;
    int e, e1, e2;		/* bresenham error and increments */
    int len;			/* length of segment */
    int axis;			/* major axis */
    int octant;
    unsigned int bias = miGetZeroLineBias(pDrawable->pScreen);

				/* a bunch of temporaries */
    int tmp;
    register int y1, y2;
    register int x1, x2;
    RegionPtr cclip;
    cfbPrivGCPtr    devPriv;
    unsigned long   xor, and;
    int		    alu;

    devPriv = cfbGetGCPrivate(pGC);
    cclip = devPriv->pCompositeClip;
    pboxInit = REGION_RECTS(cclip);
    nboxInit = REGION_NUM_RECTS(cclip);

    cfbGetLongWidthAndPointer (pDrawable, nlwidth, addrl)

    alu = devPriv->rop;
    xor = devPriv->xor;
    and = devPriv->and;
    pwidth = XXX;

    xorg = pDrawable->x;
    yorg = pDrawable->y;

    /* XXX setup registers. */


#ifdef POLYSEGMENT
    while (nseg--)
#else
    ppt = pptInit;
    x2 = ppt->x + xorg;
    y2 = ppt->y + yorg;
    while(--npt)
#endif
    {
	nbox = nboxInit;
	pbox = pboxInit;

#ifdef POLYSEGMENT
	x1 = pSeg->x1 + xorg;
	y1 = pSeg->y1 + yorg;
	x2 = pSeg->x2 + xorg;
	y2 = pSeg->y2 + yorg;
	pSeg++;
#else
	x1 = x2;
	y1 = y2;
	++ppt;
	if (mode == CoordModePrevious)
	{
	    xorg = x1;
	    yorg = y1;
	}
	x2 = ppt->x + xorg;
	y2 = ppt->y + yorg;
#endif

	if (x1 == x2)  /* vertical line */
	{
	    /* make the line go top to bottom of screen, keeping
	       endpoint semantics
	    */
	    if (y1 > y2)
	    {
		register int tmp;

		tmp = y2;
		y2 = y1 + 1;
		y1 = tmp + 1;
#ifdef POLYSEGMENT
		if (pGC->capStyle != CapNotLast)
		    y1--;
#endif
	    }
#ifdef POLYSEGMENT
	    else if (pGC->capStyle != CapNotLast)
		y2++;
#endif
	    /* get to first band that might contain part of line */
	    while ((nbox) && (pbox->y2 <= y1))
	    {
		pbox++;
		nbox--;
	    }

	    if (nbox)
	    {
		/* stop when lower edge of box is beyond end of line */
		while((nbox) && (y2 >= pbox->y1))
		{
		    if ((x1 >= pbox->x1) && (x1 < pbox->x2))
		    {
			int y1t, y2t;
			/* this box has part of the line in it */
			y1t = max(y1, pbox->y1);
			y2t = min(y2, pbox->y2);
			if (y1t != y2t)
			{
			    sfbStraightS(reg, y2t-y1t, nlwidth << PWSH,
			        x1 * pwidth + y1t * (nlwidth << PWSH));
			}
		    }
		    nbox--;
		    pbox++;
		}
	    }
#ifndef POLYSEGMENT
	    y2 = ppt->y + yorg;
#endif
	}
	else if (y1 == y2)  /* horizontal line */
	{
	    /* force line from left to right, keeping
	       endpoint semantics
	    */
	    if (x1 > x2)
	    {
		register int tmp;

		tmp = x2;
		x2 = x1 + 1;
		x1 = tmp + 1;
#ifdef POLYSEGMENT
		if (pGC->capStyle != CapNotLast)
		    x1--;
#endif
	    }
#ifdef POLYSEGMENT
	    else if (pGC->capStyle != CapNotLast)
		x2++;
#endif

	    /* find the correct band */
	    while( (nbox) && (pbox->y2 <= y1))
	    {
		pbox++;
		nbox--;
	    }

	    /* try to draw the line, if we haven't gone beyond it */
	    if ((nbox) && (pbox->y1 <= y1))
	    {
		/* when we leave this band, we're done */
		tmp = pbox->y1;
		while((nbox) && (pbox->y1 == tmp))
		{
		    int	x1t, x2t;

		    if (pbox->x2 <= x1)
		    {
			/* skip boxes until one might contain start point */
			nbox--;
			pbox++;
			continue;
		    }

		    /* stop if left of box is beyond right of line */
		    if (pbox->x1 >= x2)
		    {
			nbox = 0;
			break;
		    }

		    x1t = max(x1, pbox->x1);
		    x2t = min(x2, pbox->x2);
		    if (x1t != x2t)
		    {
			sfbStraightS(reg, x2t-x1t, pwidth,
			    x1t * pwidth + y1 * (nlwidth << PWSH));
		    }
		    nbox--;
		    pbox++;
		}
	    }
#ifndef POLYSEGMENT
	    x2 = ppt->x + xorg;
#endif
	}
	else	/* sloped line */
	{
	    CalcLineDeltas(x1, y1, x2, y2, adx, ady, signdx, signdy,
			   1, 1, octant);

	    if (adx > ady)
	    {
		axis = X_AXIS;
		e1 = ady << 1;
		e2 = e1 - (adx << 1);
		e = e1 - adx;
 	    }
	    else
	    {
		axis = Y_AXIS;
		e1 = adx << 1;
		e2 = e1 - (ady << 1);
		e = e1 - ady;
		SetYMajorOctant(octant);
	    }

	    FIXUP_ERROR(e, octant, bias);

	    /* we have bresenham parameters and two points.
	       all we have to do now is clip and draw.
	    */

	    while(nbox--)
	    {
		oc1 = 0;
		oc2 = 0;
		OUTCODES(oc1, x1, y1, pbox);
		OUTCODES(oc2, x2, y2, pbox);
		if ((oc1 | oc2) == 0)
		{
		    if (axis == X_AXIS)
			len = adx;
		    else
			len = ady;
#ifdef POLYSEGMENT
		    if (pGC->capStyle != CapNotLast)
			len++;
#endif
		    sfbBresS (reg, addrl, nlwidth, pwidth,
			  signdx, signdy, axis, x1, y1,
			  e, e1, e2, len);
		    break;
		}
		else if (oc1 & oc2)
		{
		    pbox++;
		}
		else
		{
		    int new_x1 = x1, new_y1 = y1, new_x2 = x2, new_y2 = y2;
		    int clip1 = 0, clip2 = 0;
		    int clipdx, clipdy;
		    int err;
		    
		    if (miZeroClipLine(pbox->x1, pbox->y1, pbox->x2-1,
				       pbox->y2-1,
				       &new_x1, &new_y1, &new_x2, &new_y2,
				       adx, ady, &clip1, &clip2,
				       octant, bias, oc1, oc2) == -1)
		    {
			pbox++;
			continue;
		    }

		    if (axis == X_AXIS)
			len = abs(new_x2 - new_x1);
		    else
			len = abs(new_y2 - new_y1);
#ifdef POLYSEGMENT
		    if (clip2 != 0 || pGC->capStyle != CapNotLast)
			len++;
#else
		    len += (clip2 != 0);
#endif
		    if (len)
		    {
			/* unwind bresenham error term to first point */
			if (clip1)
			{
			    clipdx = abs(new_x1 - x1);
			    clipdy = abs(new_y1 - y1);
			    if (axis == X_AXIS)
				err = e+((clipdy*e2) + ((clipdx-clipdy)*e1));
			    else
				err = e+((clipdx*e2) + ((clipdy-clipdx)*e1));
			}
			else
			    err = e;
			    sfbBresS(reg, addrl, nlwidth, pwidth,
				     signdx, signdy, axis, new_x1, new_y1,
				     err, e1, e2, len);
		    }
		    pbox++;
		}
	    } /* while (nbox--) */
	} /* sloped line */
    } /* while (nline--) */

    /* XXX unsetup registers. */

#ifndef POLYSEGMENT
    /* paint the last point if the end style isn't CapNotLast.
       (Assume that a projecting, butt, or round cap that is one
        pixel wide is the same as the single pixel of the endpoint.)
    */

    if ((pGC->capStyle != CapNotLast) &&
	((ppt->x + xorg != pptInit->x + pDrawable->x) ||
	 (ppt->y + yorg != pptInit->y + pDrawable->y) ||
	 (ppt == pptInit + 1)))
    {
	nbox = nboxInit;
	pbox = pboxInit;
	while (nbox--)
	{
	    if ((x2 >= pbox->x1) &&
		(y2 >= pbox->y1) &&
		(x2 <  pbox->x2) &&
		(y2 <  pbox->y2))
	    {
		unsigned long mask;
		unsigned long scrbits;

		mask = cfbmask[x2 & PIM];
		addrl += (y2 * nlwidth) + (x2 >> PWSH);

		scrbits = *addrl;
		*addrl = (scrbits & ~mask) |
			 (DoRRop (scrbits, and, xor) & mask);
		break;
	    }
	    else
		pbox++;
	}
    }
#endif
}

void
sfbBresS(reg, nlwidth, pwidth, signdx, signdy, axis, x1, y1, e, e1, e2, len)
    volatile u_int32_t	*reg;		/* sfb registers */
    int			nlwidth;	/* width in longwords of bitmap */
    int			pwidth;		/* pixel width in bytes;
    int			signdx;		/* signs of directions */
    int			signdy;
    int			axis;		/* major axis (Y_AXIS or X_AXIS) */
    int			x1, y1;		/* initial point */
    int			e;		/* error accumulator */
    int			e1;		/* bresenham increments */
    int			e2;
    int			len;		/* length of line */
{
    int	e3, t;

    if (len == 0)
    	return;

    e3 = e2 - e1;
    e = e - e1;
    nlwidth <<= PWSH;
    signdx *= pwidth;

    reg[SFB_REG_GADR] = (y1 * nlwidth) + (x1 * pwidth);

    if (signdy < 0)
    	nlwidth = -nlwidth;

    if (axis == Y_AXIS) {
	t = nlwidth;
	nlwidth = signdx;
	signdx = t;
    }

    reg[SFB_REG_GB1R] = signdx << 16;
    reg[SFB_REG_GB2R] = ((signdx + nlwidth) << 16) | (-e3 & 0xffff);

    if (len >= 16) {
        reg[SFB_REG_GB3R] = e << 16;
        sfb_mb();

        do {
            reg[SFB_REG_GCTR] = 0;
            sfb_mb();
            len -= 16;
            /* XXX wait */
        } while (len >= 16);
    } else
        reg[SFB_REG_GB3R] = e << 16;

    if (len != 0) {
        reg[SFB_REG_GB3R] |= len;
        sfb_mb();
        reg[SFB_REG_GCTR] = 0;
        sfb_mb();
        /* XXX wait */
    }
}

void
sfbStraightS(reg, len, inc, off)
    volatile u_int32_t	*reg;
    int			len;
    int			inc;
    int			off;
{

    if (len == 0)
    	return;

    reg[SFB_REG_GADR] = off;
    reg[SFB_REG_GB1R] = inc << 16;
    reg[SFB_REG_GB2R] = inc << 16;

    if (len >= 16) {
        reg[SFB_REG_GB3R] = 0;
        sfb_mb();

        do {
            reg[SFB_REG_GCTR] = 0;
            sfb_mb();
            len -= 16;
            /* XXX wait */
        } while (len >= 16);
    }

    if (len != 0) {
        reg[SFB_REG_GB3R] = len;
        sfb_mb();
        reg[SFB_REG_GCTR] = 0;
        sfb_mb();
        /* XXX wait */
    }
}
