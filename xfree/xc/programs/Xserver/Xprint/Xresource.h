/* $XFree86: xc/programs/Xserver/Xprint/Xresource.h,v 1.4 2000/09/28 14:50:57 tsi Exp $ */

/* $XConsortium: Xresource.h /main/1 1996/09/28 16:59:12 rws $ */
/*
(c) Copyright 1996 Hewlett-Packard Company
(c) Copyright 1996 International Business Machines Corp.
(c) Copyright 1996 Sun Microsystems, Inc.
(c) Copyright 1996 Novell, Inc.
(c) Copyright 1996 Digital Equipment Corp.
(c) Copyright 1996 Fujitsu Limited
(c) Copyright 1996 Hitachi, Ltd.

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
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the names of the copyright holders shall
not be used in advertising or otherwise to promote the sale, use or other
dealings in this Software without prior written authorization from said
copyright holders.
*/

/***********************************************************
Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts,
and the Massachusetts Institute of Technology, Cambridge, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the names of Digital or MIT not be
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

#ifndef _XRESOURCE_H_
#define _XRESOURCE_H_

/* You must include <X11/Xlib.h> before including this file */

/****************************************************************
 ****************************************************************
 ***                                                          ***
 ***                                                          ***
 ***          X Resource Manager Intrinsics                   ***
 ***                                                          ***
 ***                                                          ***
 ****************************************************************
 ****************************************************************/

_XFUNCPROTOBEGIN

/****************************************************************
 *
 * Memory Management
 *
 ****************************************************************/

extern char *Xpermalloc(
    unsigned int	/* size */
);

/****************************************************************
 *
 * Quark Management
 *
 ****************************************************************/

typedef int       XrmQuark, *XrmQuarkList;
#define NULLQUARK ((XrmQuark) 0)

typedef char *XrmString;
#define NULLSTRING ((XrmString) 0)

/* find quark for string, create new quark if none already exists */
extern XrmQuark XrmStringToQuark(
    _Xconst char* 	/* string */
);

extern XrmQuark XrmPermStringToQuark(
    _Xconst char* 	/* string */
);

/* find string for quark */
extern XrmString XrmQuarkToString(
    XrmQuark 		/* quark */
);

extern XrmQuark XrmUniqueQuark(
    void
);

#define XrmStringsEqual(a1, a2) (strcmp(a1, a2) == 0)


/****************************************************************
 *
 * Conversion of Strings to Lists
 *
 ****************************************************************/

typedef enum {XrmBindTightly, XrmBindLoosely} XrmBinding, *XrmBindingList;

extern void XrmStringToQuarkList(
    _Xconst char*	/* string */,
    XrmQuarkList	/* quarks_return */
);

extern void XrmStringToBindingQuarkList(
    _Xconst char*	/* string */,
    XrmBindingList	/* bindings_return */,
    XrmQuarkList	/* quarks_return */
);

/****************************************************************
 *
 * Name and Class lists.
 *
 ****************************************************************/

typedef XrmQuark     XrmName;
typedef XrmQuarkList XrmNameList;
#define XrmNameToString(name)		XrmQuarkToString(name)
#define XrmStringToName(string)		XrmStringToQuark(string)
#define XrmStringToNameList(str, name)	XrmStringToQuarkList(str, name)

typedef XrmQuark     XrmClass;
typedef XrmQuarkList XrmClassList;
#define XrmClassToString(c_class)	XrmQuarkToString(c_class)
#define XrmStringToClass(c_class)	XrmStringToQuark(c_class)
#define XrmStringToClassList(str,c_class) XrmStringToQuarkList(str, c_class)



/****************************************************************
 *
 * Resource Representation Types and Values
 *
 ****************************************************************/

typedef XrmQuark     XrmRepresentation;
#define XrmStringToRepresentation(string)   XrmStringToQuark(string)
#define	XrmRepresentationToString(type)   XrmQuarkToString(type)

typedef struct {
    unsigned int    size;
    XPointer	    addr;
} XrmValue, *XrmValuePtr;


/****************************************************************
 *
 * Resource Manager Functions
 *
 ****************************************************************/

typedef struct _XrmHashBucketRec *XrmHashBucket;
typedef XrmHashBucket *XrmHashTable;
typedef XrmHashTable XrmSearchList[];
typedef struct _XrmHashBucketRec *XrmDatabase;


extern void XrmDestroyDatabase(
    XrmDatabase		/* database */    
);

extern void XrmQPutResource(
    XrmDatabase*	/* database */,
    XrmBindingList	/* bindings */,
    XrmQuarkList	/* quarks */,
    XrmRepresentation	/* type */,
    XrmValue*		/* value */
);

extern void XrmPutResource(
    XrmDatabase*	/* database */,
    _Xconst char*	/* specifier */,
    _Xconst char*	/* type */,
    XrmValue*		/* value */
);

extern void XrmQPutStringResource(
    XrmDatabase*	/* database */,
    XrmBindingList      /* bindings */,
    XrmQuarkList	/* quarks */,
    _Xconst char*	/* value */
);

extern void XrmPutStringResource(
    XrmDatabase*	/* database */,
    _Xconst char*	/* specifier */,
    _Xconst char*	/* value */
);

extern void XrmPutLineResource(
    XrmDatabase*	/* database */,
    _Xconst char*	/* line */
);

extern  Bool XrmQGetResource(
    XrmDatabase		/* database */,
    XrmNameList		/* quark_name */,
    XrmClassList	/* quark_class */,
    XrmRepresentation*	/* quark_type_return */,
    XrmValue*		/* value_return */
);

extern Bool XrmGetResource(
    XrmDatabase		/* database */,
    _Xconst char*	/* str_name */,
    _Xconst char*	/* str_class */,
    char**		/* str_type_return */,
    XrmValue*		/* value_return */
);

extern Bool XrmQGetSearchList(
    XrmDatabase		/* database */,
    XrmNameList		/* names */,
    XrmClassList	/* classes */,
    XrmSearchList	/* list_return */,
    int			/* list_length */
);

extern Bool XrmQGetSearchResource(
    XrmSearchList	/* list */,
    XrmName		/* name */,
    XrmClass		/* class */,
    XrmRepresentation*	/* type_return */,
    XrmValue*		/* value_return */
);

/****************************************************************
 *
 * Resource Database Management
 *
 ****************************************************************/

#ifdef NOT_IN_SERVER

extern void XrmSetDatabase(
    Display*		/* display */,
    XrmDatabase		/* database */
);

extern XrmDatabase XrmGetDatabase(
    Display*		/* display */
);

#endif /* NOT_IN_SERVER */

extern XrmDatabase XrmGetFileDatabase(
    _Xconst char*	/* filename */
);

extern Status XrmCombineFileDatabase(
    _Xconst char* 	/* filename */,
    XrmDatabase*	/* target */,
    Bool		/* override */
);

extern XrmDatabase XrmGetStringDatabase(
    _Xconst char*	/* data */  /*  null terminated string */
);

extern void XrmPutFileDatabase(
    XrmDatabase		/* database */,
    _Xconst char*	/* filename */
);

extern void XrmMergeDatabases(
    XrmDatabase		/* source_db */,
    XrmDatabase*	/* target_db */
);

extern void XrmCombineDatabase(
    XrmDatabase		/* source_db */,
    XrmDatabase*	/* target_db */,
    Bool		/* override */
);

#define XrmEnumAllLevels 0
#define XrmEnumOneLevel  1

extern Bool XrmEnumerateDatabase(
    XrmDatabase		/* db */,
    XrmNameList		/* name_prefix */,
    XrmClassList	/* class_prefix */,
    int			/* mode */,
    Bool (*)(
	     XrmDatabase*	/* db */,
	     XrmBindingList	/* bindings */,
	     XrmQuarkList	/* quarks */,
	     XrmRepresentation*	/* type */,
	     XrmValue*		/* value */,
	     XPointer		/* closure */
	     )		/* proc */,
    XPointer		/* closure */
);

extern char *XrmLocaleOfDatabase(
    XrmDatabase 	/* database */
);


/****************************************************************
 *
 * Command line option mapping to resource entries
 *
 ****************************************************************/

typedef enum {
    XrmoptionNoArg,	/* Value is specified in OptionDescRec.value	    */
    XrmoptionIsArg,     /* Value is the option string itself		    */
    XrmoptionStickyArg, /* Value is characters immediately following option */
    XrmoptionSepArg,    /* Value is next argument in argv		    */
    XrmoptionResArg,	/* Resource and value in next argument in argv      */
    XrmoptionSkipArg,   /* Ignore this option and the next argument in argv */
    XrmoptionSkipLine,  /* Ignore this option and the rest of argv	    */
    XrmoptionSkipNArgs	/* Ignore this option and the next 
			   OptionDescRes.value arguments in argv */
} XrmOptionKind;

typedef struct {
    char	    *option;	    /* Option abbreviation in argv	    */
    char	    *specifier;     /* Resource specifier		    */
    XrmOptionKind   argKind;	    /* Which style of option it is	    */
    XPointer	    value;	    /* Value to provide if XrmoptionNoArg   */
} XrmOptionDescRec, *XrmOptionDescList;


extern void XrmParseCommand(
    XrmDatabase*	/* database */,
    XrmOptionDescList	/* table */,
    int			/* table_count */,
    _Xconst char*	/* name */,
    int*		/* argc_in_out */,
    char**		/* argv_in_out */		     
);

_XFUNCPROTOEND

#endif /* _XRESOURCE_H_ */
/* DON'T ADD STUFF AFTER THIS #endif */
