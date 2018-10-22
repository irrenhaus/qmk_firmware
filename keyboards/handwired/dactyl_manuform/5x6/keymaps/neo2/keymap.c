/* A NEO1 layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

#include "keymap_german.h"
#include "rgblight.h"

extern keymap_config_t keymap_config;

#define _NEO1    0
#define _NEO3    1
#define _NEO4    2

#define NEO1     DF(_NEO1)
#define NEO3     MO(_NEO3)
#define NEO4     MO(_NEO4)

#define _QWERTZ0 16
#define _QWERTZ1 17

#define QWERTZ   DF(_QWERTZ0)
#define QWERTZ1  MO(_QWERTZ1)

#define _______  KC_TRNS
#define XXXXXXX  KC_NO

#define LCTLALT TD(TD_LCTLALT)
#define RCTLALT TD(TD_RCTLALT)

//Tap Dance Declarations
enum {
    TD_LCTLALT = 0,
    TD_RCTLALT
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for LCTL, twice for LALT
  [TD_LCTLALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LALT),
  //Tap once for RCTL, twice for RALT
  [TD_RCTLALT] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_RALT)
};

void matrix_init_user() {
	rgblight_enable();
    rgblight_setrgb(0xFF, 0xFF, 0xFF);
}


void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  if (old_layer != new_layer) {
    switch (new_layer) {
      case _NEO1:
        rgblight_setrgb(0xFF, 0xFF, 0xFF);
        break;
      case _NEO3:
        rgblight_setrgb(0xFF, 0xA0, 0xFF);
        break;
      case _NEO4:
        rgblight_setrgb(0xA0, 0xFF, 0xFF);
        break;
      case _QWERTZ0:
        rgblight_setrgb(0xFF, 0x00, 0x00);
        break;
      case _QWERTZ1:
        rgblight_setrgb(0xFF, 0x00, 0xFF);
        break;
    }

    old_layer = new_layer;
  }

  #endif //RGBLIGHT_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_NEO1] = LAYOUT_5x6(
     KC_ESC , DE_1  , DE_2  , DE_3  , DE_4  , DE_5  ,                         DE_6  , DE_7  , DE_8  , DE_9  , DE_0  ,DE_MINS,
     XXXXXXX, DE_X  , DE_V  , DE_L  , DE_C  , DE_W  ,                         DE_K  , DE_H  , DE_G  , DE_F  , DE_Q  ,DE_SS,
     XXXXXXX, DE_U  , DE_I  , DE_A  , DE_E  , DE_O  ,                         DE_S  , DE_N  , DE_R  , DE_T  , DE_D  ,DE_Y,
      KC_TAB, DE_UE , DE_OE , DE_AE , DE_P  , DE_Z  ,                         DE_B  , DE_M  ,DE_COMM,DE_DOT , DE_J  ,DE_PLUS,
                     _______,_______,                                                        _______,_______,
                                       NEO3 , KC_SPC,                         KC_ENT,  NEO4 ,
                                     KC_LSFT,  NEO4  ,                          NEO3,KC_RSFT,
                                     LCTLALT,KC_LGUI,                         KC_DEL,RCTLALT
  ),

  [_NEO3] = LAYOUT_5x6(
     KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                        KC_F7  , KC_F8 , KC_F9 , KC_F10,KC_F11 ,KC_F12 ,
     _______,_______,DE_UNDS,DE_LBRC,DE_RBRC,DE_CIRC,                        DE_EXLM,DE_LESS,DE_MORE, DE_EQL,DE_AMPR,DE_EURO,
     _______,DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR,                        DE_QST ,DE_LPRN,DE_RPRN,DE_MINS,DE_COLN,  DE_AT,
     _______,DE_HASH, DE_DLR,DE_PIPE,DE_TILD,DE_ACUT,                        DE_PLUS,DE_PERC,DE_DQOT,DE_QUOT,DE_SCLN,DE_PLUS,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______
  ),

  [_NEO4] = LAYOUT_5x6(
     QWERTZ ,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     RGB_M_T,KC_PGUP,KC_BSPC, KC_UP , KC_DEL,KC_PGDN,                        _______,  KC_7 ,  KC_8 ,  KC_9 ,_______,RGB_HUI,
     _______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END,                        _______,  KC_4 ,  KC_5 ,  KC_6 ,_______,_______,
     RGB_TOG,KC_ESC ,KC_TAB ,KC_PSTE, KC_ENT,KC_UNDO,                        _______,  KC_1 ,  KC_2 ,  KC_3 ,_______,RGB_TOG,
                                     _______,_______,                          KC_0 ,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                       RESET, DEBUG ,                         DEBUG ,RESET
  ),

  // QWERTZ based layout from here on

  [_QWERTZ0] = LAYOUT_5x6(
     KC_ESC , DE_1  , DE_2  , DE_3  , DE_4  , DE_5  ,                         DE_6  , DE_7  , DE_8  , DE_9  , DE_0  ,DE_MINS,
     XXXXXXX, DE_Q  , DE_W  , DE_E  , DE_R  , DE_T  ,                         DE_Z  , DE_U  , DE_I  , DE_O  , DE_P  ,DE_UE  ,
     XXXXXXX, DE_A  , DE_S  , DE_D  , DE_F  , DE_G  ,                         DE_H  , DE_J  , DE_K  , DE_L  , DE_OE ,DE_AE  ,
      KC_TAB, DE_Y  , DE_X  , DE_C  , DE_V  , DE_B  ,                         DE_N  , DE_M  ,DE_COMM,DE_DOT ,DE_MINS,DE_PLUS,
                     _______,_______,                                                        _______,_______,
                                     QWERTZ1, KC_SPC,                         KC_ENT,QWERTZ1,
                                     KC_LSFT,QWERTZ1,                        QWERTZ1,KC_RSFT,
                                     KC_LCTL,KC_LGUI,                         KC_DEL,KC_RCTL
  ),

  [_QWERTZ1] = LAYOUT_5x6(
       NEO1 ,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                       RESET, DEBUG ,                         DEBUG ,RESET
  ),
};


