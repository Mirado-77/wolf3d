/*
** EPITECH PROJECT, 2025
** ls
** File description:
** ls
*/

#include "wolf.h"
#include "object.h"

void check_dialogue(wolf_t *wolf3d)
{
    int index = 0;
    int distance = 0;

    for (int i = 0; i < (int)wolf3d->ennemies.nb_ennemies; i++) {
        if (!ecs_is_valid_entity(&wolf3d->world, wolf3d->ennemies.cast[i].entity))
            continue;
        index = ecs_get_texture_path(&wolf3d->world, wolf3d->ennemies.cast[i].entity);
        if (index != IS_BOSS && index != IS_MASTER && index != IS_GENIE) {
            continue;
        }
        distance = calcul_distance(wolf3d, wolf3d->ennemies.cast[i].entity, wolf3d->ctx);
        if (distance <= 1 && index == IS_MASTER
            && !wolf3d->dialogue.is_active) {
            wolf3d->ctx->player->state = PLAYER_STATE_NEAR_MASTER;
            return;
        }
        if (distance <= 1 && index == IS_GENIE
            && !wolf3d->dialogue.is_active) {
            wolf3d->ctx->player->state = PLAYER_STATE_NEAR_GENIE;
            return;
        }
        if (distance <= 180 && index == IS_BOSS
            && !wolf3d->dialogue.is_active) {
            wolf3d->ctx->player->state = PLAYER_STATE_NEAR_BOSS;
            return;
        }
    }
}
