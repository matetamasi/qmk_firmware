/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//#include <math.h>
#include "sm_td.h"
#include QMK_KEYBOARD_H



enum preonic_layers {
    _QWERTY,
};

enum preonic_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A,
    SMTD_KEYCODES_END,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬────┬──────┬──────┬────┬───┬───┬────┬──────┬──────┬────┬───────┐
//    │  `   │ 1  │  2   │  3   │ 4  │ 5 │ 6 │ 7  │  8   │  9   │ 0  │ bspc  │
//    ├──────┼────┼──────┼──────┼────┼───┼───┼────┼──────┼──────┼────┼───────┤
//    │ tab  │ q  │  w   │  e   │ r  │ t │ y │ u  │  i   │  o   │ p  │ iso-- │
//    ├──────┼────┼──────┼──────┼────┼───┼───┼────┼──────┼──────┼────┼───────┤
//    │ esc  │ Ca │  s   │  d   │ f  │ g │ h │ j  │  k   │  l   │ ;  │   '   │
//    ├──────┼────┼──────┼──────┼────┼───┼───┼────┼──────┼──────┼────┼───────┤
//    │ lsft │ z  │  x   │  c   │ v  │ b │ n │ m  │  ,   │  .   │ /  │  ent  │
//    ├──────┼────┼──────┼──────┼────┼───┴───┼────┼──────┼──────┼────┼───────┤
//    │ lctl │ no │ lalt │ lgui │ no │  spc  │ no │ rsft │ ralt │ up │ rctl  │
//    └──────┴────┴──────┴──────┴────┴───────┴────┴──────┴──────┴────┴───────┘
[_QWERTY] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_1  , KC_2    , KC_3    , KC_4  , KC_5 , KC_6 , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_TAB  , KC_Q  , KC_W    , KC_E    , KC_R  , KC_T , KC_Y , KC_U  , KC_I    , KC_O    , KC_P    , KC_NUHS,
  KC_ESC  , CKC_A , KC_S    , KC_D    , KC_F  , KC_G , KC_H , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z  , KC_X    , KC_C    , KC_V  , KC_B , KC_N , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
  KC_LCTL , KC_NO , KC_LALT , KC_LGUI , KC_NO ,   KC_SPC    , KC_NO , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
)
};

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_CTRL);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_smtd(keycode, record)) {
    return false;
  }
    return true;
};
