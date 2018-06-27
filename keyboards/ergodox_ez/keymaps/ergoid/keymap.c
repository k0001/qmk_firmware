#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// TT(...)
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 3

// Layers.
#define LAY0 0 // ASCII and programming.
#define LAY1 1 // Like LAY0 but with uppercase letters.
#define LAY2 2 // Media keys, Fn keys, mouse, keypad.
#define LAY3 3 // Diacritics and characters for languages with latin alphabet.

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
#define UAI_A_DIERESIS RALT(Q) // ä
#define UAI_C_CEDILLA RALT(KC_COMMA) // ç
#define UAI_DEAD_ACUTE RALT(KC_QUOT) // ◌́ – acute
#define UAI_DEAD_UMLAUT S(RALT(KC_QUOT)) // ◌̈ – diaeresis or umlaut
#define UAI_DEAD_GRAVE RALT(KC_GRV) // ◌̀ – grave
#define UAI_DEAD_DACUTE S(RALT(KC_2)) // ◌̋ – double acute
#define UAI_DEAD_CAROT RALT(KC_6) // ◌̂ – circumflex
#define UAI_DEAD_CARON S(RALT(KC_DOT)) // ◌̌ – caron
#define UAI_DEAD_OVERDOT RALT(KC_DOT) // ◌̇ – overdot
#define UAI_DEAD_UNDERDOT S(RALT(KC_MINUS)) // ◌̣ – underdot
#define UAI_DEAD_BREVE S(RALT(KC_9)) // ◌̆ – breve
#define UAI_DEAD_NUFLO S(RALT(KC_GRV)) // ◌̃ - tilde
#define UAI_DEAD_MACRON S(RALT(KC_3)) // ◌̄ – macron
#define UAI_DEAD_ORING S(RALT(KC_0)) // ◌̊ – overring
#define UAI_DEAD_OGONEK S(RALT(KC_8)) // ◌̨ – ogonek
#define UAI_DEAD_CEDILLA S(RALT(KC_5)) // ◌̧ – cedilla

// Unicode input (for stuff absent from us-altgr-intl)
#define UNI_S_COMMA UC(0x0218) // Ș
#define UNI_S_COMMA_U UC(0x0219) // ș
#define UNI_T_COMMA UC(0x021b) // ț
#define UNI_T_COMMA_U UC(0x021a) // Ț

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
 *   | LAY2 |      |   ASADAZXZCX   |  `   |   _  |
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
 *        | LAY2 |      |       |      |        |
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
    TT(LAY2),  KC_NO,     UNI_S_COMMA,     KC_GRV,    UAI_USCOR,
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

/* Keymap 2: Media keys, Fn keys, mouse, keypad.
 *
 * Left hand:
 * ,--------------------------------------------------.
 * |    F1  |   F2 |  F3  |  F4  |   F5 |  F6  |  F7  |
 * |--------+------+------+------+------+-------------|
 * |        |      | Btn2 | MsUp | Btn3 |      |      |
 * |--------+------+------+------+------+------|      |
 * |        | Btn1 |MsLeft|MsDown|MsRght| WBack|------|
 * |--------+------+------+------+------+------|      |
 * |        |  F8  |  F9  |  F10 |  F11 |  F12 |      |
 * `--------+------+------+------+------+-------------'
 *   | VolDn| VolUp| Prev | Next | Play |
 *   `----------------------------------'
 * Right:
 * ,--------------------------------------------------.
 * |    a |   b  |   c  |   d  |   e  |  f   |  =     |
 * |------+------+------+------+------+------+--------|
 % |      |   %  |   7  |   8  |   9  |  (   |  )     |
 * |      |------+------+------+------+------+--------|
 * |------|   /  |   4  |   5  |   6  |  *   |        |
 * |      |------+------+------+------+------+--------|
 * |      |   *  |   1  |   2  |   3  |  +   |        |
 * `-------------+------+------+------+------+--------'
 *               |   0  |   .  |   ,  | Enter|      |
 *               `----------------------------------'
 * Left:                        Right:
 *        ,-------------.       ,-------------.
 *        | LAY0 |      |       |      |        |
 * ,------|------|------|       |------+--------+------.
 * |      |      |      |       |      |        |      |
 * |------|------|------|       |------|--------|------|
 * |      |      |      |       |      |        |      |
 * `--------------------'       `----------------------'
 */
// Mouse, media, keypad.
[LAY2] = LAYOUT_ergodox_80(
    // left hand
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,
    KC_NO,   KC_NO,   KC_BTN2, KC_MS_U, KC_BTN3, KC_NO,   KC_NO,
    KC_NO,   KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WBAK,
    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,
    KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY,
    // left thumb
             KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,
    // right hand
    KC_A,  KC_B,     KC_C, KC_D,   KC_E,     KC_F,     KC_EQL,
    KC_NO, UAI_PERC, KC_7, KC_8,   KC_9,     UAI_LPAR, UAI_RPAR,
           KC_SLSH,  KC_4, KC_5,   KC_6,     UAI_STAR, KC_NO,
    KC_NO, UAI_STAR, KC_1, KC_2,   KC_3,     UAI_PLUS, KC_NO,
                     KC_0, KC_DOT, KC_COMMA, KC_ENTER, KC_NO,
    // right thumb
    KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO
    ),

/* Layer 3: Diacritics and characters for languages with latin alphabet.
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
 *   | LAY2 |      |      |  `   |   _  |
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
 */
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
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

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
