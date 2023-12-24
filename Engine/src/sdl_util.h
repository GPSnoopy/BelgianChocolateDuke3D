
/* Consolidate SDL routine utilities that  don't add much value to understanding the code */

/*
 * "Build Engine & Tools" Copyright (c) 1993-1997 Ken Silverman
 * Ken Silverman's official web site: "http://www.advsys.net/ken"
 * See the included license file "BUILDLIC.TXT" for license info.
 * This file IS NOT A PART OF Ken Silverman's original release
 */

#pragma once

#include <assert.h>
#include <SDL2/SDL.h>
#include "build.h"

// This will output the proper SDL error strings in the event that a SDL call returns an error
#define SDL_CHECK_SUCCESS(val) __checkSdlSuccess ( (val), #val, __FILE__, __LINE__ )
#define SDL_CHECK_NOT_NULL(val, message) __checkSdlNotNull ( (val), (message), __FILE__, __LINE__ )


inline static void __checkSdlSuccess(int result, char const* func, const char* file, int line)
{
	if (result != 0)
	{
		Error(EXIT_FAILURE,
			"SDL: %s failed!\n"
			"SDL: SDL_Error: %s.\n"
			"SDL: FILE: %s\n"
			"SDL: LINE: %d",
			func,
			SDL_GetError(),
			file,
			line);
	}
}

inline static void __checkSdlNotNull(void* handle, char const* msg, const char* file, int line)
{
	if (handle == NULL)
	{
		Error(EXIT_FAILURE,
			"SDL: Failed to %s!\n"
			"SDL: SDL_Error: %s.\n"
			"SDL: FILE: %s\n"
			"SDL: LINE: %d",
			msg,
			SDL_GetError(),
			file,
			line);
	}
}

inline static void set_sdl_scancodes(uint32_t scancodes[], size_t size)
{
    assert(size == SDL_NUM_SCANCODES);
	
    memset(scancodes, '\0', sizeof(uint32_t) * size);
	
    scancodes[SDL_SCANCODE_ESCAPE] = 0x01;
    scancodes[SDL_SCANCODE_1] = 0x02;
    scancodes[SDL_SCANCODE_2] = 0x03;
    scancodes[SDL_SCANCODE_3] = 0x04;
    scancodes[SDL_SCANCODE_4] = 0x05;
    scancodes[SDL_SCANCODE_5] = 0x06;
    scancodes[SDL_SCANCODE_6] = 0x07;
    scancodes[SDL_SCANCODE_7] = 0x08;
    scancodes[SDL_SCANCODE_8] = 0x09;
    scancodes[SDL_SCANCODE_9] = 0x0A;
    scancodes[SDL_SCANCODE_0] = 0x0B;
    scancodes[SDL_SCANCODE_MINUS] = 0x0C; /* was 0x4A */
    scancodes[SDL_SCANCODE_EQUALS] = 0x0D; /* was 0x4E */
    scancodes[SDL_SCANCODE_BACKSPACE] = 0x0E;
    scancodes[SDL_SCANCODE_TAB] = 0x0F;
    scancodes[SDL_SCANCODE_Q] = 0x10;
    scancodes[SDL_SCANCODE_W] = 0x11;
    scancodes[SDL_SCANCODE_E] = 0x12;
    scancodes[SDL_SCANCODE_R] = 0x13;
    scancodes[SDL_SCANCODE_T] = 0x14;
    scancodes[SDL_SCANCODE_Y] = 0x15;
    scancodes[SDL_SCANCODE_U] = 0x16;
    scancodes[SDL_SCANCODE_I] = 0x17;
    scancodes[SDL_SCANCODE_O] = 0x18;
    scancodes[SDL_SCANCODE_P] = 0x19;
    scancodes[SDL_SCANCODE_LEFTBRACKET] = 0x1A;
    scancodes[SDL_SCANCODE_RIGHTBRACKET] = 0x1B;
    scancodes[SDL_SCANCODE_RETURN] = 0x1C;
    scancodes[SDL_SCANCODE_LCTRL] = 0x1D;
    scancodes[SDL_SCANCODE_A] = 0x1E;
    scancodes[SDL_SCANCODE_S] = 0x1F;
    scancodes[SDL_SCANCODE_D] = 0x20;
    scancodes[SDL_SCANCODE_F] = 0x21;
    scancodes[SDL_SCANCODE_G] = 0x22;
    scancodes[SDL_SCANCODE_H] = 0x23;
    scancodes[SDL_SCANCODE_J] = 0x24;
    scancodes[SDL_SCANCODE_K] = 0x25;
    scancodes[SDL_SCANCODE_L] = 0x26;
    scancodes[SDL_SCANCODE_SEMICOLON] = 0x27;
    scancodes[SDL_SCANCODE_APOSTROPHE] = 0x28;
    scancodes[SDL_SCANCODE_GRAVE] = 0x29;
    scancodes[SDL_SCANCODE_LSHIFT] = 0x2A;
    scancodes[SDL_SCANCODE_BACKSLASH] = 0x2B;
    scancodes[SDL_SCANCODE_Z] = 0x2C;
    scancodes[SDL_SCANCODE_X] = 0x2D;
    scancodes[SDL_SCANCODE_C] = 0x2E;
    scancodes[SDL_SCANCODE_V] = 0x2F;
    scancodes[SDL_SCANCODE_B] = 0x30;
    scancodes[SDL_SCANCODE_N] = 0x31;
    scancodes[SDL_SCANCODE_M] = 0x32;
    scancodes[SDL_SCANCODE_COMMA] = 0x33;
    scancodes[SDL_SCANCODE_PERIOD] = 0x34;
    scancodes[SDL_SCANCODE_SLASH] = 0x35;
    scancodes[SDL_SCANCODE_RSHIFT] = 0x36;
    scancodes[SDL_SCANCODE_KP_MULTIPLY] = 0x37;
    scancodes[SDL_SCANCODE_LALT] = 0x38;
    scancodes[SDL_SCANCODE_SPACE] = 0x39;
    scancodes[SDL_SCANCODE_CAPSLOCK] = 0x3A;
    scancodes[SDL_SCANCODE_F1] = 0x3B;
    scancodes[SDL_SCANCODE_F2] = 0x3C;
    scancodes[SDL_SCANCODE_F3] = 0x3D;
    scancodes[SDL_SCANCODE_F4] = 0x3E;
    scancodes[SDL_SCANCODE_F5] = 0x3F;
    scancodes[SDL_SCANCODE_F6] = 0x40;
    scancodes[SDL_SCANCODE_F7] = 0x41;
    scancodes[SDL_SCANCODE_F8] = 0x42;
    scancodes[SDL_SCANCODE_F9] = 0x43;
    scancodes[SDL_SCANCODE_F10] = 0x44;
    scancodes[SDL_SCANCODE_NUMLOCKCLEAR] = 0x45;
    scancodes[SDL_SCANCODE_SCROLLLOCK] = 0x46;
    scancodes[SDL_SCANCODE_KP_7] = 0x47;
    scancodes[SDL_SCANCODE_KP_8] = 0x48;
    scancodes[SDL_SCANCODE_KP_9] = 0x49;
    scancodes[SDL_SCANCODE_KP_MINUS] = 0x4A;
    scancodes[SDL_SCANCODE_KP_4] = 0x4B;
    scancodes[SDL_SCANCODE_KP_5] = 0x4C;
    scancodes[SDL_SCANCODE_KP_6] = 0x4D;
    scancodes[SDL_SCANCODE_KP_PLUS] = 0x4E;
    scancodes[SDL_SCANCODE_KP_1] = 0x4F;
    scancodes[SDL_SCANCODE_KP_2] = 0x50;
    scancodes[SDL_SCANCODE_KP_3] = 0x51;
    scancodes[SDL_SCANCODE_KP_0] = 0x52;
    scancodes[SDL_SCANCODE_KP_PERIOD] = 0x53;
    scancodes[SDL_SCANCODE_F11] = 0x57;
    scancodes[SDL_SCANCODE_F12] = 0x58;
    scancodes[SDL_SCANCODE_PAUSE] = 0x59; /* SBF - technically incorrect */

    scancodes[SDL_SCANCODE_KP_ENTER] = 0xE01C;
    scancodes[SDL_SCANCODE_RCTRL] = 0xE01D;
    scancodes[SDL_SCANCODE_KP_DIVIDE] = 0xE035;
    scancodes[SDL_SCANCODE_PRINTSCREEN] = 0xE037; /* SBF - technically incorrect */
    scancodes[SDL_SCANCODE_SYSREQ] = 0xE037; /* SBF - for windows... */
    scancodes[SDL_SCANCODE_RALT] = 0xE038;
    scancodes[SDL_SCANCODE_HOME] = 0xE047;
    scancodes[SDL_SCANCODE_UP] = 0xE048;
    scancodes[SDL_SCANCODE_PAGEUP] = 0xE049;
    scancodes[SDL_SCANCODE_LEFT] = 0xE04B;
    scancodes[SDL_SCANCODE_RIGHT] = 0xE04D;
    scancodes[SDL_SCANCODE_END] = 0xE04F;
    scancodes[SDL_SCANCODE_DOWN] = 0xE050;
    scancodes[SDL_SCANCODE_PAGEDOWN] = 0xE051;
    scancodes[SDL_SCANCODE_INSERT] = 0xE052;
    scancodes[SDL_SCANCODE_DELETE] = 0xE053;
}
