/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** torch
*/

#include "wolf.h"

void consume_health_bottle(player_t *player, float speed, map_t *m,
    wolf_t *wolf)
{
    UNUSED(wolf);
    UNUSED(speed);
    UNUSED(m);
    if (player->invetory.pot_pv) {
        player->health += MAX_HEALTH / 2;
        player->invetory.pot_pv = false;
        play_sound(&wolf->sound_sys, SOUND_POTION);
    }
}

void consume_mana_bottle(player_t *player, float speed, map_t *m, wolf_t *wolf)
{
    UNUSED(wolf);
    UNUSED(speed);
    UNUSED(m);
    if (player->invetory.pot_mana) {
        player->mana += MAX_MANA / 2;
        player->invetory.pot_mana = false;
        play_sound(&wolf->sound_sys, SOUND_POTION);
    }
}

void consume_key(player_t *player)
{
    if (player->invetory.key)
        player->invetory.key = false;
}
