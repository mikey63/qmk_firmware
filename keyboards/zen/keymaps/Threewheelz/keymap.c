#include "zen.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAV 1
#define _NAV2 2


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NAV2,

};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.             .-----------------------------------------.
 * | GESC |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Caps(Ctrl)|A |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Shift(Ent)|
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBTOG| NAV  |Space |Delete||Enter|Space | NAV2 |  ALT |   -  |   =  | Ctrl |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_GESC,         KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                    KC_6,     			 KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                    KC_Y,     			 KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS, \
  LCTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,     KC_G,                    KC_H,     			 KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                    KC_N,     			 KC_M,     KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
  KC_LCTL,         KC_LGUI, KC_LALT, RGB_TOG, MO(_NAV), KC_SPC, KC_DEL,  KC_ENT, LT(_NAV, KC_SPACE), MO(_NAV2), KC_RALT, KC_MINS, KC_EQL,  KC_RCTL \
),

/* NAV
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |             |   6  |   7  |   8  |   9  |  *   |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBSAI|RGBVAI|RGBSAD|      |  [   |             |   ]  |   4  |   5  |   6  |  -   | PGUP |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBHUD|RGBVAD|RGBHUI|      |  (   |             |   )  |   1  |   2  |   3  |  +   | PGDN |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |             | NKRO |   =  |   0  |   .  |  /   | ENT  |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBMOD|      |      |      ||     |      |      |      |VolDn |VolUp | Mute |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_NAV] = KEYMAP( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     	KC_6,              KC_7,     KC_8,    KC_9,    KC_PAST, KC_TRNS, \
  KC_TRNS, RGB_SAI, RGB_VAI, RGB_SAD, KC_TRNS, KC_LBRC,                   	KC_RBRC,           KC_4,     KC_5,    KC_6,    KC_MINS, KC_PGUP, \
  KC_TRNS, RGB_HUD, RGB_VAD, RGB_HUI, KC_TRNS, LSFT(KC_9),                  LSFT(KC_0),        KC_1,     KC_2,    KC_3,    KC_PPLS, KC_PGDN, \
  KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   	MAGIC_TOGGLE_NKRO, KC_EQL,   KC_P0,   KC_TRNS, KC_PSLS, KC_ENT, \
  KC_LCTL, KC_LGUI, KC_LALT, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE \
),

/* NAV2
 * ,-----------------------------------------.             .-----------------------------------------.
 * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBSAI|RGBVAI|RGBSAD| RESET|  [   |             |   ]  | Pgup |  Up  | Pgdn | PSCR | F12  |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |RGBHUD|RGBVAD|RGBHUI|      |  (   |             |   )  | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |             | NKRO |      | Back | Next | Pause|      |
 * |------+------+------+------+------+------+------..-----+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |RGBMOD|      |      |      ||     |      |      |      |VolDn |VolUp | Mute |
 * `------------------------------------------------''-----------------------------------------------'
 */
[_NAV2] = KEYMAP( \
  KC_TILD,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,             KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  KC_TRNS, RGB_SAI, RGB_VAI, RGB_SAD, RESET,   KC_LBRC,                   	 KC_RBRC,           KC_PGUP,  KC_UP,   KC_PGDN, KC_PSCR, KC_F12, \
  KC_TRNS, RGB_HUD, RGB_VAD, RGB_HUI, KC_TRNS, LSFT(KC_9),                   LSFT(KC_0),        KC_LEFT,  KC_DOWN, KC_RGHT, KC_DEL,  KC_END, \
  KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   	 MAGIC_TOGGLE_NKRO, KC_TRNS,  KC_MPRV, KC_MNXT, KC_MPLY, KC_TRNS, \
  KC_LCTL, KC_LGUI, KC_LALT, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE \
),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    //case COLEMAK:
      //if (record->event.pressed) {
        //#ifdef AUDIO_ENABLE
          //PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        //#endif
        //persistant_default_layer_set(1UL<<_COLEMAK);
      //}
      //return false;
      //break;
  }
  return true;
}