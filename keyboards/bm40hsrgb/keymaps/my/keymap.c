#include QMK_KEYBOARD_H

enum custom_keycodes {
    VIM_YANK = SAFE_RANGE,
    VIM_PASTE,
    PHP_THIS,
    PHP_SELF,
    PHP_ARROW,
    KENNER_DB,
    KENNER_CRM
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

    case KENNER_DB:
        if (record->event.pressed) {
            SEND_STRING("Kenner@root123");
        }
        break;

    case KENNER_CRM:
        if (record->event.pressed) {
            SEND_STRING("/home/tomcat/apache-tomcat-8.0.43/webapps/crm/");
        }
        break;

    }
    return true;
};

#define MY_HSV_WHITE 0, 0, 255
#define MY_HSV_RED 0, 255, 255
#define MY_HSV_CORAL 11, 176, 255
#define MY_HSV_ORANGE 28, 255, 255
#define MY_HSV_GOLDENROD 30, 218, 64
#define MY_HSV_GOLD 36, 255, 72
#define MY_HSV_YELLOW 43, 255, 72
#define MY_HSV_CHARTREUSE 64, 255, 255
#define MY_HSV_GREEN 85, 255, 127
#define MY_HSV_SPRINGGREEN 106, 255, 255
#define MY_HSV_TURQUOISE 123, 90, 112
#define MY_HSV_TEAL 128, 255, 128
#define MY_HSV_CYAN 128, 255, 255
#define MY_HSV_AZURE 132, 102, 255
#define MY_HSV_BLUE 170, 255, 255
#define MY_HSV_PURPLE 191, 255, 255
#define MY_HSV_MAGENTA 213, 255, 255
#define MY_HSV_PINK 234, 128, 255

const rgblight_segment_t PROGMEM cap_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {44, 1, MY_HSV_AZURE}
);

const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 4, MY_HSV_GREEN},
    {19, 4, MY_HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, MY_HSV_GOLDENROD},
    {13, 10, MY_HSV_GOLD}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 1, HSV_OFF}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 1, HSV_OFF}
);

const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 4, HSV_OFF},
    {19, 4, HSV_OFF},
    {23, 1, HSV_RED},
    {41, 1, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 3, MY_HSV_GREEN},
    {13, 4, HSV_OFF},
    {19, 3, MY_HSV_GREEN},
    {22, 1, HSV_OFF},
    {31, 3, MY_HSV_GREEN},
    {42, 1, MY_HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer3_layer,
    my_layer5_layer,
    my_layer6_layer,
    cap_lock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(7, led_state.caps_lock);
    return true;
}
 
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    return state;
}

// Tap Dance declarations
enum {
    TD_SLASH,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SLASH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  set_unicode_input_mode(UNICODE_SELECTED_MODES);

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_E, KC_E) {
      SEND_STRING(SS_TAP(X_END));
    }
    SEQ_TWO_KEYS(KC_E, KC_H) {
      SEND_STRING(SS_TAP(X_HOME));
    }

    SEQ_TWO_KEYS(KC_G, KC_S) {
      SEND_STRING("git flow feature start ");
    }
    SEQ_TWO_KEYS(KC_G, KC_F) {
      SEND_STRING("git flow finish");
    }
    SEQ_TWO_KEYS(KC_G, KC_P) {
      SEND_STRING("git push");
    }

    SEQ_TWO_KEYS(KC_D, KC_U) {
      SEND_STRING("docker-compose up -d mysql redis beanstalkd crm crm_sidekick");
    }
    SEQ_TWO_KEYS(KC_D, KC_R) {
      SEND_STRING("docker-compose restart crm");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING("docker-compose down");
    }
    SEQ_TWO_KEYS(KC_D, KC_E) {
      SEND_STRING("docker-compose exec crm_sidekick bash");
    }
   
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("string ");
    }
    SEQ_TWO_KEYS(KC_S, KC_S) {
      SEND_STRING("ssh kenner");
    }

    SEQ_ONE_KEY(KC_P) {
      SEND_STRING("private ");
    }
    SEQ_TWO_KEYS(KC_P, KC_P) {
      SEND_STRING("public ");
    }
    SEQ_THREE_KEYS(KC_P, KC_P, KC_P) {
      SEND_STRING("protected ");
    }

    SEQ_ONE_KEY(KC_I) {
      SEND_STRING("Interface");
    }
    SEQ_TWO_KEYS(KC_I, KC_I) {
      SEND_STRING("interface");
    }

    SEQ_TWO_KEYS(KC_O, KC_P) {
      SEND_STRING("@param ");
    }
    SEQ_TWO_KEYS(KC_O, KC_R) {
      SEND_STRING("@return ");
    }
    SEQ_TWO_KEYS(KC_O, KC_I) {
      SEND_STRING("@implements ");
    }
    SEQ_TWO_KEYS(KC_O, KC_E) {
      SEND_STRING("@extends ");
    }
    SEQ_TWO_KEYS(KC_O, KC_T) {
      SEND_STRING("@template T");
    }

    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("function ");
    }
    SEQ_ONE_KEY(KC_R) {
      SEND_STRING("return");
    }

    SEQ_ONE_KEY(KC_A) {
      SEND_STRING("array $");
    }

    SEQ_ONE_KEY(KC_C) {
      SEND_STRING("create");
    }

    SEQ_ONE_KEY(KC_N) {
      SEND_STRING("new ");
    }
    SEQ_TWO_KEYS(KC_N, KC_N) {
      unicode_input_start();
      send_unicode_string("好的");
      unicode_input_finish();
    }
    SEQ_TWO_KEYS(KC_N, KC_W) {
      unicode_input_start();
      send_unicode_string("我看看，稍等");
      unicode_input_finish();
    }
    SEQ_TWO_KEYS(KC_N, KC_D) {
      unicode_input_start();
      send_unicode_string("处理了，麻烦再试试");
      unicode_input_finish();
    }
  }
}

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_mit(TD(TD_SLASH), LT(5,KC_QUOT), KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, KC_TAB, LGUI_T(KC_A), LALT_T(KC_O), LCTL_T(KC_E), LSFT_T(KC_U), KC_I, KC_D, RSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S), KC_MINS, KC_ESC, LT(6,KC_SCLN), KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT, MO(4), KC_NO, KC_NO, KC_LEAD, MO(2), LT(1,KC_SPC), MO(2), KC_NO, KC_CAPS, KC_NO, MO(3)),
	[1] = LAYOUT_planck_mit(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_RCBR, KC_LCBR, KC_RBRC, KC_LBRC, KC_EQL, KC_BSLS, KC_PLUS, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[2] = LAYOUT_planck_mit(KC_LALT, KC_F1, KC_F2, KC_F3, KC_F4, PHP_SELF, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_WH_U, KC_NO, KC_RCTL, KC_F5, KC_F6, KC_F7, KC_F8, PHP_THIS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_WH_D, KC_NO, KC_RSFT, KC_F9, KC_F10, KC_F11, KC_F12, PHP_ARROW, KENNER_DB, VIM_YANK, VIM_PASTE, KC_DEL, KC_INS, KC_RSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KENNER_CRM, KC_RCTL),
	[3] = LAYOUT_planck_mit(SGUI(KC_Q), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), LGUI(KC_D), KC_NO, SGUI(KC_1), SGUI(KC_2), SGUI(KC_3), SGUI(KC_4), SGUI(KC_5), SGUI(KC_6), SGUI(KC_7), SGUI(KC_8), SGUI(KC_9), SGUI(KC_0), LGUI(KC_MINS), KC_LSFT, LGUI(KC_F1), LGUI(KC_F2), LGUI(KC_F3), KC_NO, KC_NO, KC_NO, SGUI(KC_LEFT), SGUI(KC_RGHT), SGUI(KC_UP), SGUI(KC_DOWN), KC_ENT, KC_NO, KC_NO, LGUI(KC_W), LGUI(KC_E), KC_NO, KC_NO, LGUI(KC_LEFT), LGUI(KC_RGHT), LGUI(KC_UP), LGUI(KC_DOWN), KC_NO),
	[4] = LAYOUT_planck_mit(LALT(KC_GRV), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), LALT(KC_F12), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_F7), LCA(KC_T), KC_NO, KC_NO, LALT(KC_ENT), KC_RSFT, KC_NO, KC_NO, LCA(KC_J), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, HYPR(KC_F10), KC_NO, KC_NO, KC_NO, KC_NO, LCA(KC_INS), HYPR(KC_SPC), LALT(KC_INS), KC_NO, KC_NO, HYPR(KC_F5), KC_F5),
	[5] = LAYOUT_planck_mit(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLEP, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU),
	[6] = LAYOUT_planck_mit(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_MINS, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_PLUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_ASTR, KC_PENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_NO, KC_DOT, KC_SLSH, KC_NO)
};

