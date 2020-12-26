#pragma once

#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// Wrapper for _______________XXXXXXXX_______________ in LAYOUT
#define LAYOUT_WRAPPER(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_BASTYL_WRAPPER(...) LAYOUT_new(__VA_ARGS__)

// Homerow modifiers
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)

#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I LALT_T(KC_I)

#define HM_X RALT_T(KC_X)



#define _______________COLEMAK_DH_L1_______________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _______________COLEMAK_DH_L2_______________        KC_A,    HM_R,    HM_S,    HM_T,    KC_G
#define _______________COLEMAK_DH_L3_______________        KC_Z,    HM_X,    KC_C,    KC_D,    KC_V

#define _______________COLEMAK_DH_R1_______________        KC_K,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _______________COLEMAK_DH_R2_______________        KC_M,    HM_N,    HM_E,    HM_I,    KC_O
#define _______________COLEMAK_DH_R3_______________        KC_J,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH



#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH



#define _________________LOWER_L1__________________        ________________NUMBER_LEFT________________
#define _________________LOWER_L2__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L3__________________        KC_EXLM, _______, _______, _______, KC_GRV

#define _________________LOWER_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________LOWER_R2__________________        KC_CIRC, KC_AMPR, KC_ASTR, _______, _______
#define _________________LOWER_R3__________________        KC_PSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT



#define _________________RAISE_L1__________________        _________________FUNC_LEFT_________________
#define _________________RAISE_L2__________________        _______, _______, _______, _______, _______
#define _________________RAISE_L3__________________        _______, _______, _______, _______, KC_TILD

#define _________________RAISE_R1__________________        _________________FUNC_RIGHT________________
#define _________________RAISE_R2__________________        KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END
#define _________________RAISE_R3__________________        KC_VOLD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT



#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
