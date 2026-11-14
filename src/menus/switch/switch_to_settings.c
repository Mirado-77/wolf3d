/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** switch_to_settings
*/

#include "wolf.h"
#include "textures.h"

void switch_to_settings(wolf_t *wolf3d)
{
    texture_t menu_entities[] = {
        PLAY_BTN, LEAVE_BTN, SETTINGS_BTN, FADE3, GAMEMODE_BTN,
        BR_BTN, MULTI_BTN, ZOMBIE_BTN, END
    };
    texture_t to_true[] = {
        BACK_BTN, VOLUME_SLIDER, SLIDER_HANDLE,
        KEY_A, KEY_D, KEY_E, KEY_Q, KEY_S, KEY_Z, KEY_ARROW_L,
        KEY_ARROW_R, KEY_SHIFT, AUDIO_BTN, GRAPHICS_BTN,
        CONTROLS_BTN, END
    };

    undraw_entities(wolf3d->tex_manager, menu_entities);
    set_to_true(wolf3d->tex_manager, to_true);
    hide_all_texts(wolf3d->tex_manager);
    wolf3d->game_state = IN_SUB_AUDIOS;
}
