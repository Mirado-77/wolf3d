/*
** EPITECH PROJECT, 2025
** ennemie_movement.c
** File description:
** move ennemie to player
*/

#include "wolf.h"
#include "object.h"
#include <math.h>

void move(ray_context_t *ctx, float2_t vector, float2_t *pos)
{
    if (ctx->map->tiles[(int)pos->x][(int)pos->y] != 0) {
        pos->x -= vector.x * SPEED;
        pos->y -= vector.y * SPEED;
    }
}

void move_ennemie(wolf_t *wolf3d, ray_context_t *ctx, entity_t e, float2_t pos)
{
    const float MIN_PLAYER_DIST = 1.0f;
    float2_t vector = {
        ctx->player->x - pos.x,
        ctx->player->y - pos.y,
    };
    const float range = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

    if (range <= MIN_PLAYER_DIST) {
        wolf3d->player.health -= ENNEMI_DAMAGE;
        play_sound(&wolf3d->sound_sys, SOUND_HURT);
        return;
    }
    vector.x /= range;
    vector.y /= range;
    if (ctx->map->tiles[(int)pos.x][(int)pos.y] == 0) {
        pos.x += vector.x * SPEED;
        pos.y += vector.y * SPEED;
    }
    move(ctx, vector, &pos);
    ecs_set_position(&wolf3d->world, e, pos.x, pos.y);
}
