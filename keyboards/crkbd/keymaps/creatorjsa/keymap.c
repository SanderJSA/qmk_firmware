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
#define _LOWER 2
#define _RAISE 3
#define _SHIFT 4
#define _ADJUST 5

enum custom_keycodes {
  SWAP_DL = SAFE_RANGE,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

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
                                              _______ , _______ , _______ ,    _______ , TG(_QWERTY) , _______ \
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
                                                   _______ , TG(_QWERTY) , _______ ,    _______ , _______ ,    _______ \
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

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

char layer_state_str[24];
const char *read_layer_state(void) {
  switch (biton32(layer_state))
  {
  case _COLEMAK:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
    break;
  case _QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
    break;
  case _LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case _RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case _SHIFT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Shift");
    break;
  case _ADJUST:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }
  return layer_state_str;
}

// When add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    //matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode)
  {
  case SWAP_DL:
    if (record->event.pressed) {
      if (biton32(default_layer_state) == _COLEMAK) {
          //set_single_default_layer(_QWERTY);
      } else {
          //set_single_default_layer(_COLEMAK);
      }
    }
    return false;

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
