/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_shaders
*/

#include "wolf.h"

bool init_shaders(ray_context_t *ctx)
{
    ctx->wall_shader = sfShader_createFromFile(NULL, NULL, WALL_SHADER);
    ctx->floor_shader = sfShader_createFromFile(NULL, NULL, FLOOR_SHADER);
    if (!ctx->wall_shader || !ctx->floor_shader)
        return false;
    sfShader_setFloatUniform(ctx->wall_shader, "maxDist", MAX_WALL_DISTANCE);
    sfShader_setFloatUniform(ctx->floor_shader, "maxDist", MAX_FLOOR_DISTANCE);
    sfShader_setFloatUniform(ctx->floor_shader, "posZ", 0.5f * ctx->screenH);
    sfShader_setFloatUniform(ctx->floor_shader, "screenH",
        (float)ctx->screenH);
    sfShader_setBoolUniform(ctx->wall_shader, "torchOn", ctx->flash_on);
    sfShader_setFloatUniform(ctx->wall_shader, "torchRange", 5.f);
    sfShader_setBoolUniform(ctx->floor_shader, "torchOn", ctx->flash_on);
    sfShader_setFloatUniform(ctx->floor_shader, "torchRange", 5.f);
    return true;
}
