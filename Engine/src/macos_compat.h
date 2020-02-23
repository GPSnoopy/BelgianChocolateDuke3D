//
//  macos_compat.h
//  Duke3D
//
//  Created by fabien sanglard on 12-12-12.
//  Copyright (c) 2012 fabien sanglard. All rights reserved.
//

#ifndef Duke3D_macos_compat_h
#define Duke3D_macos_compat_h

#include <stdlib.h>

#ifndef max
#define max(x, y)  (((x) > (y)) ? (x) : (y))
#endif

#ifndef min
#define min(x, y)  (((x) < (y)) ? (x) : (y))
#endif

#include <inttypes.h>

#define O_BINARY 0
#define PLATFORM_MACOSX 1
//
//#define SOL_IP SOL_SOCKET
//#define IP_RECVERR  SO_BROADCAST

#define stricmp strcasecmp
#define strcmpi strcasecmp

#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#endif
