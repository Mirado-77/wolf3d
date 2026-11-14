/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** positions
*/

#ifndef POSITIONS_H_
    #define POSITIONS_H_
    #define WIN_WIDTH 1920
    #define MIN_WIN_WIDTH 1600
    #define WIN_HEIGHT 1080
    #define MIN_WIN_HEIGHT 900
    #define MIDDLE_X WIN_WIDTH / 2.3
    #define MIDDLE_Y WIN_HEIGHT / 3.3
    #define LEFT_PLACE WIN_WIDTH / 8
    #define POFT(val, delta) ((val) + (delta))
    #define NOFT(val, delta) ((val) - (delta))
    #define Y_50 50
    #define LPLACE_300 LEFT_PLACE + 300
    #define PLACE_200 200
    #define BTN_SCALE 4.5f
    #define BTN_SCALE_2 5.5f
    #define TITLE_SCALE 3.5f
    #define KEY_OFFSET_X 100
    #define KEY_SCALE 2.5f
    #define MINIMAP_COVER 5.0f
    #define FADE1_SCALEY 2.0f
    #define FADE1_SCALEX 2.7f
    #define KPOS_X(base, n) ((base) + KEY_OFFSET_X * (n))
    #define DP_POS(base, Poff, n) ((base) + (off) * (n))
    #define DN_POS(base, Noff, n) ((base) - (off) * (n))
    #define HUD_SCALEX 6.0f
    #define HUD_SCALEY 6.7f
    #define HEAD_SCALE 0.4f
    #define SETTINGS_FADE_SCALEX 8.0f
    #define SETTINGS_FADE_SCALEY 18.0f


    /* ================================= */
    /*         POSITION MAIN_MENU        */
    /* ================================= */
    #define TITLE_DECO_X2 NOFT(LEFT_PLACE, 200)
    #define TITLE_DECO_X NOFT(MIDDLE_X, 200)
    #define TITLE_DECO_Y 50
    #define LORE_FADE_X POFT(MIDDLE_X, 50)
    #define LORE_FADE_Y 5
    #define LORE_FADE_SCALE_X 5.0f
    #define LORE_FADE_SCALE_Y 17.0f

    /* ================================= */
    /*         POSITION MAIN_MENU        */
    /*              Buttons              */
    /* ================================= */
    #define PLAY_X LEFT_PLACE
    #define PLAY_Y 400
    #define SETTING_X LEFT_PLACE
    #define SETTING_Y 500
    #define GAMEMODE_X LEFT_PLACE
    #define GAMEMODE_Y 600
    #define LEAVE_X LEFT_PLACE
    #define LEAVE_Y 700
    #define CREDITS_X NOFT(WIN_WIDTH, 220)
    #define CREDITS_Y NOFT(WIN_HEIGHT, 156)

    /* ================================= */
    /*         POSITION SETTINGS         */
    /* ================================= */
    #define TITLE_SCREN_X LEFT_PLACE
    #define TITLE_SCREN_Y 180
    #define SETTING_FADE_X LEFT_PLACE
    #define SETTING_FADE_Y 385
    /* ================================= */
    /*         POSITION SETTINGS         */
    /*              Buttons              */
    /* ================================= */
    #define BACK_BTN_X 50
    #define BACK_BTN_Y 50
    #define AUDIO_BTN_X NOFT(MIDDLE_X, 440)
    #define AUDIO_BTN_Y 310
    #define GRAPHICS_BTN_X NOFT(MIDDLE_X, 100)
    #define GRAPHICS_BTN_Y 310
    #define CONTROLS_BTN_X POFT(MIDDLE_X, 237)
    #define CONTROLS_BTN_Y 310
    #define LORE_FADE_Y_500 LORE_FADE_Y + 920
    #define LORE_DEVIDER_SCALE_Y 4.0f
    /* ================================= */
    /*         POSITION SUB_AUDIO        */
    /* ================================= */
    #define VOL_SLIDER_X NOFT(LPLACE_300, 100)
    #define VOL_SLIDER_Y POFT(MIDDLE_Y, 170)
    #define VOL_SLIDER_HANDLE_X LPLACE_300
    #define VOL_SLIDER_HANDLE_Y POFT(PLACE_200, 300)

    /* ================================= */
    /*       POSITION SUB_GRAPHICS       */
    /* ================================= */
    #define WINDOW_MODE_X POFT(LEFT_PLACE, 240)
    #define WINDOW_MODE_Y 490

    /* ================================= */
    /*       POSITION SUB_CONTROLS       */
    /* ================================= */
    #define KEY_A_X POFT(LEFT_PLACE, 200)
    #define KEY_A_Y 470
    #define KEY_Z_X POFT(LEFT_PLACE, 200)
    #define KEY_Z_Y 520
    #define KEY_E_X POFT(LEFT_PLACE, 200)
    #define KEY_E_Y 570
    #define KEY_S_X POFT(LEFT_PLACE, 200)
    #define KEY_S_Y 620
    #define KEY_Q_X POFT(LEFT_PLACE, 200)
    #define KEY_Q_Y 670
    #define KEY_D_X POFT(LEFT_PLACE, 200)
    #define KEY_D_Y 720
    #define KEY_ARROW_L_X POFT(LEFT_PLACE, 200)
    #define KEY_ARROW_L_Y 770
    #define KEY_ARROW_R_X POFT(LEFT_PLACE, 200)
    #define KEY_ARROW_R_Y 820
    #define KEY_SHIFT_X POFT(LEFT_PLACE, 200)
    #define KEY_SHIFT_Y 870
    #define KEY_F_X POFT(MIDDLE_X, 200)
    #define KEY_F_Y 470
    #define KEY_R_X POFT(MIDDLE_X, 200)
    #define KEY_R_Y 520
    #define KEY_HB_X POFT(MIDDLE_X, 200)
    #define KEY_HB_Y 570
    #define KEY_MB_X POFT(MIDDLE_X, 200)
    #define KEY_MB_Y 620
    /* ================================= */
    /*         POSITION GAMEMODE         */
    /* ================================= */
    #define MULT_BTN_X NOFT(MIDDLE_X, 80)
    #define MULT_BTN_Y 450
    #define BR_BTN_X LEFT_PLACE
    #define BR_BTN_Y 450
    #define ZO_BTN_X NOFT(WIN_WIDTH, 650)
    #define ZO_BTN_Y 450
    #define CARD_1_X NOFT(LEFT_PLACE, 50)
    #define CARD_1_Y NOFT(450, 20)
    #define CARD_2_X POFT(LEFT_PLACE, 468)
    #define CARD_2_Y NOFT(450, 20)
    #define CARD_3_X POFT(LEFT_PLACE, POFT(468, 520))
    #define CARD_3_Y NOFT(450, 20)

    #define FADE1_GAMEMODE_X NOFT(MIDDLE_X, 260)
    #define FADE1_GAMEMODE_Y 50

    /* ================================= */
    /*        POSITION PRE_MULTI         */
    /* ================================= */
    #define HOST_BTN_X NOFT(LEFT_PLACE, 20)
    #define HOST_BTN_Y 450
    #define JOIN_BTN_X NOFT(WIN_WIDTH, 600)
    #define JOIN_BTN_Y 450

    /* ================================= */
    /*         POSITION CREDITS          */
    /* ================================= */
    #define MIRA_TXT_X NOFT(LEFT_PLACE, 70)
    #define MIRA_TXT_Y 305
    #define SANDES_TXT_X NOFT(MIDDLE_X, 50)
    #define SANDES_TXT_Y 305
    #define PHIL_TXT_X NOFT(WIN_WIDTH, 500)
    #define PHIL_TXT_Y 305

    /* ================================= */
    /*          SCALES CREDITS           */
    /* ================================= */
    #define CREDITS_FADE1_X 1.5f
    #define CREDITS_FADE1_Y 2.3f
    #define TITLE_CREDITS_FADE_X LEFT_PLACE
    #define TITLE_CREDITS_FADE_Y 385

    /* ================================= */
    /*           SCALES PAUSE            */
    /* ================================= */
    #define PAUSE_TITLE_DECO_X NOFT(MIDDLE_X, 200)
    #define PAUSE_TITLE_DECO_Y 40

    /* ================================= */
    /*            SCALES HUD             */
    /* ================================= */
    #define BLOOD_LINE_X NOFT(WIN_WIDTH, 1650)
    #define BLOOD_LINE_Y NOFT(WIN_HEIGHT, 243)
    #define MANA_LINE_X  NOFT(WIN_WIDTH, 1650)
    #define MANA_LINE_Y NOFT(WIN_HEIGHT, 207)
    #define STAMINA_LINE_X NOFT(WIN_WIDTH, 1650)
    #define STAMINA_LINE_Y NOFT(WIN_HEIGHT, 170)
    #define PLAYER_HUD_X NOFT(WIN_WIDTH, 1900)
    #define PLAYER_HUD_Y NOFT(WIN_HEIGHT, 350)
    #define HUD_MAP_X 10
    #define HUD_MAP_Y 10
    #define SKELETON_HEAD_X NOFT(WIN_WIDTH, 1870)
    #define SKELETON_HEAD_Y NOFT(WIN_HEIGHT, 320)
    #define HUD_ITEMS_X NOFT(WIN_WIDTH, 450)
    #define HUD_ITEMS_Y NOFT(WIN_HEIGHT, 450)
    #define HUD_ITEMS_SX 5.5f
    #define HUD_ITEMS_SY 5.5f
    #define BOSS_BAR_X POFT(MIDDLE_X, 120)
    #define BOSS_BAR_Y 100
    #define BOSS_BAR_FILLER_X POFT(MIDDLE_X, 120)
    #define BOSS_BAR_FILLER_Y 98

    #define BOSS_SCALEX 4.0f

    #define HEART1_X 290
    #define HEART1_Y NOFT(WIN_HEIGHT, 290)
    #define HEART2_X 375
    #define HEART2_Y NOFT(WIN_HEIGHT, 290)
    #define HEART3_X 460
    #define HEART3_Y NOFT(WIN_HEIGHT, 290)

    #define HEART_SCALE 1.5f

    #define BOSS_KEY_X NOFT(WIN_WIDTH, 250)
    #define BOSS_KEY_Y NOFT(WIN_HEIGHT, 230)

    #define BOSS_KEY_SX 3.0f
    #define BOSS_KEY_SY 3.0f
    #define KEY_ANGLE 40.0f
    #define MANA_BOTLE_X NOFT(WIN_WIDTH, 163)
    #define MANA_BOTLE_Y NOFT(WIN_HEIGHT, 175)
    #define HEALTH_BOTLE_X NOFT(WIN_WIDTH, 83)
    #define HEALTH_BOTLE_Y NOFT(WIN_HEIGHT, 175)
    #define BOTTLE_SX 1.6f
    #define BOTTLE_SY 1.6f
    #define BOTTLE_ANGLE 10.0f

    // SPELLS
    #define SPELL_1_3_X NOFT(WIN_WIDTH, 140)
    #define SPELL_1_3_Y NOFT(WIN_HEIGHT, 290)
    #define SPELL_2_3_X NOFT(WIN_WIDTH, 380)
    #define SPELL_2_3_Y NOFT(WIN_HEIGHT, 290)
    #define SPELL_3_3_X NOFT(WIN_WIDTH, 250)
    #define SPELL_3_3_Y NOFT(WIN_HEIGHT, 360)

    #define SPELL_SCALE 1.3f
    #define SPELL2_SCALE 1.0f
    #define TORCH_SCALE 0.8f

    /* ================================= */
    /*         SCALES GAME OVER          */
    /* ================================= */
    #define GAME_OVER_FADE1_X NOFT(MIDDLE_X, 210)
    #define GAME_OVER_FADE1_Y 50


    #define INPUT_TXT_X JOIN_BTN_X + 55
    #define INPUT_TXT_Y JOIN_BTN_Y + 105
#endif /* !POSITIONS_H_ */
