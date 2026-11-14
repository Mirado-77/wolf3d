/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** switch_to_gamemode
*/

#include "wolf.h"

void switch_to_gamemode(wolf_t *wolf3d)
{
    texture_t to_disable[] = {
        PLAY_BTN, LEAVE_BTN, SETTINGS_BTN, FADE3, GAMEMODE_BTN,
        VOLUME_SLIDER, SLIDER_HANDLE, KEY_A, KEY_D, KEY_E, KEY_Q, KEY_S,
        KEY_ARROW_L, KEY_ARROW_R, KEY_SHIFT, PLAYER_HUD, BLOOD_LINE,
        MANA_LINE, STAMINA_LINE, HUD_MINIMAP, CLOSE_BTN, AUDIO_BTN,
        GRAPHICS_BTN, CONTROLS_BTN, WINDOW_MODE, END
    };
    texture_t to_enable[] = { FADE1, CARD_GAME, BACK_BTN, BR_BTN, MULTI_BTN,
        ZOMBIE_BTN, DEVIDER1, END
    };

    undraw_entities(wolf3d->tex_manager, to_disable);
    set_to_true(wolf3d->tex_manager, to_enable);
    hide_all_texts(wolf3d->tex_manager);
    wolf3d->game_state = IN_GAMEMODE;
}
