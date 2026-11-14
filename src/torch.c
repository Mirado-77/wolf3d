/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** torch
*/

#include "wolf.h"

void switch_torch(player_t *player, float speed, map_t *m, wolf_t *wolf)
{
    (void)player;
    (void)speed;
    (void)m;
    wolf->ctx->flash_on = !wolf->ctx->flash_on;
    sfShader_setBoolUniform(wolf->ctx->wall_shader,
        "torchOn", wolf->ctx->flash_on);
    sfShader_setBoolUniform(wolf->ctx->floor_shader,
        "torchOn", wolf->ctx->flash_on);
}
