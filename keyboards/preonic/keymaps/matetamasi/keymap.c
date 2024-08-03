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
#include "keymap_hungarian.h"
#include QMK_KEYBOARD_H



enum preonic_layers {
    _QWERTY,
    _QWERTYHU,
    _ALTGR,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ALTGRHU,
    _LOWERHU,
    _RAISEHU,
    _ADJUSTHU,
    _FN
};

enum preonic_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    LOWERHU,
    RAISEHU,
    SW,
    US,
    HU,
    FN
};

enum hu_mode {
    SOFTWARE,
    US_FIRST,
    HU_FIRST
};


// Key defs to mimic US layout when OS language is HU
const key_override_t grave_override = ko_make_with_layers_negmods_and_options(
    MOD_MASK_SHIFT,
    HU_GRV,
    HU_TILD,
    (1 << _QWERTYHU),
    ~MOD_MASK_SHIFT,
    ko_option_activation_trigger_down
);

#define custom_shift_hu(original, shifted) \
    ko_make_with_layers_negmods_and_options( MOD_MASK_SHIFT, original, shifted, (1 << _QWERTYHU), ~MOD_MASK_SHIFT, ko_option_activation_trigger_down)

const key_override_t one_override = custom_shift_hu(HU_1, HU_EXLM);
const key_override_t two_override = custom_shift_hu(HU_2, HU_AT);
const key_override_t three_override = custom_shift_hu(HU_3, HU_HASH);
const key_override_t four_override = custom_shift_hu(HU_4, HU_DLR);
const key_override_t five_override = custom_shift_hu(HU_5, HU_PERC);
const key_override_t six_override = custom_shift_hu(HU_6, HU_CIRC);
const key_override_t seven_override = custom_shift_hu(HU_7, HU_AMPR);
const key_override_t eight_override = custom_shift_hu(HU_8, HU_ASTR);
const key_override_t nine_override = custom_shift_hu(HU_9, HU_LPRN);
const key_override_t zero_override = custom_shift_hu(HU_0, HU_RPRN);
const key_override_t backslash_override = custom_shift_hu(HU_BSLS, HU_PIPE);
const key_override_t semicolon_override = custom_shift_hu(HU_SCLN, HU_COLN);
const key_override_t quote_override = custom_shift_hu(HU_QUOT, HU_DQUO);
const key_override_t comma_override = custom_shift_hu(HU_COMM, HU_LABK);
const key_override_t dot_override = custom_shift_hu(HU_DOT, HU_RABK);
const key_override_t slash_override = custom_shift_hu(HU_SLSH, HU_QUES);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &grave_override,
    &one_override,
    &one_override,
    &two_override,
    &three_override,
    &four_override,
    &five_override,
    &six_override,
    &seven_override,
    &eight_override,
    &nine_override,
    &zero_override,
    &backslash_override,
    &semicolon_override,
    &quote_override,
    &comma_override,
    &dot_override,
    &slash_override,
    NULL
};

// Unicode keys for HU characters when OS language is US
enum unicode_names {
    U_AACU_LOWER,
    U_AACU_UPPER
};

const uint32_t unicode_map[] PROGMEM = {
    [U_AACU_LOWER] = 0x00e1,
    [U_AACU_UPPER] = 0x00c1
};

#define U_AACU UP(U_AACU_LOWER, U_AACU_UPPER)


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

//    ┌────────┬──────┬──────┬──────┬─────────┬──────┬──────┬─────────┬─────────┬────────┬─────────┬─────────┐
//    │ HU_GRV │ HU_1 │ HU_2 │ HU_3 │  HU_4   │ HU_5 │ HU_6 │  HU_7   │  HU_8   │  HU_9  │  HU_0   │  bspc   │
//    ├────────┼──────┼──────┼──────┼─────────┼──────┼──────┼─────────┼─────────┼────────┼─────────┼─────────┤
//    │  tab   │ HU_Q │ HU_W │ HU_E │  HU_R   │ HU_T │ HU_Y │  HU_U   │  HU_I   │  HU_O  │  HU_P   │ HU_BSLS │
//    ├────────┼──────┼──────┼──────┼─────────┼──────┼──────┼─────────┼─────────┼────────┼─────────┼─────────┤
//    │  esc   │ HU_A │ HU_S │ HU_D │  HU_F   │ HU_G │ HU_H │  HU_J   │  HU_K   │  HU_L  │ HU_SCLN │ HU_QUOT │
//    ├────────┼──────┼──────┼──────┼─────────┼──────┼──────┼─────────┼─────────┼────────┼─────────┼─────────┤
//    │  lsft  │ HU_Z │ HU_X │ HU_C │  HU_V   │ HU_B │ HU_N │  HU_M   │ HU_COMM │ HU_DOT │ HU_SLSH │   ent   │
//    ├────────┼──────┼──────┼──────┼─────────┼──────┴──────┼─────────┼─────────┼────────┼─────────┼─────────┤
//    │  lctl  │  FN  │ lalt │ lgui │ LOWERHU │     spc     │ RAISEHU │  rsft   │  ralt  │   up    │  rctl   │
//    └────────┴──────┴──────┴──────┴─────────┴─────────────┴─────────┴─────────┴────────┴─────────┴─────────┘
[_QWERTYHU] = LAYOUT_preonic_1x2uC(
  HU_GRV  , HU_1 , HU_2    , HU_3    , HU_4    , HU_5 , HU_6 , HU_7    , HU_8    , HU_9    , HU_0    , KC_BSPC,
  KC_TAB  , HU_Q , HU_W    , HU_E    , HU_R    , HU_T , HU_Y , HU_U    , HU_I    , HU_O    , HU_P    , HU_BSLS,
  KC_ESC  , HU_A , HU_S    , HU_D    , HU_F    , HU_G , HU_H , HU_J    , HU_K    , HU_L    , HU_SCLN , HU_QUOT,
  KC_LSFT , HU_Z , HU_X    , HU_C    , HU_V    , HU_B , HU_N , HU_M    , HU_COMM , HU_DOT  , HU_SLSH , KC_ENT ,
  KC_LCTL , FN   , KC_LALT , KC_LGUI , LOWERHU ,   KC_SPC    , RAISEHU , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌──────┬────────┬──────┬──────┬───────┬────┬────┬───────┬──────┬──────┬────┬───────┐
//    │  `   │   1    │  2   │  3   │   4   │ 5  │ 6  │   7   │  8   │  9   │ 0  │ bspc  │
//    ├──────┼────────┼──────┼──────┼───────┼────┼────┼───────┼──────┼──────┼────┼───────┤
//    │ tab  │   no   │  no  │  no  │  no   │ no │ no │  no   │  no  │  no  │ no │ iso-- │
//    ├──────┼────────┼──────┼──────┼───────┼────┼────┼───────┼──────┼──────┼────┼───────┤
//    │ esc  │ U_AACU │  no  │  no  │  no   │ no │ no │  no   │  no  │  no  │ ;  │   '   │
//    ├──────┼────────┼──────┼──────┼───────┼────┼────┼───────┼──────┼──────┼────┼───────┤
//    │ lsft │   no   │  no  │  no  │  no   │ no │ no │  no   │  ,   │  .   │ /  │  ent  │
//    ├──────┼────────┼──────┼──────┼───────┼────┴────┼───────┼──────┼──────┼────┼───────┤
//    │ lctl │   FN   │ lalt │ lgui │ LOWER │   spc   │ RAISE │ rsft │ ralt │ up │ rctl  │
//    └──────┴────────┴──────┴──────┴───────┴─────────┴───────┴──────┴──────┴────┴───────┘
[_ALTGR] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_1   , KC_2    , KC_3    , KC_4  , KC_5  , KC_6  , KC_7  , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_TAB  , KC_NO  , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NUHS,
  KC_ESC  , U_AACU , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_NO  , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
  KC_LCTL , FN     , KC_LALT , KC_LGUI , LOWER ,    KC_SPC     , RAISE , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌──────┬─────────┬──────┬─────────┬─────────┬───┬─────────┬─────────┬─────────┬─────────┬────┬───────┐
//    │  `   │    1    │  2   │    3    │    4    │ 5 │    6    │    7    │    8    │    9    │ 0  │ bspc  │
//    ├──────┼─────────┼──────┼─────────┼─────────┼───┼─────────┼─────────┼─────────┼─────────┼────┼───────┤
//    │ tab  │    q    │  w   │ HU_EACU │  HU_R   │ t │    y    │    u    │ HU_IACU │ HU_OACU │ p  │ iso-- │
//    ├──────┼─────────┼──────┼─────────┼─────────┼───┼─────────┼─────────┼─────────┼─────────┼────┼───────┤
//    │ esc  │ HU_AACU │  s   │    d    │    f    │ g │ HU_UDIA │ HU_UDAC │ HU_ODIA │ HU_ODAC │ ;  │   '   │
//    ├──────┼─────────┼──────┼─────────┼─────────┼───┼─────────┼─────────┼─────────┼─────────┼────┼───────┤
//    │ lsft │    z    │  x   │    c    │    v    │ b │    n    │    m    │    ,    │    .    │ /  │  ent  │
//    ├──────┼─────────┼──────┼─────────┼─────────┼───┴─────────┼─────────┼─────────┼─────────┼────┼───────┤
//    │ lctl │   FN    │ lalt │  lgui   │ LOWERHU │     spc     │ RAISEHU │  rsft   │  ralt   │ up │ rctl  │
//    └──────┴─────────┴──────┴─────────┴─────────┴─────────────┴─────────┴─────────┴─────────┴────┴───────┘
[_ALTGRHU] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC,
  KC_TAB  , KC_Q    , KC_W    , HU_EACU , HU_R    , KC_T , KC_Y    , KC_U    , HU_IACU , HU_OACU , KC_P    , KC_NUHS,
  KC_ESC  , HU_AACU , KC_S    , KC_D    , KC_F    , KC_G , HU_UDIA , HU_UDAC , HU_ODIA , HU_ODAC , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT ,
  KC_LCTL , FN      , KC_LALT , KC_LGUI , LOWERHU ,     KC_SPC     , RAISEHU , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
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

//    ┌────────┬─────────┬─────────┬─────────┬────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬──────┐
//    │ HU_GRV │   f1    │   f2    │   f3    │   f4   │   f5    │   f6    │   f7    │   f8    │   f9    │   f10   │ bspc │
//    ├────────┼─────────┼─────────┼─────────┼────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  tab   │ HU_EXLM │  HU_AT  │ HU_HASH │ HU_DLR │ HU_PERC │ HU_CIRC │ HU_AMPR │ HU_ASTR │ HU_LPRN │ HU_RPRN │  \   │
//    ├────────┼─────────┼─────────┼─────────┼────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  esc   │  HU_1   │  HU_2   │  HU_3   │  HU_4  │  HU_5   │  HU_6   │  HU_7   │  HU_8   │  HU_9   │  HU_0   │  '   │
//    ├────────┼─────────┼─────────┼─────────┼────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  lsft  │ HU_UNDS │ HU_MINS │ HU_PLUS │ HU_EQL │   no    │   no    │ HU_EXLM │ HU_COMM │ HU_DOT  │ HU_SLSH │ ent  │
//    ├────────┼─────────┼─────────┼─────────┼────────┼─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  lctl  │   no    │  lalt   │  lgui   │        │        spc        │ RAISEHU │  rsft   │  ralt   │   up    │ rctl │
//    └────────┴─────────┴─────────┴─────────┴────────┴───────────────────┴─────────┴─────────┴─────────┴─────────┴──────┘
[_LOWERHU] = LAYOUT_preonic_1x2uC(
  HU_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_BSPC,
  KC_TAB  , HU_EXLM , HU_AT   , HU_HASH , HU_DLR  , HU_PERC , HU_CIRC , HU_AMPR , HU_ASTR , HU_LPRN , HU_RPRN , KC_BSLS,
  KC_ESC  , HU_1    , HU_2    , HU_3    , HU_4    , HU_5    , HU_6    , HU_7    , HU_8    , HU_9    , HU_0    , KC_QUOT,
  KC_LSFT , HU_UNDS , HU_MINS , HU_PLUS , HU_EQL  , KC_NO   , KC_NO   , HU_EXLM , HU_COMM , HU_DOT  , HU_SLSH , KC_ENT ,
  KC_LCTL , KC_NO   , KC_LALT , KC_LGUI , KC_TRNS ,      KC_SPC       , RAISEHU , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌──────┬────────┬──────┬──────┬─────────┬─────────┬──────┬──────┬──────┬──────┬─────────┬─────────┐
//    │  `   │   no   │ kp_* │ kp_/ │ HU_CIRC │   no    │  no  │  no  │  no  │  no  │   no    │  bspc   │
//    ├──────┼────────┼──────┼──────┼─────────┼─────────┼──────┼──────┼──────┼──────┼─────────┼─────────┤
//    │ tab  │  kp_+  │ HU_1 │ HU_2 │  HU_3   │ HU_COMM │ pscr │ sCRL │ ins  │ paus │   del   │ HU_BSLS │
//    ├──────┼────────┼──────┼──────┼─────────┼─────────┼──────┼──────┼──────┼──────┼─────────┼─────────┤
//    │ esc  │ HU_EQL │ HU_4 │ HU_5 │  HU_6   │  HU_0   │ left │ down │  up  │ rght │ HU_SCLN │ HU_QUOT │
//    ├──────┼────────┼──────┼──────┼─────────┼─────────┼──────┼──────┼──────┼──────┼─────────┼─────────┤
//    │ lsft │  kp_-  │ HU_7 │ HU_8 │  HU_9   │ HU_DOT  │ home │ pgdn │ pgup │ end  │ HU_SLSH │   ent   │
//    ├──────┼────────┼──────┼──────┼─────────┼─────────┴──────┼──────┼──────┼──────┼─────────┼─────────┤
//    │ lctl │   no   │ lalt │ lgui │ LOWERHU │      spc       │      │ rsft │ ralt │   up    │  rctl   │
//    └──────┴────────┴──────┴──────┴─────────┴────────────────┴──────┴──────┴──────┴─────────┴─────────┘
[_RAISEHU] = LAYOUT_preonic_1x2uC(
  KC_GRV  , KC_NO   , KC_PAST , KC_PSLS , HU_CIRC , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_BSPC,
  KC_TAB  , KC_PPLS , HU_1    , HU_2    , HU_3    , HU_COMM , KC_PSCR , KC_SCRL , KC_INS  , KC_PAUS , KC_DEL  , HU_BSLS,
  KC_ESC  , HU_EQL  , HU_4    , HU_5    , HU_6    , HU_0    , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , HU_SCLN , HU_QUOT,
  KC_LSFT , KC_PMNS , HU_7    , HU_8    , HU_9    , HU_DOT  , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , HU_SLSH , KC_ENT ,
  KC_LCTL , KC_NO   , KC_LALT , KC_LGUI , LOWERHU ,      KC_SPC       , KC_TRNS , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬──────┐
//    │ HU_GRV │  HU_1   │  HU_2   │  HU_3   │  HU_4   │  HU_5   │  HU_6   │  HU_7   │  HU_8   │  HU_9   │  HU_0   │ bspc │
//    ├────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  tab   │ HU_PLUS │ HU_MINS │ HU_ASTR │ HU_SLSH │ HU_PERC │ HU_CIRC │  HU_I   │  HU_J   │  HU_K   │  HU_L   │  #   │
//    ├────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  esc   │ HU_LPRN │ HU_RPRN │ HU_LBRC │ HU_RBRC │ HU_EXLM │ HU_EQL  │ HU_LCBR │ HU_RCBR │ HU_LABK │ HU_RABK │  $   │
//    ├────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  lsft  │  HU_A   │  HU_B   │  HU_C   │  HU_D   │ HU_AMPR │ HU_PIPE │  HU_Q   │  HU_W   │  HU_X   │  HU_Y   │ ent  │
//    ├────────┼─────────┼─────────┼─────────┼─────────┼─────────┴─────────┼─────────┼─────────┼─────────┼─────────┼──────┤
//    │  lctl  │   no    │  lalt   │  lgui   │         │        spc        │         │  rsft   │  ralt   │   up    │ rctl │
//    └────────┴─────────┴─────────┴─────────┴─────────┴───────────────────┴─────────┴─────────┴─────────┴─────────┴──────┘
[_ADJUSTHU] = LAYOUT_preonic_1x2uC(
  HU_GRV  , HU_1    , HU_2    , HU_3    , HU_4    , HU_5    , HU_6    , HU_7    , HU_8    , HU_9    , HU_0    , KC_BSPC,
  KC_TAB  , HU_PLUS , HU_MINS , HU_ASTR , HU_SLSH , HU_PERC , HU_CIRC , HU_I    , HU_J    , HU_K    , HU_L    , KC_HASH,
  KC_ESC  , HU_LPRN , HU_RPRN , HU_LBRC , HU_RBRC , HU_EXLM , HU_EQL  , HU_LCBR , HU_RCBR , HU_LABK , HU_RABK , KC_DLR ,
  KC_LSFT , HU_A    , HU_B    , HU_C    , HU_D    , HU_AMPR , HU_PIPE , HU_Q    , HU_W    , HU_X    , HU_Y    , KC_ENT ,
  KC_LCTL , KC_NO   , KC_LALT , KC_LGUI , KC_TRNS ,      KC_SPC       , KC_TRNS , KC_RSFT , KC_RALT , KC_UP   , KC_RCTL
),

//    ┌────┬─────┬─────┬─────┬─────┬─────────┬──────┬──────┬──────┬──────┬──────┬────┐
//    │ no │ f11 │ f12 │ f13 │ f14 │   f15   │ f16  │ f17  │ f18  │ f19  │ f20  │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┼──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │ no  │ no  │ US  │ no  │   no    │ mprv │  no  │  no  │ mnxt │ pscr │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┼──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │ no  │ SW  │ HU  │ no  │   no    │ bRID │ vold │ volu │ bRIU │  no  │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┼──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │ no  │ no  │ no  │ no  │ RGB_TOG │  no  │ mute │  no  │  no  │  no  │ no │
//    ├────┼─────┼─────┼─────┼─────┼─────────┴──────┼──────┼──────┼──────┼──────┼────┤
//    │ no │     │ no  │ no  │ no  │      mply      │  no  │  no  │  no  │  no  │ no │
//    └────┴─────┴─────┴─────┴─────┴────────────────┴──────┴──────┴──────┴──────┴────┘
[_FN] = LAYOUT_preonic_1x2uC(
  KC_NO , KC_F11  , KC_F12 , KC_F13 , KC_F14 , KC_F15  , KC_F16  , KC_F17  , KC_F18  , KC_F19  , KC_F20  , KC_NO,
  KC_NO , KC_NO   , KC_NO  , US     , KC_NO  , KC_NO   , KC_MPRV , KC_NO   , KC_NO   , KC_MNXT , KC_PSCR , KC_NO,
  KC_NO , KC_NO   , SW     , HU     , KC_NO  , KC_NO   , KC_BRID , KC_VOLD , KC_VOLU , KC_BRIU , KC_NO   , KC_NO,
  KC_NO , KC_NO   , KC_NO  , KC_NO  , KC_NO  , RGB_TOG , KC_NO   , KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO,
  KC_NO , KC_TRNS , KC_NO  , KC_NO  , KC_NO  ,      KC_MPLY      , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO
)
};

enum hu_mode hu_mode = SOFTWARE;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case SW:
            set_single_persistent_default_layer(_QWERTY);
            hu_mode = SOFTWARE;
            return false;
            break;
        case US:
            set_single_persistent_default_layer(_QWERTY);
            hu_mode = US_FIRST;
            return false;
            break;
        case HU:
            set_single_persistent_default_layer(_QWERTYHU);
            hu_mode = HU_FIRST;
            return false;
            break;
        case KC_RALT:
            if (hu_mode == US_FIRST) {
                if (record->event.pressed) {
                    layer_on(_ALTGR);
                } else {
                    layer_off(_ALTGR);
                }
                return false;
                break;
            } else if (hu_mode == HU_FIRST) {
                if (record->event.pressed) {
                    layer_on(_ALTGRHU);
                } else {
                    layer_off(_ALTGRHU);
                }
                return false;
                break;
            } else if (hu_mode == SOFTWARE) {
                return true;
                break;
            }
            // Should never be reached
            rgblight_toggle();
            return false;
            break;
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
        case LOWERHU:
          if (record->event.pressed) {
            layer_on(_LOWERHU);
            update_tri_layer(_LOWERHU, _RAISEHU, _ADJUSTHU);
          } else {
            layer_off(_LOWERHU);
            update_tri_layer(_LOWERHU, _RAISEHU, _ADJUSTHU);
          }
          return false;
          break;
        case RAISEHU:
          if (record->event.pressed) {
            layer_on(_RAISEHU);
            update_tri_layer(_LOWERHU, _RAISEHU, _ADJUSTHU);
          } else {
            layer_off(_RAISEHU);
            update_tri_layer(_LOWERHU, _RAISEHU, _ADJUSTHU);
          }
          return false;
          break;
      }
    return true;
};
