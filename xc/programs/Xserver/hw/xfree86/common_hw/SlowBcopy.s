/* $XFree86: xc/programs/Xserver/hw/xfree86/common_hw/SlowBcopy.s,v 3.2 1996/02/04 09:06:54 dawes Exp $ */
/*******************************************************************************
                        Copyright 1994 by Glenn G. Lai

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyr notice appear in all copies and that
both that copyr notice and this permission notice appear in
supporting documentation, and that the name of Glenn G. Lai not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

Glenn G. Lai DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

Glenn G. Lai
P.O. Box 4314
Austin, Tx 78765
glenn@cs.utexas.edu)
7/21/94
*******************************************************************************/
/* $XConsortium: SlowBcopy.s /main/3 1995/11/12 19:30:29 kaleb $ */
 
/* 
 *   Modified from the output generated by GCC
 *
 *   Create a dependency that should be immune from the effect of register
 *   renaming as is commonly seen in superscalar processors.  This should
 *   insert a minimum of 100-ns delays between reads/writes at clock rates
 *   up to 100 MHz---GGL
 *   
 *   Slowbcopy(char *src, char *dst, int count)   
 *   
 */ 

#include "assyntax.h"

	FILE("SlowBcopy.s")

	AS_BEGIN

gcc2_compiled.:
___gnu_compiled_c:

	GLOBL	GLNAME(SlowBcopy)

	SEG_TEXT
	ALIGNTEXT4
GLNAME(SlowBcopy):
	PUSH_L	(EBP)
	MOV_L	(ESP,EBP)
	PUSH_L	(ESI)
	PUSH_L	(EBX)
	MOV_L	(REGOFF(8,EBP),ECX)
	MOV_L	(REGOFF(12,EBP),EDX)
	MOV_L	(REGOFF(16,EBP),ESI)
	XOR_L	(EAX,EAX)
	CMP_L	(ESI,EAX)
	JGE	(L3)

	ALIGNTEXT4
L5:
	MOV_B	(REGIND(ECX),BL)

	MOV_B	(BL, BH)
	MOV_B	(BH, BL)
	MOV_B	(BL, BH)
	MOV_B	(BH, BL)
	MOV_B	(BL, BH)
	MOV_B	(BH, BL)
	MOV_B	(BL, BH)
	MOV_B	(BH, BL)
	MOV_B	(BL, BH)
	MOV_B	(BH, BL)

	MOV_B	(BL,REGIND(EDX))

	INC_L	(ECX)
	DEC_L	(ECX)
	INC_L	(ECX)
	DEC_L	(ECX)
	INC_L	(ECX)
	DEC_L	(ECX)
	INC_L	(ECX)
	DEC_L	(ECX)
	INC_L	(ECX)
	DEC_L	(ECX)

	INC_L	(ECX)
	INC_L	(EDX)
	INC_L	(EAX)
	CMP_L	(ESI,EAX)
	JL	(L5)
L3:
	LEA_L	(REGOFF(-8,EBP),ESP)
	POP_L	(EBX)
	POP_L	(ESI)
	MOV_L	(EBP,ESP)
	POP_L	(EBP)
	RET

