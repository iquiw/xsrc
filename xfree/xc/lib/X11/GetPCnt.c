/* $Xorg: GetPCnt.c,v 1.3 2000/08/17 19:44:34 cpqbld Exp $ */
/*

Copyright 1986, 1998  The Open Group

All Rights Reserved.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

*/
/* $XFree86: xc/lib/X11/GetPCnt.c,v 1.3 2001/01/17 19:41:36 dawes Exp $ */

#define NEED_REPLIES
#include "Xlibint.h"

int
XGetPointerControl(dpy, accel_numer, accel_denom, threshold)
     register Display *dpy;
     /* the following are return only vars */
     int *accel_numer, *accel_denom;
     int *threshold;
{       
    xGetPointerControlReply rep;
    xReq *req;
    LockDisplay(dpy);
    GetEmptyReq(GetPointerControl, req);
    (void) _XReply (dpy, (xReply *)&rep, 0, xTrue);
    *accel_numer = rep.accelNumerator;
    *accel_denom = rep.accelDenominator;
    *threshold = rep.threshold;
    UnlockDisplay(dpy);
    SyncHandle();
    return 1;
}

