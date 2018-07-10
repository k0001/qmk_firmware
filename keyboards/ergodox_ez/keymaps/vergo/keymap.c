#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// Layers.
enum my_layers {
    LAY0, // normal
    LAY1, // mouse stuff
    LAY2, // numeric keypad
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAY0] = LAYOUT_ergodox_80(
    // Left hand
    4,5,6,7,8,9,10,
    11,12,13,14,15,16,17,
    18,19,20,21,22,23,
    31,24,25,26,27,28,29,
    30,KC_LALT,32,KC_LGUI,KC_LCTRL,
    // Left thumb
    35,36,
    37,38,39,
    40,KC_LSFT,41,
    // Right hand
    42,43,44,45,46,47,48,
    49,51,52,53,54,55,56,
    57,58,59,60,61,MT(MOD_LGUI,62),
    TO(LAY1)/*63*/,64,65,66,67,68,69,
    81,70,71,72,73,
    // Right thumb
    74,75,
    76,77,78,
    79,84,80
    ),
// mouse stuff
[LAY1] = LAYOUT_ergodox_80(
    0,0,0,KC_BTN3,0,0,0,
    0,0,KC_BTN1,KC_MS_U,KC_BTN2,0,0,
    0,0,KC_MS_L,KC_MS_D,KC_MS_R,0,
    0,0,0,0,0,0,0,
    0,0,0,0,0,
    // left thumb
    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    0,0,0,KC_BTN3,0,0,0,
    0,0,KC_BTN1,KC_MS_U,KC_BTN2,0,0,
    0,KC_MS_L,KC_MS_D,KC_MS_R,0,0,
    TO(LAY0),0,0,0,0,0,0,
    0,0,0,0,0,
    // right thumb
    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
    ),
// numeric keypad
[LAY2] = LAYOUT_ergodox_80(
    // Left hand
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,
    0,0,0,0,0,0,0,
    0,0,0,0,0,
    // Left thumb
    0,0,
    0,0,0,
    0,0,0,
    // Right hand
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,
    TO(LAY0),0,0,0,0,0,0,
    0,0,0,0,0,
    // Right thumb
    0,0,
    0,0,0,
    0,0,0
    ),
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
