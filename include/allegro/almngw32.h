/*         ______   ___    ___ 
 *        /\  _  \ /\_ \  /\_ \ 
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _ __   ___ 
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_ \_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\____\/\____\ \____\ \____ \ \_\\ \____/
 *            \/_/\/_/\/____/\/____/\/____/\/___L\ \/_/ \/___/
 *                                           /\____/
 *                                           \_/__/
 *
 *      Configuration defines for use with Mingw32.
 *
 *      By Michael Rickmann.
 *
 *      Native build version by Henrik Stokseth.
 *
 *      See readme.txt for copyright information.
 */


#ifndef SCAN_DEPEND
   #include <io.h>
   #include <fcntl.h>
   #include <direct.h>
   #include <malloc.h>
#endif


/* describe this platform */
#ifdef ALLEGRO_STATICLINK
   #define ALLEGRO_PLATFORM_STR  "Mingw32.s"
#else
   #define ALLEGRO_PLATFORM_STR  "Mingw32"
#endif

#define ALLEGRO_WINDOWS
#define ALLEGRO_I386
#define ALLEGRO_LITTLE_ENDIAN

#ifdef USE_CONSOLE
   #define ALLEGRO_CONSOLE_OK
#endif


/* describe how function prototypes look to MINGW32 */
#ifdef ALLEGRO_STATICLINK
   #define _AL_DLL
#else
   #ifdef ALLEGRO_SRC
      #define _AL_DLL   __declspec(dllexport)
   #else
      #define _AL_DLL   __declspec(dllimport)
   #endif
#endif

#define AL_VAR(type, name)                   extern _AL_DLL type name
#define AL_ARRAY(type, name)                 extern _AL_DLL type name[]
#define AL_FUNC(type, name, args)            extern type name args
#define AL_METHOD(type, name, args)          type (*name) args
#define AL_FUNCPTR(type, name, args)         extern _AL_DLL type (*name) args


/* windows specific defines */

#if (defined ALLEGRO_SRC)
/* pathches to handle DX7 headers on a win9x system */

/* should WINNT be defined on win9x systems? */
#ifdef WINNT
   #undef WINNT
#endif

/* defined in windef.h */
#ifndef HMONITOR_DECLARED
   #define HMONITOR_DECLARED 1
#endif

/* already defined... */
#ifndef _LPCWAVEFORMATEX_DEFINED
   #define _LPCWAVEFORMATEX_DEFINED
#endif

#endif /* ALLEGRO_SRC */

/* another instance of missing constants in the mingw32 headers */
#ifndef ENUM_CURRENT_SETTINGS
   #define ENUM_CURRENT_SETTINGS       ((DWORD)-1)
#endif

/* describe the asm syntax for this platform */
#define ALLEGRO_ASM_PREFIX    "_"

/* arrange for other headers to be included later on */
#define ALLEGRO_EXTRA_HEADER     "allegro/alwin.h"
#define ALLEGRO_INTERNAL_HEADER  "allegro/aintwin.h"
#define ALLEGRO_MMX_HEADER       "obj/mingw32/mmx.h"


