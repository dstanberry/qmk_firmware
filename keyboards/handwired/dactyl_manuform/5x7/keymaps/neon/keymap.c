#include QMK_KEYBOARD_H

// layer Names
#define BASE 0
#define sFN  1
#define bFN  2
#define HW   3

// modifier mods
#define LCG_T(kc) MT(MOD_LCTL | MOD_LGUI, kc)

#define CAG_NOOP RCAG_T(XXXXXXX)
#define D_META   MAGIC_NO_GUI
#define E_META   MAGIC_UNNO_GUI
#define LC_LEFT  LCTL(KC_LEFT)
// #define LCA_NOOP LCA_T(XXXXXXX)
#define LCG_NOOP LCG_T(XXXXXXX)
#define LT_BFN   LT(bFN,KC_BSPC)
#define LT_SFN   LT(sFN,KC_SPC)
#define RC_RIGHT RCTL(KC_RIGHT)
#define RCS_NOOP RCS_T(XXXXXXX)
#define RSA_NOOP LSA_T(XXXXXXX)
#define TAB_L    LCTL(LSFT(KC_TAB))
#define TAB_R    LCTL(KC_TAB)

// alpha mods
#define GUI_SLSH RGUI_T(KC_SLSH)
#define RA_J     RALT_T(KC_J)
#define RC_SCLN  RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Qwerty (Default)
[BASE] = LAYOUT_5x7(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,MO(HW)  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_HOME ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_PGUP ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     SC_LSPO ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,
  //├────────┼────────┼────────┼────────┼────────┴────────┘
     LC_LEFT ,KC_LGUI ,TAB_L   ,LCG_NOOP,
  //└────────┴────────┴────────┴────────┘┌────────┬────────┬────────┐
  //                                      KC_LCTL, LT_BFN,  KC_DEL  ,
  //                                     ├────────┼────────┼────────┤
  //                                      KC_LALT ,KC_DOWN ,KC_UP   ,
  //                                     └────────┴────────┴────────┘
  /* PCB map on thumb cluster does not match QMK arrangement */
                                          KC_LALT ,KC_LCTL ,KC_DOWN ,
                                          LT_BFN  ,KC_UP   ,KC_DEL  ,
  // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      MO(HW)  ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_END  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_PGDN ,KC_H    ,RA_J    ,KC_K    ,KC_L    ,RC_SCLN ,KC_QUOT ,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
               KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,GUI_SLSH,SC_RSPC ,
  //          └────────┴────────┼────────┼────────┼────────┼────────┤
                                 CAG_NOOP,TAB_R   ,XXXXXXX ,RC_RIGHT,
  //┌────────┬────────┬────────┐└────────┴────────┴────────┴────────┘
  // KC_ENTER,LT_SFN,  RCS_NOOP,
  //├────────┼────────┼────────┤
  // KC_LEFT ,KC_RIGHT,RSA_NOOP
  //└────────┴────────┴────────┘
  /* PCB map on thumb cluster does not match QMK arrangement */
     RCS_NOOP,RSA_NOOP,LT_SFN,
     KC_RIGHT,KC_ENTER,KC_LEFT
),
  // SpaceFN
[sFN] = LAYOUT_5x7(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_EXLM ,KC_AT   ,KC_HASH ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_DLR  ,KC_PERC ,KC_CIRC ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     KC_TILD ,KC_AMPR ,KC_ASTR ,XXXXXXX ,KC_UNDS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┴────────┘
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────────┘┌────────┬────────┬────────┐
                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //                                     ├────────┼────────┼────────┤
                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //                                     └────────┴────────┴────────┘
  // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,KC_END  ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_F12  ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_COLN, XXXXXXX ,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
               XXXXXXX ,KC_PLUS ,XXXXXXX ,XXXXXXX ,KC_BSLS ,KC_PIPE ,
  //          └────────┴────────┼────────┼────────┼────────┼────────┤
                                 XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //┌────────┬────────┬────────┐└────────┴────────┴────────┴────────┘
     XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┘
),
  // BackspaceFN
[bFN] = LAYOUT_5x7(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LCBR ,KC_RCBR ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LBRC ,KC_RBRC ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     KC_TILD ,XXXXXXX ,XXXXXXX ,KC_LPRN ,KC_RPRN ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┴────────┘
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────────┘┌────────┬────────┬────────┐
                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //                                     ├────────┼────────┼────────┤
                                          _______ ,XXXXXXX ,XXXXXXX ,
  //                                     └────────┴────────┴────────┘
  // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,XXXXXXX ,KC_F12  ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,KC_PLUS ,XXXXXXX ,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
               XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_BSLS ,KC_PIPE ,
  //          └────────┴────────┼────────┼────────┼────────┼────────┤
                                 KC_DOT  ,KC_0    ,KC_EQUAL,XXXXXXX ,
  //┌────────┬────────┬────────┐└────────┴────────┴────────┴────────┘
     XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┘
),
  // Hardware
[HW] = LAYOUT_5x7(
  //┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┴────────┘
     E_META  ,D_META  ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────────┘┌────────┬────────┬────────┐
                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //                                     ├────────┼────────┼────────┤
                                          XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //                                     └────────┴────────┴────────┘
  // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
      _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  // └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
               XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //          └────────┴────────┼────────┼────────┼────────┼────────┤
                                 XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //┌────────┬────────┬────────┐└────────┴────────┴────────┴────────┘
     XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┘
)
};
