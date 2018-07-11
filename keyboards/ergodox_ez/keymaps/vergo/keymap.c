#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// Layers.
enum my_layers {
    LAY_BASE, // normal
    LAY_MAUS, // mouse stuff
    LAY_NUMK, // numeric keypad
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAY_BASE] = LAYOUT_ergodox_80(
    // Left hand
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MUTE,
    KC_MINUS, KC_X, KC_F, KC_R, KC_P, KC_V, KC_VOLU,
    KC_COMMA, KC_A, KC_S, KC_H, KC_T, KC_G,
    KC_DOT, KC_Q, KC_Z, KC_SCOLON, KC_M, KC_K, KC_VOLD,
    KC_RBRACKET, KC_LALT, KC_BSLASH, KC_LGUI, KC_LCTRL,
    // Left thumb
    KC_MPLY, KC_QUOTE,
    KC_MPRV, KC_MNXT, KC_F13,
    KC_SPC, KC_LSHIFT, KC_ENTER,
    // Right hand
    KC_LBRACKET, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQUAL,
    TO(LAY_NUMK), KC_B, KC_L, KC_O, KC_W, KC_F14, KC_F15,
    KC_C, KC_N, KC_E, KC_U, KC_I, KC_Y,
    TO(LAY_MAUS), KC_F16, KC_D, KC_UP, KC_F17, KC_J, KC_SLASH,
    KC_LEFT, KC_DOWN, KC_RIGHT, KC_ESC, KC_F18,
    // Right thumb
    KC_F19, KC_F20,
    KC_PSCR, KC_INSERT, KC_DELETE,
    KC_TAB, KC_RALT, KC_BSPACE
    ),
// mouse stuff
[LAY_MAUS] = LAYOUT_ergodox_80(
    KC_F1, KC_F2, KC_F3, KC_BTN3, KC_F4, KC_F5, KC_F6,
    KC_SPC, KC_TAB, KC_BTN1, KC_MS_U, KC_BTN2, KC_PGUP, 0,
    KC_ENTER, KC_WBAK, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGDN,
    KC_LCTRL, 0, 0, KC_UP, KC_DEL, KC_BSPC, TO(LAY_BASE),
    KC_RGUI, KC_LALT, KC_LEFT, KC_DOWN, KC_RIGHT,
    // left thumb
    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_F7, KC_F8, KC_F9, KC_BTN3,KC_F10, KC_F11, KC_F12,
    0, KC_PGUP, KC_BTN1, KC_MS_U,KC_BTN2, KC_TAB, KC_SPC,
    KC_PGDN, KC_MS_L, KC_MS_D, KC_MS_R, KC_WBAK, KC_ENTER,
    TO(LAY_BASE), KC_BSPC, KC_DEL, KC_UP, 0, 0, KC_RCTRL,
    KC_LEFT, KC_DOWN, KC_RIGHT, KC_RALT, KC_RGUI,
    // right thumb
    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
    ),
// numeric keypad
[LAY_NUMK] = LAYOUT_ergodox_80(
    // left hand
    0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1,
    0, 1, 0, 1, 1,
    // left thumb
    1, 1,
    1, 1, 1,
    1, 1, 1,
    // right hand
    0,0, KC_A, KC_B, KC_C, KC_F21, 1,
    TO(LAY_BASE), KC_F, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK, KC_KP_SLASH,
    KC_E, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_KP_MINUS,
    1, KC_D, KC_KP_1, KC_KP_2, KC_KP_3, KC_MINUS, KC_F15,
    KC_KP_0, KC_KP_DOT, KC_KP_COMMA, 1, KC_KP_ENTER,
    // right thumb
    0, 0,
    1, 1, 1,
    1, 1, 1
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
    uint8_t layer = biton32(layer_state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case LAY_MAUS:
            ergodox_right_led_3_on();
            break;
        case LAY_NUMK:
            ergodox_right_led_2_on();
            break;
        default:
            break;
    }
};
