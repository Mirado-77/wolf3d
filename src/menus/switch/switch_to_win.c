/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** switch_to_win
*/

#include "wolf.h"
#include "textures.h"

void switch_to_win(wolf_t *wolf3d)
{
    texture_t to_enable[] = {PLAY_BTN, BACK_BTN, SETTINGS_BTN, LEAVE_BTN,
        FADE1, FADE3, GAMEMODE_BTN, VOLUME_SLIDER, SLIDER_HANDLE, BR_BTN,
        MULTI_BTN, ZOMBIE_BTN, KEY_A, KEY_D, KEY_E, KEY_Q, KEY_S, KEY_Z, KEY_F,
        KEY_ARROW_L, KEY_ARROW_R, KEY_SHIFT, PLAYER_HUD, BLOOD_LINE,
        MANA_LINE, STAMINA_LINE, DEVIDER1, CARD_GAME, CLOSE_BTN, HUD_MINIMAP,
        SKELETON_HEAD, AUDIO_BTN, GRAPHICS_BTN, CONTROLS_BTN, WINDOW_MODE,
        HOST_BTN, JOIN_BTN, CREDITS_BTN, SAVE_BTN, HUD_ITEMS, BOSS_BAR,
        BOSS_FILLER, HEART, BOSS_KEY, INPUT, HEALTH_BOTLE, MANA_BOTLE, END
    };

    set_to_true(wolf3d->tex_manager, to_enable);
    hide_all_texts(wolf3d->tex_manager);
    wolf3d->game_state = IN_WIN;
}
