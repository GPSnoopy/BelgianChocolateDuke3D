//
//  network.c
//  Duke3D
//
//  Created by fabien sanglard on 12-12-22.
//  Copyright (c) 2012 fabien sanglard. All rights reserved.
//

#include "network.h"
#include "mmulti_unstable.h"

void callcommit(void)
{
    unstable_callcommit();
}

void initcrc(void)
{
	unstable_initcrc();
}

int32_t getcrc(uint8_t  *buffer, short bufleng)
{
	return unstable_getcrc(buffer, bufleng);
}

void initmultiplayers(uint8_t  damultioption, uint8_t  dacomrateoption, uint8_t  dapriority)
{
	unstable_initmultiplayers(damultioption, dacomrateoption, dapriority);
}

void sendpacket(int32_t other, uint8_t  *bufptr, int32_t messleng)
{
	unstable_sendpacket(other, bufptr, messleng);
}

void setpackettimeout(int32_t datimeoutcount, int32_t daresendagaincount)
{
	unstable_setpackettimeout(datimeoutcount, daresendagaincount);
}

void uninitmultiplayers(void)
{
	unstable_uninitmultiplayers();
}

void sendlogon(void)
{
	unstable_sendlogon();
}

void sendlogoff(void)
{
	unstable_sendlogoff();
}

int  getoutputcirclesize(void)
{
	return unstable_getoutputcirclesize();
}

void setsocket(short newsocket)
{
	unstable_setsocket(newsocket);
}

short getpacket(short *other, uint8_t  *bufptr)
{
	return unstable_getpacket(other, bufptr);
}

void flushpackets(void)
{
	unstable_flushpackets();
}

void genericmultifunction(int32_t other, char  *bufptr, int32_t messleng, int32_t command)
{
	unstable_genericmultifunction(other, bufptr, messleng, command);
}