#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
/* #define TAPPING_TERM 100 */

#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"yMmXn/JmND9"
#define RGB_MATRIX_STARTUP_SPD 60
