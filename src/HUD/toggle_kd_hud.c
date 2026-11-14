/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_kda_hud
*/

#include "wolf.h"

void toggle_kd_hud(player_t *player, float speed, map_t *m, wolf_t *wolf)
{
    UNUSED(speed);
    UNUSED(m);
    UNUSED(wolf);
    player->show_kd = sfKeyboard_isKeyPressed(sfKeyTab);
}
