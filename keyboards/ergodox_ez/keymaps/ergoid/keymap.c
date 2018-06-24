#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

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
/* Keymap 0: Basic layer
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
 * | Space|      |      |       |      |        |      |
 * `--------------------'       `----------------------'
 *
 * i' emits `ui` if `q` is pressed as well.
 *
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox_80(  // layer 0 : default
        // left hand
        UAI_VERTB, UAI_AMP,   UAI_STAR, KC_MINUS,  UAI_AT, UAI_CAROT, UAI_NUFLO,
        UAI_LPAR,  KC_SLSH,   KC_F,      KC_R,      KC_P,    KC_V,  UAI_PLUS,
        KC_COMMA,  KC_A,      KC_S,      KC_H,      KC_T,    KC_G,
        UAI_LCRB,  KC_Q,      KC_Z,      UAI_RCRB,  KC_M,    KC_K,  UAI_HASH,
        KC_NO,     KC_NO,     KC_NO,     KC_GRV,    UAI_USCOR,
        // left thumb
                KC_NO,   KC_NO,
        KC_NO,  KC_NO,   KC_NO,
        KC_SPC, KC_ENTER,KC_NO,

        // right hand
        KC_LBRACKET, KC_RBRACKET,  UAI_DQUO, UAI_RBANG, UAI_LANG, UAI_RANG, KC_EQL,
        KC_BSLS,     KC_B,         KC_L,     KC_O,      KC_W,     KC_X,     UAI_RPAR,
                     KC_C,         KC_N,     KC_E,      KC_U,     KC_I,     KC_DOT,
        UAI_PERC,    UAI_QUES,     KC_D,     UAI_COLO,  KC_J,     KC_Y,     UAI_DOLLAR,
                                   KC_ESC,   KC_QUOT,   KC_NO,    KC_NO,    KC_NO,
        // right thumb
        KC_NO, KC_NO,
        KC_NO, KC_NO,  KC_NO,
        KC_NO, KC_NO,  KC_NO
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox_80(
       // left hand
       M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
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
[MDIA] = LAYOUT_ergodox_80(
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
