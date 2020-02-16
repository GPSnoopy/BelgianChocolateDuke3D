/*
Copyright (C) 1994-1995 Apogee Software, Ltd.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
/**********************************************************************
   module: FX_MAN.H

   author: James R. Dose
   date:   March 17, 1994

   Public header for FX_MAN.C

   (c) Copyright 1994 James R. Dose.  All Rights Reserved.
**********************************************************************/

#ifndef __FX_MAN_H
#define __FX_MAN_H

#include <inttypes.h>

enum FX_ERRORS
   {
   FX_Warning = -2,
   FX_Error = -1,
   FX_Ok = 0,
   FX_SoundCardError,
   FX_InvalidCard,
   FX_MultiVocError,
   FX_DPMI_Error
   };

char *FX_ErrorString( int ErrorNumber );
int   FX_Init( int SoundCard, int numvoices, int numchannels, int samplebits, int mixrate );
int   FX_Shutdown( void );
int   FX_SetCallBack( void ( *function )( int32_t ) );
void  FX_SetVolume( int volume );

void  FX_SetReverseStereo( int setting );
int   FX_GetReverseStereo( void );
void  FX_SetReverb( int reverb );
void  FX_SetReverbDelay( int delay );

int FX_VoiceAvailable( int priority );

int FX_PlayLoopedVOC( uint8_t *ptr, int32_t loopstart, int32_t loopend,
       int32_t pitchoffset, int32_t vol, int32_t left, int32_t right, int32_t priority,
       uint32_t callbackval );
int FX_PlayLoopedWAV( uint8_t *ptr, int32_t loopstart, int32_t loopend,
       int32_t pitchoffset, int32_t vol, int32_t left, int32_t right, int32_t priority,
       uint32_t callbackval );
int FX_PlayVOC3D( uint8_t *ptr, int32_t pitchoffset, int32_t angle, int32_t distance,
       int32_t priority, uint32_t callbackval );
int FX_PlayWAV3D( uint8_t *ptr, int pitchoffset, int angle, int distance,
       int priority, uint32_t callbackval );
int32_t FX_Pan3D( int handle, int angle, int distance );
int32_t FX_StopSound( int handle );
int32_t FX_StopAllSounds( void );

#endif
