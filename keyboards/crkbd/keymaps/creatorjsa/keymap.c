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
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SHIFT 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,------------------------------------------------------------------.                     ,-------------------------------------------------------------------------.
      KC_ESC               , FR_Q , FR_W , FR_F , FR_P    , FR_B       ,                             FR_J ,    FR_L ,    FR_U ,   FR_Y , FR_SCLN ,              KC_ENT ,\
  //|----------------------+------+------+------+---------+------------|                     |------------+---------+---------+--------+---------+---------------------|
      LGUI_T(KC_TAB)       , FR_A , FR_R , FR_S , FR_T    , FR_G       ,                             FR_M ,    FR_N ,    FR_E ,   FR_I ,    FR_O , LT(_SHIFT, FR_QUOT) ,\
  //|----------------------+------+------+------+---------+------------|                     |------------+---------+---------+--------+---------+---------------------|
      MO(_SHIFT)           , FR_Z , FR_X , FR_C , FR_D    , FR_V       ,                             FR_K ,    FR_H , FR_COMM , FR_DOT ,  FR_EQL ,             FR_MINS ,\
  //|----------------------+------+------+------+---------+------------+--------|  |---------+------------+---------+---------+--------+---------+---------------------|
                                                  KC_LCTL , MO(_LOWER) , KC_SPC ,    KC_BSPC , MO(_RAISE) , KC_RALT \
                                              //`-------------------------------'  `--------------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------------.                      ,------------------------------------------------------------.
      FR_SLSH , FR_1    , FR_2    , FR_3    , FR_4    , FR_5    ,                           FR_6 ,    FR_7 ,    FR_8 ,    FR_9 ,     FR_0 , FR_BSLS ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+----------+---------|
      _______ , FR_EXLM , FR_AT   , FR_HASH , FR_DLR  , FR_PERC ,                        FR_CIRC , FR_AMPR , FR_ASTR , FR_LPRN ,  FR_RPRN ,  KC_DEL ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+----------+---------|
      _______ , KC_GRV  , FR_EACU , FR_EGRV , FR_AGRV , FR_CCED ,                        FR_LBRC , KC_LEFT , KC_DOWN ,   KC_UP , KC_RIGHT , FR_RBRC ,\
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+----------+---------|
                                              _______ , _______ , _______ ,    _______ , _______ , _______ \
                                          //`-----------------------------'  `-----------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,----------------------------------------------------------------.                     ,-----------------------------------------------------------------.
      FR_QUES , KC_F1        , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                         KC_F6 ,      KC_F7 ,   KC_F8 ,   KC_F9 ,     KC_F10 , FR_PIPE ,\
  //|---------+--------------+---------+---------+---------+---------|                     |---------+------------+---------+---------+------------+---------|
      _______ , OSL(_ADJUST) , XXXXXXX , XXXXXXX , KC_VOLU , KC_F12  ,                       KC_PSCR , LCTL(KC_A) , KC_PGDN , KC_PGUP , LCTL(KC_E) ,  KC_DEL ,\
  //|---------+--------------+---------+---------+---------+---------|                     |---------+------------+---------+---------+------------+---------|
      _______ , KC_TILD      , XXXXXXX , XXXXXXX , KC_VOLD , KC_F11  ,                       FR_LCBR ,    KC_LEFT , KC_DOWN ,   KC_UP ,   KC_RIGHT , FR_RCBR ,\
  //|---------+--------------+---------+---------+---------+---------+---------|  |--------+---------+------------+---------+---------+------------+---------|
                                                   _______ , _______ , _______ ,    KC_DEL , _______ ,    _______ \
                                               //`-----------------------------'  `-------------------------------'
  ),

  [_SHIFT] = LAYOUT( \
  //,-----------------------------------------------------------.                      ,-----------------------------------------------------------------------.
      _______ , S(FR_Q) , S(FR_W) , S(FR_F) , S(FR_P) , S(FR_B) ,                        S(FR_J) , S(FR_L) , S(FR_U) , S(FR_Y) , FR_COLN ,            _______  ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+---------+---------------------|
      _______ , S(FR_A) , S(FR_R) , S(FR_S) , S(FR_T) , S(FR_G) ,                        S(FR_M) , S(FR_N) , S(FR_E) , S(FR_I) , S(FR_O) , MT(_SHIFT, FR_DQUO) ,\
  //|---------+---------+---------+---------+---------+---------|                      |---------+---------+---------+---------+---------+---------------------|
      _______ , S(FR_Z) , S(FR_X) , S(FR_C) , S(FR_D) , S(FR_V) ,                        S(FR_K) , S(FR_H) , FR_LABK , FR_RABK , FR_PLUS ,             FR_UNDS ,\
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------------------|
                                              _______ , _______ , _______ ,    _______ , _______ , _______ \
                                          //`-----------------------------'  `-----------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL,   LOWER,  KC_SPC,     KC_BSPC, _______, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

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

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
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
    matrix_write_ln(matrix, read_keylog());
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
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
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
