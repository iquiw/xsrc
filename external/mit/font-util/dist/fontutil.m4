dnl fontutil.m4.  Generated from fontutil.m4.in by configure.
dnl
dnl This file comes from X.Org's font-util 1.1.1
dnl
dnl Copyright 2005 Red Hat, Inc
dnl
dnl Permission to use, copy, modify, distribute, and sell this software and its
dnl documentation for any purpose is hereby granted without fee, provided that
dnl the above copyright notice appear in all copies and that both that
dnl copyright notice and this permission notice appear in supporting
dnl documentation.
dnl
dnl The above copyright notice and this permission notice shall be included
dnl in all copies or substantial portions of the Software.
dnl
dnl THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
dnl OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
dnl MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
dnl IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
dnl OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
dnl ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
dnl OTHER DEALINGS IN THE SOFTWARE.
dnl
dnl Except as contained in this notice, the name of the copyright holders shall
dnl not be used in advertising or otherwise to promote the sale, use or
dnl other dealings in this Software without prior written authorization
dnl from the copyright holders.
dnl
dnl --------------------------------------------------------------------
dnl
dnl Copyright 2009 Sun Microsystems, Inc.  All rights reserved.
dnl
dnl Permission is hereby granted, free of charge, to any person obtaining a
dnl copy of this software and associated documentation files (the
dnl "Software"), to deal in the Software without restriction, including
dnl without limitation the rights to use, copy, modify, merge, publish,
dnl distribute, and/or sell copies of the Software, and to permit persons
dnl to whom the Software is furnished to do so, provided that the above
dnl copyright notice(s) and this permission notice appear in all copies of
dnl the Software and that both the above copyright notice(s) and this
dnl permission notice appear in supporting documentation.
dnl
dnl THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
dnl OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
dnl MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
dnl OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
dnl HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL
dnl INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING
dnl FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
dnl NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
dnl WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
dnl
dnl Except as contained in this notice, the name of a copyright holder
dnl shall not be used in advertising or otherwise to promote the sale, use
dnl or other dealings in this Software without prior written authorization
dnl of the copyright holder.

# XORG_FONT_MACROS_VERSION(required-version)
# ------------------------------------------
# Minimum version: 1.1.0
#
# If you're using a macro added in Version 1.1 or newer, include this in
# your configure.ac with the minimum required version, such as:
# XORG_FONT_MACROS_VERSION(1.1)
#
# To ensure that this macro is defined, also add:
# m4_ifndef([XORG_FONT_MACROS_VERSION],
#     [m4_fatal([must install X.Org font-util 1.1 or later before running autoconf/autogen])])
#
#
# See the "minimum version" comment for each macro you use to see what
# version you require.
m4_defun([XORG_FONT_MACROS_VERSION],[
m4_define([vers_have], [1.1.1])
m4_define([maj_have], m4_substr(vers_have, 0, m4_index(vers_have, [.])))
m4_define([maj_needed], m4_substr([$1], 0, m4_index([$1], [.])))
m4_if(m4_cmp(maj_have, maj_needed), 0,,
    [m4_fatal([font-util major version ]maj_needed[ is required but ]vers_have[ found])])
m4_if(m4_version_compare(vers_have, [$1]), -1,
    [m4_fatal([font-util version $1 or higher is required but ]vers_have[ found])])
m4_undefine([vers_have])
m4_undefine([maj_have])
m4_undefine([maj_needed])
]) # XORG_FONT_MACROS_VERSION

# XORG_FONT_CHECK_{maps}()
# ------------------------
# Minimum version: 1.0.0
# These macros add --enable/disable-{maps} where {maps} are ISO8859-*,
# JISX0201 or KOI8_R.  By default, they are all enabled.

AC_DEFUN([XORG_FONT_CHECK_ISO8859_1], [XORG_FONT_CHECK_ENCODING(ISO8859-1)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_2], [XORG_FONT_CHECK_ENCODING(ISO8859-2)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_3], [XORG_FONT_CHECK_ENCODING(ISO8859-3)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_4], [XORG_FONT_CHECK_ENCODING(ISO8859-4)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_5], [XORG_FONT_CHECK_ENCODING(ISO8859-5)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_6], [XORG_FONT_CHECK_ENCODING(ISO8859-6)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_7], [XORG_FONT_CHECK_ENCODING(ISO8859-7)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_8], [XORG_FONT_CHECK_ENCODING(ISO8859-8)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_9], [XORG_FONT_CHECK_ENCODING(ISO8859-9)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_10],[XORG_FONT_CHECK_ENCODING(ISO8859-10)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_11],[XORG_FONT_CHECK_ENCODING(ISO8859-11)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_12],[XORG_FONT_CHECK_ENCODING(ISO8859-12)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_13],[XORG_FONT_CHECK_ENCODING(ISO8859-13)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_14],[XORG_FONT_CHECK_ENCODING(ISO8859-14)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_15],[XORG_FONT_CHECK_ENCODING(ISO8859-15)])
AC_DEFUN([XORG_FONT_CHECK_ISO8859_16],[XORG_FONT_CHECK_ENCODING(ISO8859-16)])
AC_DEFUN([XORG_FONT_CHECK_JISX0201],  [XORG_FONT_CHECK_ENCODING(JISX0201)])
AC_DEFUN([XORG_FONT_CHECK_KOI8_R],    [XORG_FONT_CHECK_ENCODING(KOI8-R)])

# XORG_FONT_CHECK_ENCODING(encoding)
# ----------------------------------
# Minimum version: 1.1.0
# This macro adds --enable/disable-<encoding>, enabled by default.
# It replaced individual copies of this code in the above macros in 1.1.
# Currently assumes encoding names will be all upper-case - add m4_toupper
# calls if this is not true in the future.

AC_DEFUN([XORG_FONT_CHECK_ENCODING],[
	AC_ARG_ENABLE(m4_tolower($1),
		AS_HELP_STRING(m4_join([-], [--disable], m4_tolower($1)),
				[Build $1 fonts (default: yes)]),
		[AS_TR_SH($1)=$enableval], [AS_TR_SH($1)=yes])
	AC_MSG_CHECKING([whether to build $1 fonts])
	AC_MSG_RESULT($[AS_TR_SH($1)])
	AM_CONDITIONAL(AS_TR_SH($1), [test "x$AS_TR_SH($1)" = xyes])
]) # XORG_FONT_CHECK_ENCODING

# XORG_FONT_CHECK_ENCODING_LIST(encoding1 encoding2....)
# -----------------------------------------------------
# Minimum version: 1.1.0
# Call XORG_FONT_CHECK_ENCODING for multiple encodings at once

AC_DEFUN([XORG_FONT_CHECK_ENCODING_LIST],[
	m4_foreach_w([enc], [$1], [XORG_FONT_CHECK_ENCODING(enc)])
]) # XORG_FONT_CHECK_ENCODING_LIST

# XORG_FONT_REQUIRED_PROG(VARNAME, progname)
# ------------------------------------------
# Minimum version: 1.1.0
#
# Simple wrapper around AC_PATH_PROG that errors if not found
#

AC_DEFUN([XORG_FONT_REQUIRED_PROG],[
	AC_PATH_PROG($1, $2)
	if test x"$1" = x; then
		AC_MSG_ERROR([$2 is required to build $PACKAGE_NAME.])
	fi
])


# XORG_FONT_FCCACHE()
# -------------------
# Minimum version: 1.1.0
#
# Set FCCACHE to path to fc-cache (fontconfig cache builder) if found
# Set RUN_FCCACHE to a rule suitable for substituting into a makefile
# to run fc-cache if found and not installing to $DESTDIR
#
# fc-cache is optional, not required, and should be skipped when making
# packages (installing to $DESTDIR).
#
AC_DEFUN([XORG_FONT_FCCACHE],[
	AC_PATH_PROG(FCCACHE, fc-cache)
	FCCACHE_WARN='echo "** Warning: fonts.cache not built" ; echo "** Generate this file manually on host system using fc-cache"'
	if test x"$FCCACHE" = x ; then
		RUN_FCCACHE="${FCCACHE_WARN}"
	else
		RUN_FCCACHE='@(if test -z "$(DESTDIR)"; then echo $(FCCACHE) $(fontdir); $(FCCACHE) $(fontdir); else'
		RUN_FCCACHE="${RUN_FCCACHE} ${FCCACHE_WARN} ; fi)"
	fi
	AC_SUBST([RUN_FCCACHE])
])


# XORG_FONT_COMMON_UTILS()
# ------------------------
# Minimum version: 1.1.0
#
# Call XORG_FONT_REQUIRED_PROG for programs needed for all font types

AC_DEFUN([XORG_FONT_COMMON_UTILS],[
	XORG_FONT_FCCACHE
	XORG_FONT_REQUIRED_PROG(MKFONTDIR, mkfontdir)
])

# XORG_FONT_SCALED_UTILS()
# ------------------------
# Minimum version: 1.1.0
#
# Call XORG_FONT_REQUIRED_PROG for programs needed for scalable fonts
# (TrueType, OpenType, Type1)

AC_DEFUN([XORG_FONT_SCALED_UTILS],[
	XORG_FONT_COMMON_UTILS
	XORG_FONT_REQUIRED_PROG(MKFONTSCALE, mkfontscale)
])

# XORG_FONT_BDF_UTILS()
# ---------------------
# Minimum version: 1.1.0
#
# Call XORG_FONT_REQUIRED_PROG for programs needed for BDF format bitmap fonts
# Also call XORG_FONT_CHECK_COMPRESSION to determine how to compress the
# PCF output files created by bdftopcf

AC_DEFUN([XORG_FONT_BDF_UTILS],[
	XORG_FONT_COMMON_UTILS
	XORG_FONT_REQUIRED_PROG(BDFTOPCF, bdftopcf)
	XORG_FONT_CHECK_COMPRESSION
])

# XORG_FONT_CHECK_COMPRESSION()
# -----------------------------
# Minimum version: 1.1.0
#
# Offer a --with-compression flag to control what compression method is
# used for pcf font files.   Offers all the methods currently supported
# by libXfont, including no compression.

AC_DEFUN([XORG_FONT_CHECK_COMPRESSION],[
	AC_MSG_CHECKING([font compression method])
	AC_ARG_WITH(compression,
	 [AS_HELP_STRING([--with-compression=<no|compress|gzip|bzip2>],
			 [compression method to use on pcf fonts])],
         [compression="$withval"], [compression="yes"])
	if test x"$compression" = "xyes" ; then
		compression="gzip"
	fi
	AC_MSG_RESULT([${compression}])
	case ${compression} in
	 *compress)	COMPRESS_SUFFIX=".Z" ;;
	 *gzip)		COMPRESS_SUFFIX=".gz" ;;
	 *bzip2)	COMPRESS_SUFFIX=".bz2" ;;
	 no|none)	COMPRESS_SUFFIX="" ; COMPRESS="cat" ;;
	 *) AC_MSG_ERROR([${compression} is not a supported compression method]) ;;
	esac
	if test x"$COMPRESS_SUFFIX" != "x" ; then
	   XORG_FONT_REQUIRED_PROG(COMPRESS, ${compression})
	fi
	AC_SUBST([COMPRESS_SUFFIX])
])

# XORG_FONT_UCS2ANY()
# -------------------
# Minimum version: 1.1.0
#
# Call XORG_FONT_REQUIRED_PROG for ucs2any program needed for splitting
# Unicode-encoded BDF format bitmap fonts into subsets for older encodings.
# Also call pkg-config to find the directory with the encoding files needed
# by ucs2any, and export it as MAPFILES_PATH to the Makefiles

AC_DEFUN([XORG_FONT_UCS2ANY],[
	XORG_FONT_REQUIRED_PROG(UCS2ANY, ucs2any)
	PKG_CHECK_MODULES(MAPS, [fontutil])
	AC_MSG_CHECKING([for ucs2any encoding data files])
	MAPFILES_PATH=`pkg-config --variable=mapdir fontutil`
	AC_SUBST(MAPFILES_PATH)
	AC_MSG_RESULT([${MAPFILES_PATH}])
])



# XORG_FONTROOTDIR()
# --------------------
# Minimum version: 1.1.0
#
# Sets FONTROOTDIR to the root directory for font files.  Uses the first
# found from:
#	--with-fontrootdir
#	pkg-config --variable=fontrootdir fontutil
#	${datadir}/fonts/X11

AC_DEFUN([XORG_FONTROOTDIR],[
	dnl Ensure $PKG_CONFIG is set first
	AC_REQUIRE([PKG_PROG_PKG_CONFIG])

	AC_MSG_CHECKING([for root directory for font files])
	AC_ARG_WITH(fontrootdir,
		    AS_HELP_STRING([--with-fontrootdir=DIR],
			   [Path to root directory for font files]),
		    [FONTROOTDIR="$withval"])
	# if --with-fontrootdir not specified...
	if test "x${FONTROOTDIR}" = "x"; then
		FONTROOTDIR=`$PKG_CONFIG --variable=fontrootdir fontutil`
	fi
	# ...and if pkg-config didn't find fontdir in fontutil.pc...
	if test "x${FONTROOTDIR}" = "x"; then
		FONTROOTDIR="${datadir}/fonts/X11"
	fi
	AC_SUBST(FONTROOTDIR)
	AC_MSG_RESULT([${FONTROOTDIR}])
])

# XORG_FONTSUBDIR(variable, flag, subdir)
# ---------------------------------------
# Minimum version: 1.1.0
#
# Offer a --with-<flag> flag to control directory for font installation
# Default is the specified <subdir> of the font root directory.
# Sets <variable> to the selected directory

AC_DEFUN([XORG_FONTSUBDIR],[
	AC_REQUIRE([XORG_FONTROOTDIR])

	AC_MSG_CHECKING([for directory for $3 files])
	AC_ARG_WITH($2,
		    [AS_HELP_STRING([--with-$2=DIR],
				    [Path to $3 files [FONTROOTDIR/$3]])],
		    [$1="${withval}"], [$1='${FONTROOTDIR}/$3'])
	AC_SUBST($1)
	AC_MSG_RESULT([${$1}])
]) # XORG_FONTSUBDIR

# XORG_FONTDIR(subdir)
# --------------------
# Minimum version: 1.1.0
#
# Offer a --with-fontdir flag to control directory for font installation
# Default is the specified subdir of the font root directory.
# Sets FONTDIR to the selected directory

AC_DEFUN([XORG_FONTDIR],[XORG_FONTSUBDIR([FONTDIR], [fontdir], [$1])])