/**************************************************************************
 * 
 * Copyright 2009 VMware, Inc.
 * All Rights Reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL VMWARE AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 **************************************************************************/

/**
 * @file
 * Symbol lookup.
 * 
 * @author Jose Fonseca <jfonseca@vmware.com>
 */

#include "pipe/p_compiler.h"
#include "os/os_thread.h"
#include "u_string.h"

#include "u_debug.h"
#include "u_debug_symbol.h"
#include "u_hash_table.h"


#if defined(PIPE_OS_WINDOWS)
   
#include <windows.h>
#include <stddef.h>

#include "dbghelp.h"


/**
 * SymInitialize() must be called once for each process (in this case, the
 * current process), before any of the other functions can be called.
 */
static BOOL g_bSymInitialized = FALSE;


/**
 * Lookup the address of a DbgHelp function.
 */
static FARPROC WINAPI
getDbgHelpProcAddress(LPCSTR lpProcName)
{
   static HMODULE hModule = NULL;

   if (!hModule) {
      static boolean bail = FALSE;

      if (bail) {
         return NULL;
      }

#ifdef PIPE_CC_GCC
      /*
       * DbgHelp does not understand the debug information generated by MinGW toolchain.
       *
       * mgwhelp.dll is a dbghelp.dll look-alike replacement, which is able to
       * understand MinGW symbols, including on 64-bit builds.
       */
      if (!hModule) {
         hModule = LoadLibraryA("mgwhelp.dll");
         if (!hModule) {
            _debug_printf("warning: mgwhelp.dll not found: symbol names will not be resolved\n"
                          "warning: download it from http://code.google.com/p/jrfonseca/wiki/DrMingw#MgwHelp\n");
         }
      }

      /*
       * bfdhelp.dll was the predecessor of mgwhelp.dll.  It is available from
       * http://people.freedesktop.org/~jrfonseca/bfdhelp/ for now.
       */
      if (!hModule) {
         hModule = LoadLibraryA("bfdhelp.dll");
      }
   #endif

      /*
       * Fallback to the real DbgHelp.
       */
      if (!hModule) {
         hModule = LoadLibraryA("dbghelp.dll");
      }

      if (!hModule) {
         bail = TRUE;
         return NULL;
      }
   }

   return GetProcAddress(hModule, lpProcName);
}


/**
 * Generic macro to dispatch a DbgHelp functions.
 */
#define DBGHELP_DISPATCH(_name, _ret_type, _ret_default, _arg_types, _arg_names) \
   static _ret_type WINAPI \
   j_##_name _arg_types \
   { \
      typedef BOOL (WINAPI *PFN) _arg_types; \
      static PFN pfn = NULL; \
      if (!pfn) { \
         pfn = (PFN) getDbgHelpProcAddress(#_name); \
         if (!pfn) { \
            return _ret_default; \
         } \
      } \
      return pfn _arg_names; \
   }

DBGHELP_DISPATCH(SymInitialize,
                 BOOL, 0,
                 (HANDLE hProcess, PSTR UserSearchPath, BOOL fInvadeProcess),
                 (hProcess, UserSearchPath, fInvadeProcess))

DBGHELP_DISPATCH(SymSetOptions,
                 DWORD, FALSE,
                 (DWORD SymOptions),
                 (SymOptions))

DBGHELP_DISPATCH(SymFromAddr,
                 BOOL, FALSE,
                 (HANDLE hProcess, DWORD64 Address, PDWORD64 Displacement, PSYMBOL_INFO Symbol),
                 (hProcess, Address, Displacement, Symbol))

DBGHELP_DISPATCH(SymGetLineFromAddr64,
                 BOOL, FALSE,
                 (HANDLE hProcess, DWORD64 dwAddr, PDWORD pdwDisplacement, PIMAGEHLP_LINE64 Line),
                 (hProcess, dwAddr, pdwDisplacement, Line))


#undef DBGHELP_DISPATCH


static INLINE boolean
debug_symbol_name_dbghelp(const void *addr, char* buf, unsigned size)
{
   DWORD64 dwAddr = (DWORD64)(uintptr_t)addr;
   HANDLE hProcess = GetCurrentProcess();

   /* General purpose buffer, to back pSymbol and other temporary stuff.
    * Must not be too memory hungry here to avoid stack overflows.
    */
   CHAR buffer[512];

   PSYMBOL_INFO pSymbol = (PSYMBOL_INFO) buffer;
   DWORD64 dwDisplacement = 0;  /* Displacement of the input address, relative to the start of the symbol */
   DWORD dwLineDisplacement = 0;
   IMAGEHLP_LINE64 Line;

   memset(pSymbol, 0, sizeof *pSymbol);
   pSymbol->SizeOfStruct = sizeof buffer;
   pSymbol->MaxNameLen = sizeof buffer - offsetof(SYMBOL_INFO, Name);

   if (!g_bSymInitialized) {
      j_SymSetOptions(/* SYMOPT_UNDNAME | */ SYMOPT_LOAD_LINES);
      if (j_SymInitialize(hProcess, NULL, TRUE)) {
         g_bSymInitialized = TRUE;
      }
   }

   /* Lookup symbol name */
   if (!g_bSymInitialized ||
       !j_SymFromAddr(hProcess, dwAddr, &dwDisplacement, pSymbol)) {
      /*
       * We couldn't obtain symbol information.  At least tell which module the address belongs.
       */

      HMODULE hModule = NULL;

      if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
                             (LPCTSTR)addr,
                             &hModule)) {
         return FALSE;
      }

      if (GetModuleFileNameA(hModule, buffer, sizeof buffer) == sizeof buffer) {
         return FALSE;
      }
      util_snprintf(buf, size, "%p at %s+0x%lx",
                    addr, buffer,
                    (unsigned long)((uintptr_t)addr - (uintptr_t)hModule));

      return TRUE;
   }

   /*
    * Try to get filename and line number.
    */
   memset(&Line, 0, sizeof Line);
   Line.SizeOfStruct = sizeof Line;
   if (!j_SymGetLineFromAddr64(hProcess, dwAddr, &dwLineDisplacement, &Line)) {
      Line.FileName = NULL;
   }

   if (Line.FileName) {
      util_snprintf(buf, size, "%s at %s:%lu", pSymbol->Name, Line.FileName, Line.LineNumber);
   } else {
      util_snprintf(buf, size, "%s", pSymbol->Name);
   }

   return TRUE;
}

#endif /* PIPE_OS_WINDOWS */


#if defined(__GLIBC__) && !defined(__UCLIBC__)

#include <execinfo.h>

/* This can only provide dynamic symbols, or binary offsets into a file.
 *
 * To fix this, post-process the output with tools/addr2line.sh
 */
static INLINE boolean
debug_symbol_name_glibc(const void *addr, char* buf, unsigned size)
{
   char** syms = backtrace_symbols((void**)&addr, 1);
   if (!syms) {
      return FALSE;
   }
   strncpy(buf, syms[0], size);
   buf[size - 1] = 0;
   free(syms);
   return TRUE;
}

#endif /* defined(__GLIBC__) && !defined(__UCLIBC__) */


void
debug_symbol_name(const void *addr, char* buf, unsigned size)
{
#if defined(PIPE_OS_WINDOWS)
   if (debug_symbol_name_dbghelp(addr, buf, size)) {
      return;
   }
#endif

#if defined(__GLIBC__) && !defined(__UCLIBC__)
   if (debug_symbol_name_glibc(addr, buf, size)) {
       return;
   }
#endif

   util_snprintf(buf, size, "%p", addr);
   buf[size - 1] = 0;
}

void
debug_symbol_print(const void *addr)
{
   char buf[1024];
   debug_symbol_name(addr, buf, sizeof(buf));
   debug_printf("\t%s\n", buf);
}

struct util_hash_table* symbols_hash;
pipe_static_mutex(symbols_mutex);

static unsigned hash_ptr(void* p)
{
   return (unsigned)(uintptr_t)p;
}

static int compare_ptr(void* a, void* b)
{
   if(a == b)
      return 0;
   else if(a < b)
      return -1;
   else
      return 1;
}

const char*
debug_symbol_name_cached(const void *addr)
{
   const char* name;
#ifdef PIPE_SUBSYSTEM_WINDOWS_USER
   static boolean first = TRUE;

   if (first) {
      pipe_mutex_init(symbols_mutex);
      first = FALSE;
   }
#endif

   pipe_mutex_lock(symbols_mutex);
   if(!symbols_hash)
      symbols_hash = util_hash_table_create(hash_ptr, compare_ptr);
   name = util_hash_table_get(symbols_hash, (void*)addr);
   if(!name)
   {
      char buf[1024];
      debug_symbol_name(addr, buf, sizeof(buf));
      name = strdup(buf);

      util_hash_table_set(symbols_hash, (void*)addr, (void*)name);
   }
   pipe_mutex_unlock(symbols_mutex);
   return name;
}
