/*	$NetBSD: rpccons.c,v 1.3 2004/03/13 19:43:33 bjh21 Exp $	*/

/*
 * Copyright (c) 1999 Mark Brinicombe & Neil A. Carson 
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * X11 driver code for VIDC20
 *
 */

/*
 * This is in a severely hacked up state and is a rush job to implement
 * a X server for the RiscPC.
 *
 * Most of the mouse and keyboard specific code has been separated into
 * a separate file to try and make things simpler when we support wscons
 * as well.
 *
 * A lot of cleanup is already being worked on.
 */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/* X11 headers
 */
#include "X.h"
#include "Xproto.h"
#include "screenint.h"
#include "input.h"
#include "cursor.h"
#include "misc.h"
#include "scrnintstr.h"
#include "servermd.h"
#include "mipointer.h"
#include "colormap.h"
#include "colormapst.h"
#include "resource.h"

/* NetBSD headers RiscPC specific */
#include <arm/iomd/vidc.h>
#include <machine/vconsole.h>
#include <machine/kbd.h>

/* Keymap, from XFree86*/
#include "atKeynames.h"

/* Our private translation table to work around the missing 8042 */
#include "kbd.h"

/* Our private definitions */
#include "private.h"

/*#define DEBUG*/

#ifdef DEBUG
#define DPRINTF(x) ErrorF x
#else
#define DPRINTF(x)
#endif

/* Path to various devices */
#define CON_PATH	"/dev/vidcvideo0"	/* Console */
#define KBD_PATH	"/dev/kbd"		/* Keyboard (rpc format) */

extern struct _private private;

void rpccons_write_palette(c, r, g, b)
	int	c;
	int	r;
	int	g;
	int	b;
{
	struct console_palette pal;

	DPRINTF(("write_palette: %d %d %d %d\n", c, r, g, b));
	pal.entry = c;
	pal.red = r;
	pal.green = g;
	pal.blue = b;
	ioctl(private.con_fd, CONSOLE_PALETTE, &pal);
}

void vidc_mousectrl(DeviceIntPtr device, PtrCtrl *ctrl)
{
	DPRINTF(("mousectrl\n"));
}

void vidc_kbdctrl(DeviceIntPtr device, KeybdCtrl *ctrl)
{
	DPRINTF(("kbdmousectrl\n"));
}

/* Handle IO signals for all input devices present
 */
#define TVTOMILLI(tv)   ((tv).tv_usec / 1000 + (tv).tv_sec * 1000)

void rpc_kbd_io(void)
{
	int was_kbd = 0;
	xEvent x_event;
	struct kbd_data kb;
	static int controlmask = 0;

	/*
	 * If it wasn't the mouse, try the keyboard and see what joys we have
	 * in store for us.
	 */
	while (read(private.kbd_fd, &kb, sizeof(kb)) > 0)
	{
		/* The user walloped a key */
		was_kbd = 1;

/*		ErrorF("kbd code=%x\n", kb.keycode);*/
		/* Get the time of the event as near as possible */
		x_event.u.keyButtonPointer.time = TVTOMILLI(kb.event_time);

		/* Was it a press or a release ? */
		if (kb.keycode & 0x100) {
			x_event.u.u.type = KeyRelease;
			kb.keycode &= ~0x100;
		} else
			x_event.u.u.type = KeyPress;

		/*
		 * Ok we now have a kludge to map the RiscPC raw keycodes
		 * to AT keycodes. We don't get AT keycodes as the RiscPC
		 * does not have a 8042 keyboard controller to translate
		 * the raw codes from the keyboard.
		 * We do the translation here so that we can then use
		 * existing PC keyboard mapping info.
		 * This is really just a hack as I don't want to spend
		 * time now figuring out the correct mappings when I can
		 * borrow existing AT ones.
		 */
		if (kb.keycode < 0x90 && kbdmap[kb.keycode] != -1) {
			x_event.u.u.detail = kbdmap[kb.keycode];
/*			ErrorF("xlated code=%x\n", kbdmap[kb.keycode]);*/
		} else if (kb.keycode > 0x210 && kb.keycode < 0x215
		    && kbdmap1[(kb.keycode - 0x210)] != -1) {
			x_event.u.u.detail = kbdmap1[(kb.keycode - 0x210)];
/*			ErrorF("xlated code=%x\n", kbdmap[kb.keycode - 0x210]);*/
		} else if (kb.keycode > 0x240 && kb.keycode < 0x280
		    && kbdmap2[(kb.keycode - 0x240)] != -1) {
			x_event.u.u.detail = kbdmap2[(kb.keycode - 0x240)];
/*			ErrorF("xlated code=%x\n", kbdmap[kb.keycode - 0x240]);*/
		} else
			continue;

		/*
		 * Bit of hackery to provide a Xserver kill hot key
		 *
		 * Could also be used to enable debug etc.etc.
		 */
		if (x_event.u.u.type == KeyPress) {
			if (x_event.u.u.detail == KEY_BackSpace)
				controlmask |= 1;
			else if (x_event.u.u.detail == KEY_RCtrl)
				controlmask |= 2;
			else if (x_event.u.u.detail == KEY_AltLang)
				controlmask |= 4;
		} else if (x_event.u.u.type == KeyRelease) {
			if (x_event.u.u.detail == KEY_BackSpace)
				controlmask &= ~1;
			else if (x_event.u.u.detail == KEY_RCtrl)
				controlmask &= ~2;
			else if (x_event.u.u.detail == KEY_AltLang)
				controlmask &= ~4;
		}

		if ((controlmask & 7) == 7)
			GiveUp(0);

		/* Enqueue the event */
		x_event.u.u.detail += MIN_KEYCODE;
		mieqEnqueue(&x_event);
	}
}

int rpc_init_kbd(void)
{
	int fd;
	int len;
	struct kbd_data kb;

	if ((fd = open(KBD_PATH, O_RDONLY | O_NONBLOCK)) < 0)
		return -1;

	/* Drain the keyboard buffer */
	do {
		len = read(private.kbd_fd, &kb, sizeof(kb));
	} while (len > 0);

	return fd;
}

int rpc_init_screen(ScreenPtr screen, int argc, char **argv)
{
	int cnt;
	struct console_info consinfo;
	int btime;
	int nconsole;

	DPRINTF(("vidc_init_screen\n"));

	private.rpc_origvc = -1;

	if ((private.con_fd = open(CON_PATH, O_RDONLY | O_NONBLOCK)) < 0)
		return FALSE;

	if (ioctl(private.con_fd, CONSOLE_GETVC, &private.rpc_origvc) != 0)
		FatalError("Couldn't get console number.\n");

	ErrorF("Started from console %d\n", private.rpc_origvc);

	nconsole = 8;
	if (ioctl(private.con_fd, CONSOLE_SPAWN_VIDC, &nconsole) != 0)
		FatalError("Couldn't spawn new console\n");

	ErrorF("Spawned console %d\n", nconsole);

	if (ioctl(private.con_fd, CONSOLE_SWITCHTO, &nconsole) != 0) {
		ErrorF("Couldn't switch to console %d\n", nconsole);
		FatalError((char *)sys_errlist[errno]);
	}

	if (ioctl(private.con_fd, CONSOLE_GETINFO, &consinfo) != 0) {
		ErrorF("Couldn't get console info for console\n");
		FatalError((char *)sys_errlist[errno]);
	}

/*	ErrorF("videomemory vbase = %08x\n", consinfo.videomemory.vidm_vbase);*/
	ErrorF("videomemory pbase = %08x\n", consinfo.videomemory.vidm_pbase);
/*	ErrorF("videomemory size  = %08x\n", consinfo.videomemory.vidm_size);
	ErrorF("videomemory type  = %08x\n", consinfo.videomemory.vidm_type);*/
	ErrorF("Frame buffer %d x %d x %d\n", consinfo.width, consinfo.height,
	    consinfo.bpp);

	if (ioctl(private.con_fd, CONSOLE_RESETSCREEN) != 0)
		FatalError("Couldn't reset console (%d).\n", errno);

	btime = 1;
	if (ioctl(private.con_fd, CONSOLE_BLANKTIME, &btime) != 0)
		FatalError("Couldn't set blanktime for console (%d)\n", errno);

	if ((private.vram_fd = open(CON_PATH, O_RDWR | O_NONBLOCK, 0)) < 0) {
		FatalError("Unable to open %s\n", CON_PATH);
		return FALSE;
	}

	private.xres = consinfo.width;
	private.yres = consinfo.height;
	private.depth = consinfo.bpp;
	private.width = (consinfo.width * consinfo.bpp) / 8;

	return TRUE;
}

void rpc_closedown(void)
{
	if (private.rpc_origvc != -1) {
		if (ioctl(private.con_fd, CONSOLE_SWITCHTO,
		    &private.rpc_origvc) != 0)
			ErrorF("Couldn't switch to console %d\n",
			    private.rpc_origvc);
	}
}
