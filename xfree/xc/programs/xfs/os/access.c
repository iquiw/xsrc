/* $Xorg: access.c,v 1.3 2000/08/17 19:54:22 cpqbld Exp $ */
/*
 
Copyright 1990, 1991, 1998  The Open Group

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

 * Copyright 1990, 1991 Network Computing Devices;
 * Portions Copyright 1987 by Digital Equipment Corporation 
 *
 * Permission to use, copy, modify, distribute, and sell this software and
 * its documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the names of Network Computing Devices, or Digital
 * not be used in advertising or publicity pertaining to distribution
 * of the software without specific, written prior permission.
 *
 * NETWORK COMPUTING DEVICES, AND DIGITAL DISCLAIM ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL NETWORK COMPUTING DEVICES,
 * OR DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 */
/* $XFree86: xc/programs/xfs/os/access.c,v 3.4 2001/01/17 23:45:32 dawes Exp $ */

#include	<X11/Xos.h>
#ifndef MINIX
#ifndef Lynx
#include        <sys/param.h>
#include	<sys/socket.h>
#else
#include	<socket.h>
#endif
#include	<netdb.h>
#include	<netinet/in.h>
#else
#include <net/gen/netdb.h>
#endif /* !MINIX */
#include	"clientstr.h"
#include	"misc.h"
#include	"site.h"
#include	"accstr.h"
#include	"osdep.h"
#include	"osstruct.h"

long        MaxClients = DEFAULT_CLIENT_LIMIT;

void
AccessSetConnectionLimit(int num)
{
    num++;	/* take serverClient into account */
    if (num > MAXSOCKS) {
	ErrorF("Client limit of %d too high; using default of %d\n",
	       num, DEFAULT_CLIENT_LIMIT);
	return;
    }
    MaxClients = num;
}

/*
 * XXX
 *
 * needs massive amounts of OS-dependent work (big surprise)
 */
int
GetHostAddress(HostAddress *addr)
{
    char        hname[64];
    struct hostent *hp;

    addr->addr_len = sizeof(struct in_addr);
    addr->address = (pointer) fsalloc(addr->addr_len);
    if (!addr->address)
	return FSBadAlloc;
    addr->type = HOST_AF_INET;
    gethostname(hname, sizeof(hname));
    hp = gethostbyname(hname);
    if (hp) {
	memmove( (char *) addr->address, (char *) hp->h_addr, addr->addr_len);
    } else {
	fsfree((char *) addr->address);
	return FSBadName;
    }
    return FSSuccess;
}

/* ARGSUSED */
int
CheckClientAuthorization(
    ClientPtr   client,
    AuthPtr     client_auth,
    int        *accept,
    int        *index,
    int        *size,
    char      **auth_data)
{
    OsCommPtr	oc;
    int i;

    /* now that it's connected, zero the connect time
       so it doesn't get killed */
    oc = (OsCommPtr)client->osPrivate;
    oc->conn_time = 0;

    *size = 0;
    *accept = AuthSuccess;

    client->auth_generation++;

#define AUTH1_NAME "hp-hostname-1"
#define AUTH2_NAME "hp-printername-1"
    for (i = 0; i < *index; i++)
	if ((client_auth[i].namelen == sizeof(AUTH1_NAME) &&
	    !strcmp(client_auth[i].name, AUTH1_NAME)) ||
	    (client_auth[i].namelen == sizeof(AUTH2_NAME) &&
	    !strcmp(client_auth[i].name, AUTH2_NAME))) break;
    if (i == *index)
	i = 0;
    else
	i++;
    *index = i;
    return FSSuccess;
}
