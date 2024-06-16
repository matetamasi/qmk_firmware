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

#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
};

enum preonic_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬────┬──────┬──────┬───────┬───┬───┬───────┬──────┬──────┬────┬───────┐
//    │  `   │ 1  │  2   │  3   │   4   │ 5 │ 6 │   7   │  8   │  9   │ 0  │ bspc  │
//    ├──────┼────┼──────┼──────┼───────┼───┼───┼───────┼──────┼──────┼────┼───────┤
//    │ tab  │ q  │  w   │  e   │   r   │ t │ y │   u   │  i   │  o   │ p  │ iso-- │
//    ├──────┼────┼──────┼──────┼───────┼───┼───┼───────┼──────┼──────┼────┼───────┤
//    │ esc  │ a  │  s   │  d   │   f   │ g │ h │   j   │  k   │  l   │ ;  │   '   │
//    ├──────┼────┼──────┼──────┼───────┼───┼───┼───────┼──────┼──────┼────┼───────┤
//    │ lsft │ z  │  x   │  c   │   v   │ b │ n │   m   │  ,   │  .   │ /  │  ent  │
//    ├──────┼────┼──────┼──────┼───────┼───┴───┼───────┼──────┼──────┼────┼───────┤
//    │ lctl │ FN │ lalt │ lgui │ LOWER │  spc  │ RAISE │ rsft │ ralt │ up │ rctl  │
//    └──────┴────┴──────┴──────┴───────┴───────┴───────┴──────┴──────┴────┴───────┘
[_QWERTY] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_1 , KC_2    , KC_3    , KC_4  , KC_5 , KC_6 , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_TAB  , KC_Q , KC_W    , KC_E    , KC_R  , KC_T , KC_Y , KC_U  , KC_I    , KC_O    , KC_P    , KC_NUHS,
  KC_ESC  , KC_A , KC_S    , KC_D    , KC_F  , KC_G , KC_H , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X    , KC_C    , KC_V  , KC_B , KC_N , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
  KC_LCTL , FN   , KC_LALT , KC_LGUI , LOWER ,   KC_SPC    , RAISE , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌──────┬────┬──────┬──────┬─────┬────┬────┬───────┬──────┬──────┬─────┬──────┐
//    │  `   │ f1 │  f2  │  f3  │ f4  │ f5 │ f6 │  f7   │  f8  │  f9  │ f10 │ bspc │
//    ├──────┼────┼──────┼──────┼─────┼────┼────┼───────┼──────┼──────┼─────┼──────┤
//    │ tab  │ !  │  @   │  #   │  $  │ %  │ ^  │   &   │  *   │  (   │  )  │  \   │
//    ├──────┼────┼──────┼──────┼─────┼────┼────┼───────┼──────┼──────┼─────┼──────┤
//    │ esc  │ 1  │  2   │  3   │  4  │ 5  │ 6  │   7   │  8   │  9   │  0  │  '   │
//    ├──────┼────┼──────┼──────┼─────┼────┼────┼───────┼──────┼──────┼─────┼──────┤
//    │ lsft │ _  │  -   │  +   │  =  │ no │ no │   !   │  ,   │  .   │  /  │ ent  │
//    ├──────┼────┼──────┼──────┼─────┼────┴────┼───────┼──────┼──────┼─────┼──────┤
//    │ lctl │ no │ lalt │ lgui │     │   spc   │ RAISE │ rsft │ ralt │ up  │ rctl │
//    └──────┴────┴──────┴──────┴─────┴─────────┴───────┴──────┴──────┴─────┴──────┘
[_LOWER] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_BSPC,
  KC_TAB  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSLS,
  KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_QUOT,
  KC_LSFT , KC_UNDS , KC_MINS , KC_PLUS , KC_EQL  , KC_NO   , KC_NO   , KC_EXLM , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
  KC_LCTL , KC_NO   , KC_LALT , KC_LGUI , KC_TRNS ,      KC_SPC       , RAISE   , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌──────┬──────┬──────┬──────┬───────┬────┬──────┬──────┬──────┬──────┬─────┬───────┐
//    │  `   │  no  │ kp_* │ kp_/ │   ^   │ no │  no  │  no  │  no  │  no  │ no  │ bspc  │
//    ├──────┼──────┼──────┼──────┼───────┼────┼──────┼──────┼──────┼──────┼─────┼───────┤
//    │ tab  │ kp_+ │  1   │  2   │   3   │ ,  │ pscr │ sCRL │ ins  │ paus │ del │ iso-- │
//    ├──────┼──────┼──────┼──────┼───────┼────┼──────┼──────┼──────┼──────┼─────┼───────┤
//    │ esc  │  =   │  4   │  5   │   6   │ 0  │ left │ down │  up  │ rght │  ;  │   '   │
//    ├──────┼──────┼──────┼──────┼───────┼────┼──────┼──────┼──────┼──────┼─────┼───────┤
//    │ lsft │ kp_- │  7   │  8   │   9   │ .  │ home │ pgdn │ pgup │ end  │  /  │  ent  │
//    ├──────┼──────┼──────┼──────┼───────┼────┴──────┼──────┼──────┼──────┼─────┼───────┤
//    │ lctl │  no  │ lalt │ lgui │ LOWER │    spc    │      │ rsft │ ralt │ up  │ rctl  │
//    └──────┴──────┴──────┴──────┴───────┴───────────┴──────┴──────┴──────┴─────┴───────┘
[_RAISE] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_NO   , KC_PAST , KC_PSLS , KC_CIRC , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_BSPC,
  KC_TAB  , KC_PPLS , KC_1    , KC_2    , KC_3    , KC_COMM , KC_PSCR , KC_SCRL , KC_INS  , KC_PAUS , KC_DEL  , KC_NUHS,
  KC_ESC  , KC_EQL  , KC_4    , KC_5    , KC_6    , KC_0    , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_PMNS , KC_7    , KC_8    , KC_9    , KC_DOT  , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_SLSH , KC_ENT ,
  KC_LCTL , KC_NO   , KC_LALT , KC_LGUI , LOWER   ,      KC_SPC       , KC_TRNS , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌──────┬────┬──────┬──────┬─────┬───┬───┬─────┬──────┬──────┬────┬──────┐
//    │  `   │ 1  │  2   │  3   │  4  │ 5 │ 6 │  7  │  8   │  9   │ 0  │ bspc │
//    ├──────┼────┼──────┼──────┼─────┼───┼───┼─────┼──────┼──────┼────┼──────┤
//    │ tab  │ +  │  -   │  *   │  /  │ % │ ^ │  i  │  j   │  k   │ l  │  #   │
//    ├──────┼────┼──────┼──────┼─────┼───┼───┼─────┼──────┼──────┼────┼──────┤
//    │ esc  │ (  │  )   │  [   │  ]  │ ! │ = │  {  │  }   │  <   │ >  │  $   │
//    ├──────┼────┼──────┼──────┼─────┼───┼───┼─────┼──────┼──────┼────┼──────┤
//    │ lsft │ a  │  b   │  c   │  d  │ & │ | │  q  │  w   │  x   │ y  │ ent  │
//    ├──────┼────┼──────┼──────┼─────┼───┴───┼─────┼──────┼──────┼────┼──────┤
//    │ lctl │ no │ lalt │ lgui │     │  spc  │     │ rsft │ ralt │ up │ rctl │
//    └──────┴────┴──────┴──────┴─────┴───────┴─────┴──────┴──────┴────┴──────┘
[_ADJUST] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0  , KC_BSPC,
  KC_TAB  , KC_PLUS , KC_MINS , KC_ASTR , KC_SLSH , KC_PERC , KC_CIRC , KC_I    , KC_J    , KC_K    , KC_L  , KC_HASH,
  KC_ESC  , KC_LPRN , KC_RPRN , KC_LBRC , KC_RBRC , KC_EXLM , KC_EQL  , KC_LCBR , KC_RCBR , KC_LT   , KC_GT , KC_DLR ,
  KC_LSFT , KC_A    , KC_B    , KC_C    , KC_D    , KC_AMPR , KC_PIPE , KC_Q    , KC_W    , KC_X    , KC_Y  , KC_ENT ,
  KC_LCTL , KC_NO   , KC_LALT , KC_LGUI , KC_TRNS ,      KC_SPC       , KC_TRNS , KC_RSFT , KC_RALT , KC_UP , KC_RCTL
),

//    ┌────┬─────┬─────┬─────┬─────┬─────────┬──────┬──────┬──────┬──────┬──────┬────┐
//    │ no │ f11 │ f12 │ f13 │ f14 │   f15   │ f16  │ f17  │ f18  │ f19  │ f20  │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┼──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │ no  │ no  │ no  │ no  │   no    │ mprv │  no  │  no  │ mnxt │ pscr │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┼──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │ no  │ no  │ no  │ no  │   no    │ bRID │ vold │ volu │ bRIU │  no  │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┼──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │ no  │ no  │ no  │ no  │ RGB_TOG │  no  │ mute │  no  │  no  │  no  │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┴──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │     │ no  │ no  │ no  │      mply      │  no  │  no  │  no  │  no  │ no │
//    └────┴─────┴─────┴─────┴─────┴────────────────┴──────┴──────┴──────┴──────┴────┘
[_FN] = LAYOUT_preonic_1x2uC(
  KC_NO , KC_F11  , KC_F12 , KC_F13 , KC_F14 , KC_F15  , KC_F16  , KC_F17  , KC_F18  , KC_F19  , KC_F20  , KC_NO,
  KC_NO , KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_MPRV , KC_NO   , KC_NO   , KC_MNXT , KC_PSCR , KC_NO,
  KC_NO , KC_NO   , KC_NO  , KC_NO  , KC_NO  , KC_NO   , KC_BRID , KC_VOLD , KC_VOLU , KC_BRIU , KC_NO   , KC_NO,
  KC_NO , KC_NO   , KC_NO  , KC_NO  , KC_NO  , RGB_TOG , KC_NO   , KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO,
  KC_NO , KC_TRNS , KC_NO  , KC_NO  , KC_NO  ,      KC_MPLY      , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case FN:
        if (record->event.pressed) {
                layer_on(_FN);
            } else {
                layer_off(_FN);
            }
            return false;
            break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};
