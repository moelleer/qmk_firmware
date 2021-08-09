#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "keymap_swedish.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  SE_LSPO,
  SE_RSPC,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define QWERTY_COLOR 169, 120, 255
#define CMD_COLOR 12, 225, 241
#define MUSIC_COLOR 32, 255, 234

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_AA,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           SE_OSLH,        SE_ADIA,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_SLSH,        SE_QUES,
    KC_BSPACE,      KC_LCTRL,       KC_LALT,        KC_LGUI,        MO(2),          KC_SPACE,       KC_NO,          KC_ENTER,       KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    SE_GRV,         KC_EXLM,        SE_AT,          SE_LCBR_MAC,    SE_RCBR_MAC,    SE_AMPR,        SE_ASTR,        KC_7,           KC_8,           KC_9,           SE_PLUS,        SE_EQL,
    SE_TILD,        SE_CIRC,        SE_DLR,         SE_LPRN,        SE_RPRN,        SE_COLN,        SE_SCLN,        KC_4,           KC_5,           KC_6,           SE_MINS,        SE_UNDS,
    SE_PIPE_MAC,    KC_HASH,        KC_PERC,        SE_LBRC,        SE_RBRC,        SE_QUOT,        SE_DQUO,        KC_1,           KC_2,           KC_3,           SE_BSLS_MAC,    SE_QUES,
    KC_BSPACE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_ENTER,       KC_0,           KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_DELETE,      KC_TRANSPARENT, AU_ON,          AU_OFF,         AU_TOG,         KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,RGB_TOG,        RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        {CMD_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR},
        {CMD_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR},
        {CMD_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},
        {CMD_COLOR}, {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},                    {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},    {CMD_COLOR},
    },


    [2] = {
        {CMD_COLOR},    {CMD_COLOR}, {CMD_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {CMD_COLOR}, {CMD_COLOR},    {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {CMD_COLOR}, {CMD_COLOR},
        {CMD_COLOR},    {CMD_COLOR}, {CMD_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {CMD_COLOR}, {CMD_COLOR},    {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {CMD_COLOR}, {CMD_COLOR},
        {CMD_COLOR},    {CMD_COLOR}, {CMD_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {CMD_COLOR}, {CMD_COLOR},    {QWERTY_COLOR}, {QWERTY_COLOR}, {QWERTY_COLOR}, {CMD_COLOR}, {CMD_COLOR},
        {QWERTY_COLOR}, {0,0,0},     {0,0,0},     {0,0,0},        {0,0,0},        {0,0,0},     {QWERTY_COLOR}, {MUSIC_COLOR},  {MUSIC_COLOR},  {MUSIC_COLOR},  {MUSIC_COLOR}
    },

    [3] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {105,255,255}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {105,255,255}, {105,255,255}, {31,255,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {154,255,255}, {154,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,183,238}, {15,166,195}, {15,166,195}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    static bool shift_registered;

    switch (keycode) {
        case KC_COMMA: {
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    register_code(KC_GRV);
                    register_code(KC_LSHIFT);
                    shift_registered = true;
                    return false;
                }
            } else {
                if (shift_registered) {
                    unregister_code(KC_GRV);
                    shift_registered = false;
                    return false;
                }
            }
        }
        case KC_DOT: {
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(KC_GRV);
                    shift_registered = true;
                    return false;
                }
            } else {
                if (shift_registered) {
                    unregister_code(KC_GRV);
                    shift_registered = false;
                    return false;
                }
            }
        }
        case SE_SLSH: {
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    register_code(KC_MINS);
                    shift_registered = true;
                    return false;
                }
            } else {
                if (shift_registered) {
                    unregister_code(KC_MINS);
                    shift_registered = false;
                    return false;
                }
            }
        }
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
