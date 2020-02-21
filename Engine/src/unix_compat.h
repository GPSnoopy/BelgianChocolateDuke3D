//
//  unix_compat.h
//  Duke3D
//
//  Based on macos_compat.h
//  Copyright Wed, Jul 31, 2013, Juan Manuel Borges Caño (GPLv3+)
//

#ifndef Duke3D_unix_compat_h
#define Duke3D_unix_compat_h

//#define BYTE_ORDER LITTLE_ENDIAN

#include <stdlib.h>

#ifndef max
#define max(x, y)  (((x) > (y)) ? (x) : (y))
#endif

#ifndef min
#define min(x, y)  (((x) < (y)) ? (x) : (y))
#endif

#include <inttypes.h>

#define O_BINARY 0


/*
#define SOL_IP SOL_SOCKET
#define IP_RECVERR  SO_BROADCAST
*/

#define stricmp strcasecmp
#define strcmpi strcasecmp

#define S_IREAD S_IRUSR
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#endif
