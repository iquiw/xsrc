/* internal.h

   Internal definitions used by Expat.  This is not needed to compile
   client code.

   The following calling convention macros are defined for frequently
   called functions:

   FASTCALL    - Used for those internal functions that have a simple
                 body and a low number of arguments and local variables.

   PTRCALL     - Used for functions called though function pointers.

   PTRFASTCALL - Like PTRCALL, but for low number of arguments.

   inline      - Used for selected internal functions for which inlining
                 may improve performance on some platforms.

   Note: Use of these macros is based on judgement, not hard rules,
         and therefore subject to change.
*/
/* $XFree86: xc/extras/expat/lib/internal.h,v 1.2 2003/11/06 18:37:54 tsi Exp $ */

#if defined(__GNUC__) && defined(__i386__)

/* Instability reported with egcs on a RedHat Linux 7.3.
   Let's comment it out:
   #define FASTCALL __attribute__((stdcall, regparm(3)))
   and let's try this:
*/
#define FASTCALL __attribute__((regparm(3)))
#define PTRCALL
#define PTRFASTCALL __attribute__((regparm(3)))

#elif defined(WIN32)

/* Using __fastcall seems to have an unexpected negative effect under
   MS VC++, especially for function pointers, so we won't use it for
   now on that platform. It may be reconsidered for a future release
   if it can be made more effective.
   Likely reason: __fastcall on Windows is like stdcall, therefore
   the compiler cannot perform stack optimizations for call clusters.
*/
#define FASTCALL
#define PTRCALL
#define PTRFASTCALL

#endif

#ifndef FASTCALL
#define FASTCALL
#endif

#ifndef PTRCALL
#define PTRCALL
#endif

#ifndef PTRFASTCALL
#define PTRFASTCALL
#endif

#ifndef XML_MIN_SIZE
#if !defined(__cplusplus) && !defined(inline)
#ifdef __GNUC__
#define inline __inline
#endif /* __GNUC__ */
#endif
#endif /* XML_MIN_SIZE */

#ifdef __cplusplus
#define inline inline
#else
#ifndef inline
#define inline
#endif
#endif
