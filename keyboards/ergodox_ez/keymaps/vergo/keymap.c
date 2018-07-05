#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// Layers.
enum my_layers {
    LAY0 = 0, // normal
    LAY1,     // mouse stuff
    LAY2,     // numeric keypad
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAY0] = LAYOUT_ergodox_80(
    // Left hand
    4,5,6,7,8,9,10,
    11,12,13,14,15,16,17,
    18,19,20,21,22,23,
    KC_LCTRL,24,25,26,27,28,29,
    30,31,32,33,34,
    // Left thumb
    35,36,
    37,38,39,
    40,KC_LSHIFT,41,
    // Right hand
    42,43,44,45,46,47,48,
    49,51,52,53,54,55,56,
    57,58,59,60,61,62,
    63,64,65,66,67,68,KC_RGUI,
    68,69,70,71,72,
    // Right thumb
    73,74,
    75,76,77,
    78,KC_RALT,79
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    // uint8_t layer = biton32(layer_state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
};
