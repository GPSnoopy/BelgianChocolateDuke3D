#ifndef _MMULTI_UNSTABLE_H_
#define _MMULTI_UNSTABLE_H_

#include <stdint.h>

void initmultiplayers();
void sendpacket(int32_t other, const uint8_t* bufptr, int32_t messleng);
void setpackettimeout(int32_t datimeoutcount, int32_t daresendagaincount);
void uninitmultiplayers(void);
void sendlogon(void);
void sendlogoff(void);
int32_t  getoutputcirclesize(void);
short getpacket(short* other, uint8_t* bufptr);
void flushpackets(void);
void genericmultifunction(int32_t other, const uint8_t* bufptr, int32_t messleng, int32_t command);

#endif