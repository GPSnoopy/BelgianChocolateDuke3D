/*
 * win32 compatibility header. Takes care of some legacy code issues
 *  and incompatibilities at the source level.
 *
 *  Written by Ryan C. Gordon (icculus@clutteredmind.org)
 *
 * Please do NOT harrass Ken Silverman about any code modifications
 *  (including this file) to BUILD.
 */

/*
 * "Build Engine & Tools" Copyright (c) 1993-1997 Ken Silverman
 * Ken Silverman's official web site: "http://www.advsys.net/ken"
 * See the included license file "BUILDLIC.TXT" for license info.
 * This file IS NOT A PART OF Ken Silverman's original release
 */
  
#ifndef _INCLUDE_WIN32_COMPAT_H_
#define _INCLUDE_WIN32_COMPAT_H_

#include <stdio.h>

#if (!defined _MSC_VER)
	#include <unistd.h>
#else
	#include <fcntl.h>
    #include <sys/stat.h>
#endif

#include <stdlib.h>
#include <io.h>
#include <direct.h>
#include <conio.h>
#include <dos.h>
#include <assert.h>
#include <string.h>

#ifdef FP_OFF
#undef FP_OFF
#endif

// Horrible horrible macro: Watcom allowed memory pointer to be cast
// to a 32bits integer. The code is unfortunately stuffed with this :( !
#define FP_OFF(x) ((int32_t) (x))

#ifndef max
#define max(x, y)  (((x) > (y)) ? (x) : (y))
#endif

#ifndef min
#define min(x, y)  (((x) < (y)) ? (x) : (y))
#endif

#if (defined _MSC_VER)

#define open _open
#define O_BINARY _O_BINARY
#define O_RDONLY _O_RDONLY
#define O_WRONLY _O_WRONLY
#define O_RDWR _O_RDWR
#define O_TRUNC _O_TRUNC
#define O_CREAT _O_CREAT
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE
#define S_IRDWR _S_IRDWR
#endif /* defined _MSC_VER */

#define snprintf _snprintf
#define strncasecmp strnicmp

#include <inttypes.h>

#endif

/* end of win32_compat.h ... */
