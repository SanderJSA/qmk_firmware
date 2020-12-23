#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _QWERTY 1
#define _RAISE 2

#define SWAP_DL TG(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_new( \
   KC_LBRC        , KC_1 , KC_2 , KC_3    , KC_4       , KC_5       ,       KC_6 ,       KC_7 ,     KC_8 ,   KC_9 ,    KC_0 , KC_RBRC ,\
   KC_ESC         , KC_Q , KC_W , KC_F    , KC_P       , KC_B       ,       KC_K ,       KC_L ,     KC_U ,   KC_Y , KC_SCLN , KC_BSLS ,\
   LGUI_T(KC_TAB) , KC_A , KC_R , KC_S    , KC_T       , KC_G       ,       KC_M ,       KC_N ,     KC_E ,   KC_I ,    KC_O , KC_QUOT ,\
   KC_MINUS       , KC_Z , KC_X , KC_C    , KC_D       , KC_V       ,       KC_J ,       KC_H ,  KC_COMM , KC_DOT , KC_SLSH ,  KC_EQL ,\
                                  KC_LCTL , MO(_RAISE) , KC_LSHIFT  ,  KC_RSHIFT , MO(_RAISE) ,  KC_LALT ,\
                                            KC_DEL     , KC_SPC     ,    KC_BSPC ,     KC_ENT
  ),

  [_QWERTY] = LAYOUT_new( \
   KC_LBRC        , KC_1 , KC_2 , KC_3    , KC_4       , KC_5       ,       KC_6 ,       KC_7 ,     KC_8 ,   KC_9 ,    KC_0 , KC_RBRC ,\
   KC_ESC         , KC_Q , KC_W , KC_E    , KC_R       , KC_T       ,       KC_Y ,       KC_U ,     KC_I ,   KC_O ,    KC_P , KC_BSLS ,\
   LGUI_T(KC_TAB) , KC_A , KC_S , KC_D    , KC_F       , KC_G       ,       KC_H ,       KC_J ,     KC_K ,   KC_L , KC_SCLN , KC_QUOT ,\
   KC_MINUS       , KC_Z , KC_X , KC_C    , KC_V       , KC_B       ,       KC_N ,       KC_M ,  KC_COMM , KC_DOT , KC_SLSH ,  KC_EQL ,\
                                  KC_LCTL , MO(_RAISE) , KC_LSHIFT  ,  KC_RSHIFT , MO(_RAISE) ,  KC_LALT ,\
                                            KC_DEL     , KC_SPC     ,    KC_BSPC ,     KC_ENT
  ),

  [_RAISE] = LAYOUT_new( \
   KC_F11     , KC_F1      , KC_F2      , KC_F3      , KC_F4      , KC_F5       ,    KC_F6 ,   KC_F7 ,   KC_F8 ,   KC_F9 ,   KC_F10 ,  KC_F12 ,\
   KC_GRV     , KC_1       , KC_2       , KC_3       , KC_4       , KC_5        ,     KC_6 ,    KC_7 ,    KC_8 ,    KC_9 ,     KC_0 , KC_MUTE ,\
   _______    , KC_EXLM    , KC_AT      , KC_HASH    , KC_DLR     , KC_PERC     ,  KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN ,  KC_RPRN , KC_VOLU ,\
   RALT(KC_U) , RALT(KC_A) , RALT(KC_E) , RALT(KC_D) , RALT(KC_R) , RALT(KC_C)  ,  KC_PSCR , KC_LEFT , KC_DOWN ,   KC_UP , KC_RIGHT , KC_VOLD ,\
                                             SWAP_DL , _______    , _______     ,    RESET , _______ , KC_RALT ,\
                                                       KC_LCBR    , KC_LBRC     ,  KC_RBRC , KC_RCBR
  ),
};
