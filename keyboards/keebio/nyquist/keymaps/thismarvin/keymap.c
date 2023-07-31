#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _MINIMAL 1
#define _EXTEND 2
#define _LOWER 3
#define _RAISE 4
#define _SHORTCUT 5
#define _ADJUST 6

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EXTEND,
    LOWER,
    RAISE,
    SHRTCUT,
    ADJUST,
    OSM_CTL,
    OSM_GUI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Extend|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |      |      |      |Lower |Space | Bksp |Raise |      |      |      | Ctrl |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_5x12(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        EXTEND,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SHRTCUT, SHRTCUT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, LOWER,   KC_SPC,  KC_BSPC, RAISE,   XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL
    ),
    [_MINIMAL] =  LAYOUT_ortho_5x12(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
        EXTEND,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   KC_SPC,  KC_BSPC, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* Extend
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |Enter |      | Left | Down |  Up  |Right |      | Esc  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_EXTEND] = LAYOUT_ortho_5x12(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_ENT,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_ESC,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   {  |   }  |   _  |   =  |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   [  |   ]  |   -  |   +  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      | Lead |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_5x12(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        OSM_GUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_LEAD
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   `  |   ~  |   (  |   )  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_5x12(
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
        _______,  KC_GRV, KC_TILD, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        QK_LEAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OSM_GUI
    ),

    /* Shortcut
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_SHORTCUT] = LAYOUT_ortho_5x12(
        _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______,
        _______, _______, _______, _______, _______, _______, G(KC_D), G(KC_Y), G(KC_N), G(KC_M), _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_ortho_5x12(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        OSM_GUI, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______, OSM_GUI
    ),
};

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_LGUI("s"));

        return;
    }

    if (leader_sequence_two_keys(KC_R, KC_Q)) {
        SEND_STRING(
            SS_DOWN(X_LGUI)
            SS_DOWN(X_LSFT)
            SS_TAP(X_Q)
            SS_UP(X_LSFT)
            SS_UP(X_LGUI)
        );

        return;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS: {
            // Apply shift to next key.
            add_weak_mods(MOD_BIT(KC_LSFT));

            return true;
        }

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS: {
            return true;
        }

        // I had to hack this in for Workman to work...
        case KC_SCLN: {
            // Apply shift to next key.
            add_weak_mods(MOD_BIT(KC_LSFT));

            return true;
        }

        // Deactivate Caps Word.
        default: {
            return false;
        }
    }
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY: {
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _QWERTY);
            }

            return false;
        }
        case EXTEND: {
            if (record->event.pressed) {
                layer_on(_EXTEND);
            } else {
                layer_off(_EXTEND);
            }

            return false;
        }
        case LOWER: {
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }

            update_tri_layer(_LOWER, _RAISE, _ADJUST);

            return false;
        }
        case RAISE: {
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }

            update_tri_layer(_LOWER, _RAISE, _ADJUST);

            return false;
        }
        case SHRTCUT: {
            if (record->event.pressed) {
                layer_on(_SHORTCUT);
            } else {
                layer_off(_SHORTCUT);
            }

            return false;
        }
        case ADJUST: {
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }

            return false;
        }
        case OSM_CTL: {
            if (record->event.pressed) {
                set_oneshot_mods(MOD_BIT(KC_LCTL));
                layer_on(_MINIMAL);
            } else {
                layer_off(_MINIMAL);
            }

            return false;
        }
        case OSM_GUI: {
            if (record->event.pressed) {
                set_oneshot_mods(MOD_BIT(KC_LGUI));
                layer_on(_MINIMAL);
            } else {
                layer_off(_MINIMAL);
            }

            return false;
        }
    }

    return true;
}
