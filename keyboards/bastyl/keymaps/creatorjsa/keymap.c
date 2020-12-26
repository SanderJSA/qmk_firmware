#include QMK_KEYBOARD_H
#include "creatorjsa.h"

#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

#define SWAP_DL TG(_QWERTY)

enum {
    TD_LPRN,
    TD_RPRN,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LBRC),
    [TD_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_BASTYL_WRAPPER( \
    XXXXXXX        , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX            ,            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX ,
    KC_BSLS        , _______________COLEMAK_DH_L1_______________            ,            _______________COLEMAK_DH_R1_______________ , KC_DEL  ,
    LGUI_T(KC_TAB) , _______________COLEMAK_DH_L2_______________            ,            _______________COLEMAK_DH_R2_______________ , KC_QUOT ,
    KC_MINS        , _______________COLEMAK_DH_L3_______________            ,            _______________COLEMAK_DH_R3_______________ , KC_EQL  ,
                                TD(TD_LPRN) , LT(_LOWER, KC_ESC) , KC_SPC   ,  KC_BSPC , LT(_RAISE, KC_ENT) , TD(TD_RPRN) ,
                                                         XXXXXXX , XXXXXXX  ,  XXXXXXX , XXXXXXX
  ),

  [_QWERTY] = LAYOUT_BASTYL_WRAPPER( \
    XXXXXXX        , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX            ,            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX ,
    KC_ESC         , _________________QWERTY_L1_________________            ,            _________________QWERTY_R1_________________ , KC_RBRC ,
    LGUI_T(KC_TAB) , _________________QWERTY_L2_________________            ,            _________________QWERTY_R2_________________ , KC_QUOT ,
    KC_LSHIFT      , _________________QWERTY_L3_________________            ,            _________________QWERTY_R3_________________ , KC_EQL  ,
                                    KC_LCPO , LT(_LOWER, KC_ESC) , KC_SPC   ,  KC_BSPC , LT(_RAISE, KC_ENT) , KC_LAPO ,
                                                         XXXXXXX , XXXXXXX  ,  XXXXXXX , XXXXXXX
  ),

  [_LOWER] = LAYOUT_BASTYL_WRAPPER( \
    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX            ,            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX ,
    _______ , _________________LOWER_L1__________________            ,            _________________LOWER_R1__________________ , _______ ,
    _______ , _________________LOWER_L2__________________            ,            _________________LOWER_R2__________________ , _______ ,
    _______ , _________________LOWER_L3__________________            ,            _________________LOWER_R3__________________ , _______ ,
                                        _______ , _______ , _______  ,  _______ , SWAP_DL , _______ ,
                                                  _______ , _______  ,  _______ , _______
  ),

  [_RAISE] = LAYOUT_BASTYL_WRAPPER( \
    RESET   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX            ,            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX , XXXXXXX ,
    _______ , _________________RAISE_L1__________________            ,            _________________RAISE_R1__________________ , _______ ,
    _______ , _________________RAISE_L2__________________            ,            _________________RAISE_R2__________________ , _______ ,
    _______ , _________________RAISE_L3__________________            ,            _________________RAISE_R3__________________ , _______ ,
                                        _______ , SWAP_DL , _______  ,  _______ , _______ , _______ ,
                                                  _______ , _______  ,  _______ , _______
  ),
};
