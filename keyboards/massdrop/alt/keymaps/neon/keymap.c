#include "keycode.h"
#include QMK_KEYBOARD_H

enum alt_keycodes {
  L_BRI = SAFE_RANGE,  // LED Brightness Increase                                   //Working
  L_BRD,               // LED Brightness Decrease                                   //Working
  L_PTN,               // LED Pattern Select Next                                   //Working
  L_PTP,               // LED Pattern Select Previous                               //Working
  L_PSI,               // LED Pattern Speed Increase                                //Working
  L_PSD,               // LED Pattern Speed Decrease                                //Working
  L_T_MD,              // LED Toggle Mode                                           //Working
  L_T_ONF,             // LED Toggle On / Off                                       //Broken
  L_ON,                // LED On                                                    //Broken
  L_OFF,               // LED Off                                                   //Broken
  L_T_BR,              // LED Toggle Breath Effect                                  //Working
  L_T_PTD,             // LED Toggle Scrolling Pattern Direction                    //Working
  U_T_AGCR,            // USB Toggle Automatic GCR control                          //Working
  DBG_TOG,             // DEBUG Toggle On / Off                                     //
  DBG_MTRX,            // DEBUG Toggle Matrix Prints                                //
  DBG_KBD,             // DEBUG Toggle Keyboard Prints                              //
  DBG_MOU,             // DEBUG Toggle Mouse Prints                                 //
  MD_BOOT              // Restart into bootloader after hold timeout                //Working
};

keymap_config_t keymap_config;

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
// #define TAB_L    LCTL(LSFT(KC_TAB))
// #define TAB_R    LCTL(KC_TAB)

// alpha mods
#define GUI_SLSH RGUI_T(KC_SLSH)
#define LCTL_A   LCTL_T(KC_A)
#define LALT_F   LALT_T(KC_F)
#define RA_J     RALT_T(KC_J)
#define RC_SCLN  RCTL_T(KC_SCLN)

// layer Names
#define BASE 0
#define sFN  1
#define FN   2
#define GAME 3
#define MIDI 4
#define LOCK 5
#define HW   6

// keymap | layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Qwerty (Default)
  [BASE] = LAYOUT_65_ansi_blocker(
  // ┌───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬───────────┬────────┐
      KC_GRV ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS,KC_EQUAL,KC_BSPACE  ,KC_HOME ,
  // ├───────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬─────────┼────────┤
      KC_TAB   ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,KC_RBRC ,KC_BSLASH,KC_PGUP ,
  // ├─────────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬─────────────────┼────────┤
      KC_ESC    ,LCTL_A  ,KC_S    ,KC_D    ,LALT_F  ,KC_G    ,KC_H    ,RA_J    ,KC_K    ,KC_L    ,RC_SCLN ,KC_QUOTE,KC_ENTER         ,KC_PGDN ,
  // ├──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┬────────┼────────┤
      KC_LSPO       ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,GUI_SLSH,KC_RSPC      ,KC_UP   ,KC_END  ,
  // ├────────┬─────┴──┬─────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
      LC_LEFT ,KC_LGUI ,RC_RIGHT,                            LT_SFN                              ,CAG_NOOP,TG(FN)  ,KC_LEFT ,KC_DOWN ,KC_RIGHT
  // └────────┴────────┴────────┴────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),
  // SpaceFN
  [sFN] = LAYOUT(
  // ┌───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬───────────┬────────┐
      XXXXXXX,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX    ,XXXXXXX ,
  // ├───────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬─────────┼────────┤
      XXXXXXX  ,KC_EXLM ,KC_AT   ,KC_HASH ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_HOME ,KC_END  ,KC_PGUP ,KC_PGDN ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,
  // ├─────────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬─────────────────┼────────┤
      KC_CAPS   ,KC_DLR  ,KC_PERC ,KC_CIRC ,KC_BSPC ,KC_DEL  ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,XXXXXXX          ,XXXXXXX ,
  // ├──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┬────────┼────────┤
      KC_TILD       ,KC_AMPR ,KC_ASTR ,XXXXXXX ,KC_LCBR ,XXXXXXX ,KC_RCBR ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_GRAVE     ,XXXXXXX ,XXXXXXX ,
  // ├────────┬─────┴──┬─────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
      E_META  ,D_META  ,XXXXXXX ,                            _______                             ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  // └────────┴────────┴────────┴────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),
  // FN Layers
  [FN] = LAYOUT(
  // ┌───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬───────────┬────────┐
      _______,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______    ,MO(HW)  ,
  // ├───────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬─────────┼────────┤
      _______  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______  ,TG(GAME),
  // ├─────────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬─────────────────┼────────┤
      _______   ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______          ,TG(MIDI),
  // ├──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┬────────┼────────┤
      _______       ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______      ,_______ ,TT(LOCK),
  // ├────────┬─────┴──┬─────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
      _______ ,_______ ,_______ ,                            _______                             ,_______ ,_______ ,_______ ,_______ ,_______
  // └────────┴────────┴────────┴────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),
  // Game
  [GAME] = LAYOUT_65_ansi_blocker(
  // ┌───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬───────────┬────────┐
      KC_ESC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINUS,KC_EQUAL,KC_BSPACE  ,KC_HOME ,
  // ├───────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬─────────┼────────┤
      KC_TAB   ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,KC_RBRC ,KC_BSLS  ,_______ ,
  // ├─────────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬─────────────────┼────────┤
      KC_CAPS   ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,KC_ENT           ,KC_PGDN ,
  // ├──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┬────────┼────────┤
      KC_LSFT       ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT      ,KC_UP   ,KC_END  ,
  // ├────────┬─────┴──┬─────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
      KC_LCTL ,XXXXXXX ,KC_LALT ,                              KC_SPC                            ,KC_RALT ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RIGHT
  // └────────┴────────┴────────┴────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),
  // Media
  [MIDI] = LAYOUT_65_ansi_blocker(
  // ┌───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬───────────┬────────┐
      KC_ESC ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX    ,XXXXXXX ,
  // ├───────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬─────────┼────────┤
      XXXXXXX  ,XXXXXXX ,XXXXXXX ,KC_EJCT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MPLY ,XXXXXXX ,XXXXXXX ,KC_BSLS  ,XXXXXXX ,
  // ├─────────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬─────────────────┼────────┤
      XXXXXXX   ,XXXXXXX ,KC_MSTP ,XXXXXXX ,KC_F    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_ENT           ,_______ ,
  // ├──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┬────────┼────────┤
      XXXXXXX       ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MNXT ,KC_MUTE ,KC_MPRV ,KC_MNXT ,XXXXXXX ,XXXXXXX      ,KC_VOLU ,KC_MUTE ,
  // ├────────┬─────┴──┬─────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,                             KC_MPLY                            ,XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_VOLD ,KC_MNXT
  // └────────┴────────┴────────┴────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),
  // Locked
  [LOCK] = LAYOUT(
  // ┌───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬───────────┬────────┐
      XXXXXXX,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX    ,XXXXXXX ,
  // ├───────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬─────────┼────────┤
      XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,
  // ├─────────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬─────────────────┼────────┤
      XXXXXXX   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX          ,XXXXXXX ,
  // ├──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┬────────┼────────┤
      XXXXXXX       ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX      ,XXXXXXX ,_______ ,
  // ├────────┬─────┴──┬─────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,                            XXXXXXX                             ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  // └────────┴────────┴────────┴────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┴────────┘
  ),
  // Hardware
  [HW] = LAYOUT(
  // ┌───────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬───────────┬────────┐
      XXXXXXX,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,L_BRD   ,L_BRI   ,XXXXXXX    ,_______ ,
  // ├───────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬─────────┼────────┤
      XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,
  // ├─────────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬───────┴┬─────────────────┼────────┤
      XXXXXXX   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX          ,XXXXXXX ,
  // ├──────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┬────────┼────────┤
      XXXXXXX       ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,MD_BOOT ,NK_TOGG ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX      ,KC_ASUP ,XXXXXXX ,
  // ├────────┬─────┴──┬─────┴──┬─────┴────────┴────────┴────────┴────────┴────────┴────────┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,                            KC_ASTG                             ,XXXXXXX ,XXXXXXX ,KC_ASOFF,KC_ASDN ,KC_ASON
  // └────────┴────────┴────────┴────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┴────────┘
  )
};

// runs just one time when the keyboard initializes.
void matrix_init_user(void){};

// runs constantly in the background, in a loop.
void matrix_scan_user(void){};

// shorthand for getting modifier key events
#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

// Key processing before key events are handled
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint32_t key_timer;

  switch (keycode) {
    case L_BRI:
      if (record->event.pressed) {
        if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired)
          gcr_desired = LED_GCR_MAX;
        else
          gcr_desired += LED_GCR_STEP;
        if (led_animation_breathing) gcr_breathe = gcr_desired;
      }
      return false;
    case L_BRD:
      if (record->event.pressed) {
        if (LED_GCR_STEP > gcr_desired)
          gcr_desired = 0;
        else
          gcr_desired -= LED_GCR_STEP;
        if (led_animation_breathing) gcr_breathe = gcr_desired;
      }
      return false;
    case L_PTN:
      if (record->event.pressed) {
        if (led_animation_id == led_setups_count - 1)
          led_animation_id = 0;
        else
          led_animation_id++;
      }
      return false;
    case L_PTP:
      if (record->event.pressed) {
        if (led_animation_id == 0)
          led_animation_id = led_setups_count - 1;
        else
          led_animation_id--;
      }
      return false;
    case L_PSI:
      if (record->event.pressed) {
        led_animation_speed += ANIMATION_SPEED_STEP;
      }
      return false;
    case L_PSD:
      if (record->event.pressed) {
        led_animation_speed -= ANIMATION_SPEED_STEP;
        if (led_animation_speed < 0) led_animation_speed = 0;
      }
      return false;
    case L_T_MD:
      if (record->event.pressed) {
        led_lighting_mode++;
        if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
      }
      return false;
    case L_T_ONF:
      if (record->event.pressed) {
        led_enabled = !led_enabled;
        I2C3733_Control_Set(led_enabled);
      }
      return false;
    case L_ON:
      if (record->event.pressed) {
        led_enabled = 1;
        I2C3733_Control_Set(led_enabled);
      }
      return false;
    case L_OFF:
      if (record->event.pressed) {
        led_enabled = 0;
        I2C3733_Control_Set(led_enabled);
      }
      return false;
    case L_T_BR:
      if (record->event.pressed) {
        led_animation_breathing = !led_animation_breathing;
        if (led_animation_breathing) {
          gcr_breathe               = gcr_desired;
          led_animation_breathe_cur = BREATHE_MIN_STEP;
          breathe_dir               = 1;
        }
      }
      return false;
    case L_T_PTD:
      if (record->event.pressed) {
        led_animation_direction = !led_animation_direction;
      }
      return false;
    case U_T_AGCR:
      if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
        TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
      }
      return false;
    case DBG_TOG:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
      }
      return false;
    case DBG_MTRX:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
      }
      return false;
    case DBG_KBD:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
      }
      return false;
    case DBG_MOU:
      if (record->event.pressed) {
        TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
      }
      return false;
    case MD_BOOT:
      if (record->event.pressed) {
        key_timer = timer_read32();
      } else {
        if (timer_elapsed32(key_timer) >= 500) {
          reset_keyboard();
        }
      }
      return false;
    default:
      return true;  // Process all other keycodes normally
  }
}

led_instruction_t led_instructions[] = {
  // esc, semi-colon, slash, alpha-numeric keys on sFN layer - deep sky blue
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 2147950591, .id1 = 4317439, .layer = sFN, .r = 0, .g = 191, .b = 255},
  // meta keys on sFN layer - dark violet
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 1073741824, .id1 = 201330688, .layer = sFN, .r = 161, .g = 0, .b = 255},

  // w,a,s,d on GAME layer - deep sky blue
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 2147614720, .id1 = 3, .layer = GAME, .r = 0, .g = 191, .b = 255},

  // media keys on MIDI layer - deep sky blue
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 33822720, .id1 = 591134721, .id2 = 7, .layer = MIDI, .r = 0, .g = 191, .b = 255},

  // misc keys on HW layer - deep sky blue
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 6144, .id1 = 553779200, .id2 = 7, .layer = HW, .r = 0, .g = 191, .b = 255},

  // fn on FN layer - dark violet
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id1 = 2147483648, .layer = FN, .r = 161, .g = 0, .b = 255},
  // home on HW layer - dark violet
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 16384, .layer = HW, .r = 161, .g = 0, .b = 255},
  // pgUp on GAME layer - dark violet
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 536870912, .layer = GAME, .r = 161, .g = 0, .b = 255},
  // pgDn on MIDI layer - dark violet
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id1 = 2048, .layer = MIDI, .r = 161, .g = 0, .b = 255},
  // slash on LOCK layer - deep sky blue
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id1 = 4194304, .layer = LOCK, .r = 0, .g = 191, .b = 255},

  // underglow LED on all layers - dark violet
  {.flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id2 = 4294967288, .id3 = 511, .r = 161, .g = 0, .b = 255},

  // end must be set to 1 to indicate end of instruction set
  {.end = 1}
};
