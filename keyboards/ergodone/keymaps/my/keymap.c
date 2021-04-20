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

LEADER_EXTERNS();

void matrix_scan_user(void) {
  set_unicode_input_mode(UNICODE_SELECTED_MODES);

  uint8_t layer = biton32(layer_state);

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
      case 3:
          ergodox_right_led_3_on();
          break;
      default:
          // none
          break;
  }

  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
  }

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
      SEND_STRING("return ");
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
	[0] = LAYOUT_ergodox(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_F3, KC_SLSH, LGUI_T(KC_QUOT), LALT_T(KC_COMM), LCTL_T(KC_DOT), LSFT_T(KC_P), KC_Y, KC_LBRC, KC_TAB, KC_A, KC_O, KC_E, KC_I, KC_U, KC_ESC, LT(2,KC_SCLN), KC_Q, KC_J, KC_K, KC_X, KC_DLR, OSM(MOD_MEH), KC_NO, KC_NO, KC_LEAD, OSL(1), KC_HOME, KC_NO, KC_CAPS, KC_SFTENT, KC_DEL, KC_INS, KC_F5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_RBRC, KC_F, LSFT_T(KC_G), LCTL_T(KC_C), LALT_T(KC_R), LGUI_T(KC_L), KC_BSLS, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_EXLM, KC_B, KC_M, KC_W, KC_V, LT(2,KC_Z), KC_EQL, OSL(1), KC_LEAD, KC_NO, KC_NO, OSM(MOD_MEH), KC_PGUP, KC_END, KC_PGDN, KC_NO, KC_BSPC, LSFT_T(KC_SPC)),
	[1] = LAYOUT_ergodox(KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, VIM_YANK, KC_NO, KC_NO, KC_AT, KC_HASH, KC_LPRN, KC_PERC, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KENNER_DB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DM_REC1, DM_REC2, DM_PLY1, DM_RSTP, KC_DEL, DM_PLY2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, VIM_PASTE, KC_NO, PHP_ARROW, PHP_THIS, PHP_SELF, KC_NO, KC_NO, KC_CIRC, KC_RPRN, KC_ASTR, KC_AMPR, KC_NO, KC_NO, KENNER_CRM, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, HYPR(KC_SPC)),
	[2] = LAYOUT_ergodox(KC_SLEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_U, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN2, KC_BTN1, KC_WH_L, KC_WH_R, KC_WH_U, KC_BTN3, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_PPLS, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_ENT, KC_NO, KC_0, KC_ACL1, KC_DOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL2, KC_ACL0)
};

