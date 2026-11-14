/*
** EPITECH PROJECT, 2025
** distance
** File description:
** distance
*/

#include "wolf.h"

double calcul_distance(wolf_t *wolf3d,
    entity_t ennemies, ray_context_t *ctx)
{
    float2_t sprite_pos = {0, 0};
    double result = 0;

    ecs_get_position(&wolf3d->world, ennemies,
        &sprite_pos.x, &sprite_pos.y);
    result = ((ctx->player->x - sprite_pos.x) *
        (ctx->player->x - sprite_pos.x) +
        (ctx->player->y - sprite_pos.y) * (ctx->player->y - sprite_pos.y));
    return result;
}
