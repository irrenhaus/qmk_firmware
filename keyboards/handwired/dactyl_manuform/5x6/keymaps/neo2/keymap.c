/* A NEO2 layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

#include "keymap_german.h"

extern keymap_config_t keymap_config;

#define _QWERTZ 0
#define _MOD3   1

#define MOD3  MO(_MOD3)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define DE_EURO RALT(KC_E)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTZ] = LAYOUT_5x6(
     KC_ESC , DE_1  , DE_2  , DE_3  , DE_4  , DE_5  ,                         DE_6  , DE_7  , DE_8  , DE_9  , DE_0  ,DE_MINS,
     KC_TAB , DE_X  , DE_V  , DE_L  , DE_C  , DE_W  ,                         DE_K  , DE_H  , DE_G  , DE_F  , DE_Q  ,DE_SS,
     XXXXXXX, DE_U  , DE_I  , DE_A  , DE_E  , DE_O  ,                         DE_S  , DE_N  , DE_R  , DE_T  , DE_D  ,DE_Y,
     XXXXXXX, DE_UE , DE_OE , DE_AE , DE_P  , DE_Z  ,                         DE_B  , DE_M  ,DE_COMM,DE_DOT , DE_J  ,DE_PLUS
                     DE_LEFT,DE_RGHT,                                                        DE_UP  ,DE_DOWN,
                                     KC_LSFT, KC_SPC,                         KC_ENT,KC_BSPC,
                                     MOD3   ,KC_LGUI,                        KC_RGUI, MOD3  ,
                                     KC_LCTL,KC_LALT,                        KC_RALT,KC_RCTL
  ),

  [_MOD3] = LAYOUT_5x6(
     KC_F1  , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,                        KC_F7  , KC_F8 , KC_F9 , KC_F10,KC_F11 ,KC_F12 ,
     _______,_______,DE_UNDS,DE_LBRC,DE_RBRC,DE_CIRC,                        DE_EXLM,DE_LESS,DE_MORE, DE_EQL,DE_AMPR,DE_EURO,
     _______,DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR,                        DE_QST ,DE_LPRN,DE_RPRN,DE_MINS,DE_COLN,  DE_AT,
     _______,DE_HASH, DE_DLR,DE_PIPE,DE_TILD,DE_ACUT,                        DE_PLUS,DE_PERC,DE_DQOT,DE_QUOT,DE_SCLN,DE_PLUS,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                     _______,_______,                        _______,_______,
                                       RESET, DEBUG ,                         DEBUG ,RESET
  ),
};


