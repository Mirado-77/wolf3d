/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** destroy_ctx
*/

#include "wolf.h"

static void destroy_ctx_textures(ray_context_t *ctx)
{
    sfTexture_destroy(ctx->wall_texture);
    sfTexture_destroy(ctx->floor_texture);
    sfTexture_destroy(ctx->main_door_texture);
    sfTexture_destroy(ctx->wood_texture);
    sfTexture_destroy(ctx->sec_door_texture);
    sfTexture_destroy(ctx->boss_door_texture);
    sfShader_destroy(ctx->wall_shader);
    sfShader_destroy(ctx->floor_shader);
}

void destroy_ctx(ray_context_t *ctx)
{
    if (!ctx)
        return;
    destroy_ctx_textures(ctx);
    if (ctx->zdbuffer) {
        free(ctx->zdbuffer);
        ctx->zdbuffer = NULL;
    }
}
