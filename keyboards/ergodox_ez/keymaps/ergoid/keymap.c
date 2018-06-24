#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define LAY0 0 // ASCII and programming layer.
#define LAY1 1 // Uppercase letters.
#define LAY2 2 // TODO AltGR stuff

// us altgr-intl keycodes
#define UAI_STAR S(KC_8) // *
#define UAI_DQUO S(KC_QUOT) /* " */
#define UAI_COLO S(KC_SCLN) // :
#define UAI_LANG S(KC_COMMA) // <
#define UAI_RANG S(KC_DOT) // >
#define UAI_LCRB S(KC_LBRACKET) // {
#define UAI_RCRB S(KC_RBRACKET) // }
#define UAI_LGUIL RALT(KC_LBRACKET) // «
#define UAI_RGUIL RALT(KC_RBRACKET) // »
#define UAI_LDQUO RALT(S(KC_LBRACKET)) // “
#define UAI_RDQUO RALT(S(KC_RBRACKET)) // ”
#define UAI_LQUO RALT(KC_9) // ‘
#define UAI_RQUO RALT(KC_0) // ’
#define UAI_LPAR S(KC_9) // (
#define UAI_RPAR S(KC_0) // )
#define UAI_QUES S(KC_SLSH) // ?
#define UAI_CAROT S(KC_6) // ^
#define UAI_VERTB S(KC_BSLS) // |
#define UAI_AT S(KC_2) // @
#define UAI_RBANG S(KC_1) // !
#define UAI_AMP S(KC_7) // &
#define UAI_DOLLAR S(KC_4) // $
#define UAI_PERC S(KC_5) // %
#define UAI_USCOR S(KC_MINUS) // _
#define UAI_PLUS S(KC_EQL) // +
#define UAI_NUFLO S(KC_GRV) // ~
#define UAI_HASH S(KC_3) // #

/* English:
 *   - Letters: e t a o i n s rh dl ucm f ywg p b v k xqjz
 *   - Bigrams: th he in er an re es on st nt
 *              en at ed nd to or ea ti ar te
 *              ng al it as is ha et se ou of
 *  ztrneiasthzniedsznre
 * Spanish:
 *   - Letters: e a o s n r il dtu c mp b hqyvg fjz xkw
 *   - Bigrams: de es en el la os on as er ra
 *              ad ar re al an nt ue ci co se
 *              ta te or do io ac st na ro un
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: ASCII and programming layer.
 *
 * Left:
 * ,--------------------------------------------------.
 * |     |  |   &  |   *  |   -  |   @  |   ^  |   ~  |
 * |--------+------+------+------+------+-------------|
 * |     (  |   /  |   f  |   r  |   p  |   v  |   +  |
 * |--------+------+------+------+------+------|      |
 * |     ,  |   a  |   s  |   h  |   t  |   g  |------|
 * |--------+------+------+------+------+------|   #  |
 * |     {  |   q  |   z  |   }  |   m  |   k  |      |
 * `--------+------+------+------+------+-------------'
 *   |      |      |      |  `   |   _  |
 *   `----------------------------------'
 * Right:
 * ,--------------------------------------------------.
 * |  [   |   ]  |   "" |   !  |   <  |  >   | =      |
 * |------+------+------+------+------+------+--------|
 * |  \   |   b  |   l  |   o  |   w  |  x   | )      |
 * |      |------+------+------+------+------+--------|
 * |------|   c  |   n  |   e  |   u  |  i   | .;     |
 * |  %   |------+------+------+------+------+--------|
 * |      |   ?  |   d  |   :  |   j  |  y   | $      |
 * `-------------+------+------+------+------+--------'
 *               |  Esc |   '  |      |      |      |
 *               `----------------------------------'
 * Left:                        Right:
 *        ,-------------.       ,-------------.
 *        |      |      |       |      |        |
 * ,------|------|------|       |------+--------+------.
 * |      |      |      |       |      |        |      |
 * |------|------|------|       |------|--------|------|
 * | Space|      |      |       |      | Enter  | LAY1 |
 * `--------------------'       `----------------------'
 *
 * - '.' emits ';' if ',' is pressed as well.
 */
[LAY0] = LAYOUT_ergodox_80(
        // left hand
        UAI_VERTB, UAI_AMP,   UAI_STAR, KC_MINUS,   UAI_AT,  UAI_CAROT, UAI_NUFLO,
        UAI_LPAR,  KC_SLSH,   KC_F,      KC_R,      KC_P,    KC_V,      UAI_PLUS,
        KC_COMMA,  KC_A,      KC_S,      KC_H,      KC_T,    KC_G,
        UAI_LCRB,  KC_Q,      KC_Z,      UAI_RCRB,  KC_M,    KC_K,      UAI_HASH,
        KC_NO,     KC_NO,     KC_NO,     KC_GRV,    UAI_USCOR,
        // left thumb
                KC_NO,   KC_NO,
        KC_NO,  KC_NO,   KC_NO,
        KC_SPC, KC_NO,   KC_NO,

        // right hand
        KC_LBRACKET, KC_RBRACKET,  UAI_DQUO, UAI_RBANG, UAI_LANG, UAI_RANG, KC_EQL,
        KC_BSLS,     KC_B,         KC_L,     KC_O,      KC_W,     KC_X,     UAI_RPAR,
                     KC_C,         KC_N,     KC_E,      KC_U,     KC_I,     KC_DOT,
        UAI_PERC,    UAI_QUES,     KC_D,     UAI_COLO,  KC_J,     KC_Y,     UAI_DOLLAR,
                                   KC_ESC,   KC_QUOT,   KC_NO,    KC_NO,    KC_NO,
        // right thumb
        KC_NO, KC_NO,
        KC_NO, KC_NO,    KC_NO,
        KC_NO, KC_ENTER, TT(LAY1)
    ),

/* Layer 1: Uppercase letters
 */
[LAY1] = LAYOUT_ergodox_80(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, S(KC_F), S(KC_R), S(KC_P), S(KC_V), KC_TRNS,
        KC_TRNS, S(KC_A), S(KC_S), S(KC_H), S(KC_T), S(KC_G),
        KC_TRNS, S(KC_Q), S(KC_Z), KC_TRNS, S(KC_M), S(KC_K), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // left thumb
                   KC_TRNS,   KC_TRNS,
        KC_TRNS,  KC_TRNS,   KC_TRNS,
        KC_TRNS,  KC_TRNS,   KC_TRNS,

        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, S(KC_B), S(KC_L), S(KC_O), S(KC_W), S(KC_X), KC_TRNS,
                 S(KC_C), S(KC_N), S(KC_E), S(KC_U), S(KC_I), KC_TRNS,
        KC_TRNS, KC_TRNS, S(KC_D), KC_TRNS, S(KC_J), S(KC_Y), KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // right thumb
        KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS
    ),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
 */
// MEDIA AND MOUSE
[LAY2] = LAYOUT_ergodox_80(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool is_down_comma = false;
    static bool print_comma = false;

    if (record->event.pressed) {
        // On key down
        switch (keycode) {
        case KC_COMMA:
            is_down_comma = true;
            print_comma = true;
            return false;
        case KC_DOT:
            if (is_down_comma) {
                print_comma = false;
                SEND_STRING(";");
                return false;
            };
        default:
            if (print_comma) {
               print_comma = false;
               SEND_STRING(",");
            };
        }
    } else {
        // On key up
        is_down_comma = false;
        if (print_comma) {
            print_comma = false;
            SEND_STRING(",");
        };
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) { };

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
