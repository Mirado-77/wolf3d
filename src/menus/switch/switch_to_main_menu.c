/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** switch_to_main_menu
*/

#include "wolf.h"

void switch_to_main_menu(wolf_t *wolf3d)
{
    texture_t menu_entities[] = {
        BACK_BTN, VOLUME_SLIDER, SLIDER_HANDLE, BR_BTN,
        MULTI_BTN, ZOMBIE_BTN, FADE1, KEY_A, KEY_D, KEY_E, KEY_Q, KEY_S, KEY_Z,
        KEY_ARROW_L, KEY_ARROW_R, PLAYER_HUD, BLOOD_LINE, MANA_LINE,
        STAMINA_LINE, DEVIDER1, CARD_GAME, CLOSE_BTN, HUD_MINIMAP,
        SKELETON_HEAD, AUDIO_BTN, GRAPHICS_BTN, CONTROLS_BTN, WINDOW_MODE, END
    };
    texture_t to_true[] = {
        FADE3, PLAY_BTN, SETTINGS_BTN, LEAVE_BTN, GAMEMODE_BTN, LORE_BTN, END
    };

    undraw_entities(wolf3d->tex_manager, menu_entities);
    set_to_true(wolf3d->tex_manager, to_true);
    hide_all_texts(wolf3d->tex_manager);
    wolf3d->game_state = IN_MAIN_MENU;
}
