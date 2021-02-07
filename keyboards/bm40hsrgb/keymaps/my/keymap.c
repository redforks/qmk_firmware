#include QMK_KEYBOARD_H

enum custom_keycodes {
    VIM_YANK = SAFE_RANGE,
    VIM_PASTE,
    PHP_THIS,
    PHP_SELF,
    PHP_ARROW,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VIM_YANK:
        if (record->event.pressed) {
            SEND_STRING("\"+y");
        }
        break;

    case VIM_PASTE:
        if (record->event.pressed) {
            SEND_STRING("\"+p");
        }
        break;

    case PHP_THIS:
        if (record->event.pressed) {
            SEND_STRING("$this->");
        }
        break;

    case PHP_SELF:
        if (record->event.pressed) {
            SEND_STRING("self::");
        }
        break;

    case PHP_ARROW:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        break;

    }
    return true;
};


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit(KC_SLSH, LT(5,KC_QUOT), KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, KC_TAB, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I, KC_D, RSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S), KC_MINS, KC_ESC, LT(6,KC_SCLN), KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT, MO(4), KC_NO, KC_NO, KC_NO, OSL(2), LT(1,KC_SPC), OSL(2), KC_NO, KC_NO, KC_NO, MO(3)),
	[1] = LAYOUT_planck_mit(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_EQL, KC_BSLS, KC_PLUS, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[2] = LAYOUT_planck_mit(KC_LALT, KC_F1, KC_F2, KC_F3, KC_F4, PHP_SELF, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, KC_RCTL, KC_F5, KC_F6, KC_F7, KC_F8, PHP_THIS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_RSFT, KC_F9, KC_F10, KC_F11, KC_F12, PHP_ARROW, KC_NO, VIM_YANK, VIM_PASTE, KC_DEL, KC_INS, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_RCTL),
	[3] = LAYOUT_planck_mit(SGUI(KC_Q), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), LGUI(KC_D), KC_NO, SGUI(KC_1), SGUI(KC_2), SGUI(KC_3), SGUI(KC_4), SGUI(KC_5), SGUI(KC_6), SGUI(KC_7), SGUI(KC_8), SGUI(KC_9), SGUI(KC_0), LGUI(KC_MINS), KC_LSFT, LGUI(KC_F1), LGUI(KC_F2), LGUI(KC_F3), KC_NO, KC_NO, KC_NO, SGUI(KC_LEFT), SGUI(KC_RGHT), SGUI(KC_UP), SGUI(KC_DOWN), KC_ENT, KC_NO, KC_NO, LGUI(KC_W), LGUI(KC_E), KC_NO, KC_NO, LGUI(KC_LEFT), LGUI(KC_RGHT), LGUI(KC_UP), LGUI(KC_DOWN), KC_NO),
	[4] = LAYOUT_planck_mit(LALT(KC_GRV), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), LALT(KC_F12), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_F7), LCA(KC_T), KC_NO, KC_NO, LALT(KC_ENT), KC_RSFT, KC_NO, KC_NO, LCA(KC_J), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, HYPR(KC_F10), KC_NO, KC_NO, KC_NO, KC_NO, LCA(KC_INS), HYPR(KC_SPC), LALT(KC_INS), KC_NO, KC_NO, HYPR(KC_F5), KC_F5),
	[5] = LAYOUT_planck_mit(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[6] = LAYOUT_planck_mit(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_MINS, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_ASTR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_NO, KC_DOT, KC_SLSH, KC_PENT)
};

