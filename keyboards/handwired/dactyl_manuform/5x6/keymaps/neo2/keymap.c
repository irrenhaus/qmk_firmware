/* A NEO1 layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

#include "keymap_german.h"

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

#define ALT_TAB LALT(KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_NEO1] = LAYOUT_5x6(
     KC_ESC , DE_1  , DE_2  , DE_3  , DE_4  , DE_5  ,                         DE_6  , DE_7  , DE_8  , DE_9  , DE_0  ,DE_MINS,
     XXXXXXX, DE_X  , DE_V  , DE_L  , DE_C  , DE_W  ,                         DE_K  , DE_H  , DE_G  , DE_F  , DE_Q  ,DE_SS,
     XXXXXXX, DE_U  , DE_I  , DE_A  , DE_E  , DE_O  ,                         DE_S  , DE_N  , DE_R  , DE_T  , DE_D  ,DE_Y,
      KC_TAB, DE_UE , DE_OE , DE_AE , DE_P  , DE_Z  ,                         DE_B  , DE_M  ,DE_COMM,DE_DOT , DE_J  ,DE_PLUS,
                     _______,_______,                                                        _______,_______,
                                     KC_SPC, KC_LSFT,                        KC_RSFT, KC_ENT,
                                      NEO3 ,  NEO4  ,                          NEO4 ,  NEO3 ,
                                     KC_LCTL,KC_LGUI,                         KC_DEL,KC_RCTL
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
     _______,KC_PGUP,KC_BSPC, KC_UP , KC_DEL,KC_PGND,                        _______, KC_P7 , KC_P8 , KC_P9 ,_______,_______,
     ALT_TAB,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END,                        _______, KC_P4 , KC_P5 , KC_P6 ,_______,_______,
     _______,KC_ESC ,KC_TAB ,KC_PSTE,KC_ENTR,KC_UNDO,                        _______, KC_P1 , KC_P2 , KC_P3 ,_______,_______,
                                     _______,_______,                        _______, KC_P0 ,
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
                                     KC_SPC , KC_LSFT,                        KC_BSPC, KC_ENT,
                                     QWERTZ1,KC_LALT,                        DE_ALGR, NEO3  ,
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


