/*
 *			GPAC - Multimedia Framework C SDK
 *
 *			Authors: Jean Le Feuvre
 *			Copyright (c) Telecom ParisTech 2000-2012
 *					All rights reserved
 *
 *  This file is part of GPAC / modules interfaces
 *
 *  GPAC is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  GPAC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef _GF_MODULE_DROIDAUDIO_H_
#define _GF_MODULE_DROIDAUDIO_H_

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    GF_DROIDAUDIO_ENTERING_CRITICAL,
    GF_DROIDAUDIO_EXITING_CRITICAL,
} GF_DroidAudio_Event;

void gf_droidaudio_register_java_vm(JavaVM *vm);
typedef void (*GF_DroidAudio_EventCallback)(void *, GF_DroidAudio_Event);
void gf_droidaudio_register_event_handler(GF_DroidAudio_EventCallback, void *);

#ifdef __cplusplus
}
#endif


#endif	/*_GF_MODULE_DROIDAUDIO_H_*/
