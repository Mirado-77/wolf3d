/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** floor_rendering
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "raycasting.h"


rf_maths_t get_floor_math(const player_t *player, int screenH)
{
    rf_maths_t floor_math;

    floor_math.dirX0 = player->dirX - player->planeX;
    floor_math.dirY0 = player->dirY - player->planeY;
    floor_math.dirX1 = player->dirX + player->planeX;
    floor_math.dirY1 = player->dirY + player->planeY;
    floor_math.posZ = 0.5f * screenH;
    return floor_math;
}

void draw_floor_texture(ray_context_t *ctx, sfImage *img)
{
    sfTexture *floor_texture = sfTexture_createFromImage(img, NULL);
    sfSprite *sprite = sfSprite_create();
    sfRenderStates state = {0};

    sfSprite_setTexture(sprite, floor_texture, sfTrue);
    state.transform = sfTransform_Identity;
    state.blendMode = sfBlendAlpha;
    state.shader = ctx->floor_shader;
    state.texture = floor_texture;
    sfRenderWindow_drawSprite(ctx->win, sprite, &state);
    sfSprite_destroy(sprite);
    sfTexture_destroy(floor_texture);
}

static void fill_floor_pixel(sfUint8 *dst, const sfUint8 *src)
{
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = FLOOR_OPAQUENESS;
}

static floor_vars_t compute_floor_vars(const ray_context_t *ctx,
    const floor_data_t *data, int y)
{
    floor_vars_t vars;

    vars.p = y - (float)ctx->screenH / 2.0f;
    vars.rowDist = data->floor_math->posZ / vars.p;
    vars.stepX = vars.rowDist * (data->floor_math->dirX1
    - data->floor_math->dirX0) / ctx->screenW;
    vars.stepY = vars.rowDist * (data->floor_math->dirY1
    - data->floor_math->dirY0) / ctx->screenW;
    vars.floorX = ctx->player->x + vars.rowDist * data->floor_math->dirX0;
    vars.floorY = ctx->player->y + vars.rowDist * data->floor_math->dirY0;
    return vars;
}

static void fill_floor_x_loop(const ray_context_t *ctx,
    const floor_data_t *data, floor_vars_t *vars, int y)
{
    int cellX = 0;
    int cellY = 0;
    int texX = 0;
    int texY = 0;
    const sfUint8 *src;
    sfUint8 *dst;

    for (int x = 0; x < ctx->screenW; ++x) {
        cellY = (int)vars->floorY;
        cellX = (int)vars->floorX;
        texX = (int)(TEXW * (vars->floorX - cellX)) & TEXMASK;
        texY = (int)(TEXH * (vars->floorY - cellY)) & TEXMASK;
        src = data->tex_pixels + 4 * (texY * TEXW + texX);
        dst = data->frame_buffer + 4 * (y * ctx->screenW + x);
        fill_floor_pixel(dst, src);
        vars->floorX += vars->stepX;
        vars->floorY += vars->stepY;
    }
}

static void fill_floor_row(ray_context_t *ctx, floor_data_t *data, int y)
{
    floor_vars_t vars = compute_floor_vars(ctx, data, y);

    fill_floor_x_loop(ctx, data, &vars, y);
}

static void fill_floor_image(ray_context_t *ctx,
    const rf_maths_t *floor_math, const sfUint8 *tex_pixels, sfImage *img)
{
    sfUint8 *frame_buffer = (sfUint8 *)sfImage_getPixelsPtr(img);
    floor_data_t floor_data = {tex_pixels, frame_buffer, floor_math};

    for (int y = ctx->screenH / 2 + 1; y < ctx->screenH; ++y) {
        fill_floor_row(ctx, &floor_data, y);
    }
}

void draw_floor_strips(ray_context_t *ctx,
    const rf_maths_t *floor_math, const sfUint8 *tex_pixels)
{
    sfImage *img = sfImage_create(ctx->screenW, ctx->screenH);

    fill_floor_image(ctx, floor_math, tex_pixels, img);
    draw_floor_texture(ctx, img);
    sfImage_destroy(img);
}
