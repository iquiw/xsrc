/* $TOG: restart.h /main/5 1998/02/09 14:15:07 kaleb $ */
/******************************************************************************

Copyright 1993, 1998  The Open Group

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
******************************************************************************/
/* $XFree86: xc/programs/xsm/restart.h,v 1.3 1999/03/07 14:23:43 dawes Exp $ */

extern Bool CheckIsManager(char *program);
extern void GetRestartInfo(char *restart_service_prop, char *client_host_name,
			   Bool *run_local, char **restart_protocol, 
			   char **restart_machine);
extern Status Restart(int flag);
extern void Clone(ClientRec *client, Bool useSavedState);
extern void StartDefaultApps(void);
extern void StartNonSessionAwareApps(void);
