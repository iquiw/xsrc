/* $Xorg: lut.c,v 1.3 2000/08/17 19:45:27 cpqbld Exp $ */

/*

Copyright 1993, 1998  The Open Group

All Rights Reserved.

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from The Open Group.

*/
/* $XFree86: xc/lib/XIE/lut.c,v 1.4 2001/01/17 19:42:22 dawes Exp $ */

#include "XIElibint.h"


XieLut
XieCreateLUT (Display *display)
{
    xieCreateLUTReq	*req;
    char		*pBuf;
    XieLut		id;

    LockDisplay (display);

    id = XAllocID (display);

    GET_REQUEST (CreateLUT, pBuf);

    BEGIN_REQUEST_HEADER (CreateLUT, pBuf, req);

    STORE_REQUEST_HEADER (CreateLUT, req);
    req->lut = id;

    END_REQUEST_HEADER (CreateLUT, pBuf, req);

    UnlockDisplay (display);
    SYNC_HANDLE (display);

    return (id);
}


void
XieDestroyLUT (Display *display, XieLut lut)
{
    xieDestroyLUTReq	*req;
    char		*pBuf;

    LockDisplay (display);

    GET_REQUEST (DestroyLUT, pBuf);

    BEGIN_REQUEST_HEADER (DestroyLUT, pBuf, req);

    STORE_REQUEST_HEADER (DestroyLUT, req);
    req->lut = lut;

    END_REQUEST_HEADER (DestroyLUT, pBuf, req);

    UnlockDisplay (display);
    SYNC_HANDLE (display);
}
