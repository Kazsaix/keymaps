#include QMK_KEYBOARD_H

#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_ROMAK] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________ROMAK_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________ROMAK_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L2____________________ , XXXXXXX , XXXXXXX , ___________________ROMAK_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KCR_MAC , _________ROMAK_L3____________________ , XXXXXXX , XXXXXXX , ___________________ROMAK_R3__________ , KCI_MAC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____ROMAK_L4_____ ,      XXXXXXX      , ____ROMAK_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_NUMPAD] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________NUMPAD_L1_________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________NUMPAD_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NUMPAD_L2___________________ , XXXXXXX , XXXXXXX , ___________________NUMPAD_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NUMPAD_L3___________________ , XXXXXXX , XXXXXXX , ___________________NUMPAD_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____NUMPAD_L4____ ,      XXXXXXX      , ____NUMPAD_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_ACCENT] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________ACCENT_L1_________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________ACCENT_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ACCENT_L2___________________ , XXXXXXX , XXXXXXX , ___________________ACCENT_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________ACCENT_L3___________________ , XXXXXXX , XXXXXXX , ___________________ACCENT_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____ACCENT_L4____ ,      XXXXXXX      , ____ACCENT_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MACROS] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MACROS_L1_________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________MACROS_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MACROS_L2___________________ , XXXXXXX , XXXXXXX , ___________________MACROS_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________MACROS_L3___________________ , XXXXXXX , XXXXXXX , ___________________MACROS_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____MACROS_L4____ ,      XXXXXXX      , ____MACROS_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________LOWER_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________LOWER_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L2____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________LOWER_L3____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____LOWER_L4_____ ,      XXXXXXX      , ____LOWER_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________RAISE_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________RAISE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L2____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________RAISE_L3____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____RAISE_L4_____ ,      XXXXXXX      , ____RAISE_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_FIXED_NAV] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NAVIGATION_L3_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R3_____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __NAVIGATION_L4__ ,      XXXXXXX      , __FIXED_NAV__R4__ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_NAVIGATION] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NAVIGATION_L3_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R3_____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __NAVIGATION_L4__ ,      XXXXXXX      , __NAVIGATION_R4__ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MEDIA] = LAYOUT_wrapper(
 // |_______________________________ ________________________________________________________________________________________|
      ___________________MEDIA_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________MEDIA_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L2____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________MEDIA_L3____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____MEDIA_L4_____ ,      XXXXXXX      , ____MEDIA_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_LOCK] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      _______________________LOCK____L1____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _____________LOCK____R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______________________LOCK____L2______________ , XXXXXXX , XXXXXXX , _______________________LOCK____R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _____________LOCK____L3______________ , XXXXXXX , XXXXXXX , _______________________LOCK____R3____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ______LOCK____L4_ ,      XXXXXXX      , ______LOCK____R4_ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MAINTENANCE] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MAINTENANCE_L1____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________MAINTENANCE_R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L2______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________MAINTENANCE_L3______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R3____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __MAINTENANCE_L4_ ,      XXXXXXX      , __MAINTENANCE_R4_ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_______________________________________________________________________________________________________________________|
};

// clang-format on

// RGB Indicators

extern os_t          os;
extern leader_t      leader;
extern select_word_t select_word;
extern swapper_t     swapper;
const int            led_count = 17;
int                  leds[]    = {0, 4, 5, 6, 7, 11, 17, 18, 29, 30, 36, 37, 38, 41, 44, 45, 46};

void keyboard_post_init_user(void) {
    os.type = WINDOWS;
}

void set_rgblight_by_layer(uint32_t layer) {
    for (int i = 0; i < led_count; i++) {
        switch (layer) {
            case _LOCK:
            case _ROMAK:
                break;
            case _NUMPAD:
                rgb_matrix_set_color(leds[i], RGB_PURPLE);
                break;
            case _MAINTENANCE:
                rgb_matrix_set_color(leds[i], RGB_RED);
                break;
            default:
                rgb_matrix_set_color(leds[i], RGB_BLUE);
                break;
        }
    }
}

void set_current_layer_rgb(void) {
    set_rgblight_by_layer(get_highest_layer(layer_state | default_layer_state));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_rgblight_by_layer(biton32(state));
    return state;
}

bool rgb_matrix_indicators_user(void) {
    uint8_t mods                = get_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();

    bool isShift = mods & MOD_MASK_SHIFT || oneshot_mods & MOD_MASK_SHIFT || oneshot_locked_mods & MOD_MASK_SHIFT;
    bool isCtrl  = mods & MOD_MASK_CTRL || oneshot_mods & MOD_MASK_CTRL || oneshot_locked_mods & MOD_MASK_CTRL;
    bool isAlt   = mods & MOD_MASK_ALT || oneshot_mods & MOD_MASK_ALT || oneshot_locked_mods & MOD_MASK_ALT;
    bool isGui   = mods & MOD_MASK_GUI || oneshot_mods & MOD_MASK_GUI || oneshot_locked_mods & MOD_MASK_GUI;

    for (int i = 0; i < led_count; i++) {
        if (swapper.state != NONE || leader.isLeading || select_word.state != STATE_NONE) {
            rgb_matrix_set_color(leds[i], RGB_GREEN);
        } else if (has_any_smart_case()) {
            rgb_matrix_set_color(leds[i], RGB_YELLOW);
        } else if (isShift) {
            rgb_matrix_set_color(leds[i], RGB_BLUE);
        } else if (isCtrl || isAlt || isGui) {
            rgb_matrix_set_color(leds[i], RGB_WHITE);
        } else {
            set_current_layer_rgb();
        }
    }

    return false;
}
