/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** switch_to_multi
*/

#include "wolf.h"
#include "multiplayer.h"

void switch_to_multi(wolf_t *wolf3d)
{
    texture_t menu_entities[] = {PLAY_BTN, SETTINGS_BTN, LEAVE_BTN, FADE3,
        GAMEMODE_BTN, VOLUME_SLIDER, SLIDER_HANDLE, BR_BTN, MULTI_BTN, KEY_Q,
        ZOMBIE_BTN, KEY_A, KEY_D, KEY_E, KEY_S, KEY_Z, KEY_ARROW_L,
        KEY_ARROW_R, KEY_SHIFT, END };
    texture_t to_enable[] = {PLAYER_HUD, BLOOD_LINE, MANA_LINE, STAMINA_LINE,
        END};

    if (!wolf3d->ip || wolf3d->ip[0] == '\0') {
        printf("%s %s", ERROR_IP, ERROR_IP_1);
        return;
    }
    free_map(&wolf3d->map);
    free_map(wolf3d->ctx->map);
    wolf3d->map = load_map(MAP_MULTI);
    *wolf3d->ctx->map = load_map(MAP_MULTI);
    undraw_entities(wolf3d->tex_manager, menu_entities);
    set_to_true(wolf3d->tex_manager, to_enable);
    hide_all_texts(wolf3d->tex_manager);
    multiplayer_init(wolf3d, wolf3d->ip);
    wolf3d->game_state = IN_MULTI;
}
