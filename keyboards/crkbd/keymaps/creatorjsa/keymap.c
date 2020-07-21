#include QMK_KEYBOARD_H
#include "keymap_french.h"


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _QWERTY 1
#define _SHIFT 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define SWAP_DL TG(_QWERTY)

//
// Keymaps
//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT( \
  //,--------------------------------------------------------------------------.                     ,---------------------------------------------------------------------------------.
      KC_ESC               , FR_Q , FR_W , FR_F , FR_P            , FR_B       ,                             FR_J ,            FR_L ,    FR_U ,   FR_Y , FR_SCLN ,              KC_ENT ,\
  //|----------------------+------+------+------+-----------------+------------|                     |------------+-----------------+---------+--------+---------+---------------------|
      LGUI_T(KC_TAB)       , FR_A , FR_R , FR_S , FR_T            , FR_G       ,                             FR_M ,            FR_N ,    FR_E ,   FR_I ,    FR_O , LT(_SHIFT, FR_QUOT) ,\
  //|----------------------+------+------+------+-----------------+------------|                     |------------+-----------------+---------+--------+---------+---------------------|
      MO(_SHIFT)           , FR_Z , FR_X , FR_C , FR_D            , FR_V       ,                             FR_K ,            FR_H , FR_COMM , FR_DOT , FR_MINS ,              FR_EQL ,\
  //|----------------------+------+------+------+-----------------+------------+--------|  |---------+------------+-----------------+---------+--------+---------+---------------------|
                                                  LCTL_T(FR_LPRN) , MO(_LOWER) , KC_SPC ,    KC_BSPC , MO(_RAISE) , LALT_T(FR_RPRN) \
                                              //`---------------------------------------'  `----------------------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------------.                      ,------------------------------------------------------------.
      FR_SLSH , FR_1    , FR_2    , FR_3    , FR_4    , FR_5    ,                           FR_6 ,    FR_7 ,    FR_8 ,    FR_9 ,     FR_0 , FR_BSLS ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+----------+---------|
      _______ , FR_EXLM , FR_AT   , FR_HASH , FR_DLR  , FR_PERC ,                        FR_CIRC , FR_AMPR , FR_ASTR , FR_LBRC ,  FR_RBRC ,  KC_DEL ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+----------+---------|
      _______ , FR_EURO , FR_EACU , FR_EGRV , FR_AGRV , FR_CCED ,                         FR_GRV , KC_LEFT , KC_DOWN ,   KC_UP , KC_RIGHT , _______ ,\
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+----------+---------|
                                              _______ , _______ , _______ ,    _______ , SWAP_DL , _______ \
                                          //`-----------------------------'  `-----------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,----------------------------------------------------------------.                      ,--------------------------------------------------------------------.
      FR_QUES , KC_F1        , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                          KC_F6 ,      KC_F7 ,      KC_F8 ,   KC_F9 ,     KC_F10 , FR_PIPE ,\
  //|---------+--------------+---------+---------+---------+---------|                      |---------+------------+------------+---------+------------+---------|
      _______ , KC_MUTE      , XXXXXXX , KC_PGUP , KC_VOLU , KC_F12  ,                        KC_PSCR , LCTL(FR_A) , LCTL(FR_E) , FR_LCBR ,    FR_RCBR ,  KC_DEL ,\
  //|---------+--------------+---------+---------+---------+---------|                      |---------+------------+------------+---------+------------+---------|
      _______ , OSL(_ADJUST) , XXXXXXX , KC_PGDN , KC_VOLD , KC_F11  ,                        FR_TILD ,    KC_LEFT ,    KC_DOWN ,   KC_UP ,   KC_RIGHT , _______ ,\
  //|---------+--------------+---------+---------+---------+---------+---------|  |---------+---------+------------+------------+---------+------------+---------|
                                                   _______ , SWAP_DL , _______ ,    _______ , _______ ,    _______ \
                                               //`-----------------------------'  `--------------------------------'
  ),

  [_SHIFT] = LAYOUT( \
  //,-----------------------------------------------------------.                      ,-----------------------------------------------------------------------.
      _______ , S(FR_Q) , S(FR_W) , S(FR_F) , S(FR_P) , S(FR_B) ,                        S(FR_J) , S(FR_L) , S(FR_U) , S(FR_Y) , FR_COLN ,           S(KC_ENT) ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+---------+---------------------|
      _______ , S(FR_A) , S(FR_R) , S(FR_S) , S(FR_T) , S(FR_G) ,                        S(FR_M) , S(FR_N) , S(FR_E) , S(FR_I) , S(FR_O) , LT(_SHIFT, FR_DQUO) ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+---------+---------------------|
      _______ , S(FR_Z) , S(FR_X) , S(FR_C) , S(FR_D) , S(FR_V) ,                        S(FR_K) , S(FR_H) , FR_LABK , FR_RABK , FR_UNDS ,             FR_PLUS ,\
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------------------|
                                              _______ , _______ , _______ ,    _______ , _______ , _______ \
                                          //`-----------------------------'  `-----------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------------.                      ,-----------------------------------------------------------.
      RESET   , RGBRST  , EEP_RST , XXXXXXX , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+---------+---------|
      RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+---------+---------|
      RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX ,                        XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,\
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                              _______ , _______ , _______ ,    _______ , _______ , _______ \
                                          //`-----------------------------'  `-----------------------------'
  ),

  [_QWERTY] = LAYOUT( \
  //,-------------------------------------------------------------.                     ,---------------------------------------------------------------------------------.
      KC_ESC         , FR_Q , FR_W , FR_E , FR_R     , FR_T       ,                             FR_Y ,            FR_U ,    FR_I ,   FR_O ,    FR_P ,              KC_ENT ,\
  //|----------------+------+------+------+----------+------------|                     |------------+-----------------+---------+--------+---------+---------------------|
      LGUI_T(KC_TAB) , FR_A , FR_S , FR_D , FR_F     , FR_G       ,                             FR_H ,            FR_J ,    FR_K ,   FR_L , FR_SCLN , LT(_SHIFT, FR_QUOT) ,\
  //|----------------+------+------+------+----------+------------|                     |------------+-----------------+---------+--------+---------+---------------------|
      KC_LSHIFT      , FR_Z , FR_X , FR_C , FR_V     , FR_B       ,                             FR_N ,            FR_M , FR_COMM , FR_DOT , FR_SLSH ,              FR_EQL ,\
  //|----------------+------+------+------+----------+------------+--------|  |---------+------------+-----------------+---------+--------+---------+---------------------|
                                            KC_LCTRL , MO(_LOWER) , KC_SPC ,    KC_BSPC , MO(_RAISE) , LALT_T(FR_RPRN) \
                                        //`--------------------------------'  `----------------------------------------'
  )
};

//
// Special actions
//

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode)
  {
  case RGBRST:
    #ifdef RGBLIGHT_ENABLE
    if (record->event.pressed) {
      eeconfig_update_rgblight_default();
      rgblight_enable();
      RGB_current_mode = rgblight_config.mode;
    }
    #endif
    break;
  }
  return true;
}

//
// RGB
//

int RGB_current_mode;

#ifdef RGBLIGHT_ENABLE
void matrix_init_user(void) {
      RGB_current_mode = rgblight_config.mode;
}
#endif

//
// OLED
//

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) {
        return OLED_ROTATION_180;
    }
    return rotation;
}
#endif

#ifdef SSD1306OLED
void render_cat(void);

void render_layer_state(void) {
  switch (biton32(layer_state))
  {
  case _COLEMAK:
    oled_write_ln_P(PSTR("Colemak"), false);
    break;
  case _QWERTY:
    oled_write_ln_P(PSTR("Qwerty"), false);
    break;
  case _LOWER:
    oled_write_ln_P(PSTR("Lower"), false);
    break;
  case _RAISE:
    oled_write_ln_P(PSTR("Raise"), false);
    break;
  case _SHIFT:
    oled_write_ln_P(PSTR("Shift"), false);
    break;
  case _ADJUST:
    oled_write_ln_P(PSTR("Adjust"), false);
    break;
  default:
    oled_write_ln_P(PSTR("Undefined"), false);
  }
}

char wpm[5];
void oled_task_user(void) {
  if (is_master) {
    oled_write_P(PSTR("Layer: "), false);
    render_layer_state();
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
  } else {
    render_cat();
    oled_set_cursor(17, 3);
    snprintf(wpm, sizeof(wpm), "%03d", get_current_wpm());
    oled_write(wpm, false);
  }
}

static const char PROGMEM idle[128 * 32 / 8] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x20,
0x20, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x18, 0x08, 0x04, 0x06, 0x02, 0x03, 0x03, 0x06, 0x04,
0x08, 0x18, 0x30, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x78, 0xfe, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02,
0x06, 0x0c, 0x0c, 0x04, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08,
0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0xfe, 0x7c, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x02, 0x02, 0x02, 0x07, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40,
0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x81, 0x83, 0x82, 0x82, 0x82, 0x83, 0x86, 0x04, 0x04, 0x04,
0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0xe0,
0xf8, 0x0c, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x0c, 0x18, 0x30, 0x20,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x2c, 0x67, 0xc1, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x40, 0x30, 0x40, 0x3e, 0x00, 0x7e, 0x12, 0x12, 0x12,
0x0c, 0x00, 0x7e, 0x04, 0x18, 0x04, 0x7e, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04,
0x07, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x41, 0x47, 0x4c, 0xf8, 0xe0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void render_cat(void) {
    oled_set_cursor(0, 0);
    oled_write_raw_P(idle, sizeof(idle));
}

#endif//SSD1306OLED
