/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** raycasting
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include "raycasting.h"

static void init_ray(ray_t *r, const ray_context_t *ctx, int x)
{
    r->cameraX = 2.0f * x / (float)ctx->screenW - 1.0f;
    r->rayDir.x = ctx->player->dirX + ctx->player->planeX * r->cameraX;
    r->rayDir.y = ctx->player->dirY + ctx->player->planeY * r->cameraX;
    r->mapCoord.x = (int)ctx->player->x;
    r->mapCoord.y = (int)ctx->player->y;
    r->deltaDist.x = (r->rayDir.x == 0) ? 1e30f : fabsf(1.0f / r->rayDir.x);
    r->deltaDist.y = (r->rayDir.y == 0) ? 1e30f : fabsf(1.0f / r->rayDir.y);
    r->hit = 0;
}

static void calc_step_side(ray_t *r, const ray_context_t *ctx)
{
    float cam_x = ctx->player->x;
    float cam_y = ctx->player->y;

    if (r->rayDir.x < 0) {
        r->step.x = -1;
        r->sideDist.x = (cam_x - r->mapCoord.x) * r->deltaDist.x;
    } else {
        r->step.x = 1;
        r->sideDist.x = (r->mapCoord.x + 1.0f - cam_x) * r->deltaDist.x;
    }
    if (r->rayDir.y < 0) {
        r->step.y = -1;
        r->sideDist.y = (cam_y - r->mapCoord.y) * r->deltaDist.y;
    } else {
        r->step.y = 1;
        r->sideDist.y = (r->mapCoord.y + 1.0f - cam_y) * r->deltaDist.y;
    }
}

static void perform_dda(ray_t *r, const ray_context_t *ctx)
{
    while (!r->hit) {
        if (r->sideDist.x < r->sideDist.y) {
            r->sideDist.x += r->deltaDist.x;
            r->mapCoord.x += r->step.x;
            r->side = 0;
        } else {
            r->sideDist.y += r->deltaDist.y;
            r->mapCoord.y += r->step.y;
            r->side = 1;
        }
        if (r->mapCoord.x < 0 || r->mapCoord.x >= ctx->map->width ||
            r->mapCoord.y < 0 || r->mapCoord.y >= ctx->map->height) {
            r->hit = 1;
            return;
        }
        if (ctx->map->tiles[r->mapCoord.x][r->mapCoord.y] > 0)
            r->hit = 1;
    }
}

static void calc_line(ray_t *r, const ray_context_t *ctx)
{
    float cam_x = ctx->player->x;
    float cam_y = ctx->player->y;

    if (r->side == 0)
        r->perpWallDist = (r->mapCoord.x - cam_x + (1 - r->step.x)*0.5f)
        / r->rayDir.x;
    else
        r->perpWallDist = (r->mapCoord.y - cam_y + (1 - r->step.y)*0.5f)
        / r->rayDir.y;
    r->lineHeight = (int)(ctx->screenH / r->perpWallDist);
    r->drawStart = -r->lineHeight / 2 + ctx->screenH / 2;
    r->drawEnd = r->lineHeight / 2 + ctx->screenH / 2;
}

static float get_wall_x(const ray_t *r, const ray_context_t *ctx)
{
    float val = (r->side == 0)
        ? (ctx->player->y + r->perpWallDist * r->rayDir.y)
        : (ctx->player->x + r->perpWallDist * r->rayDir.x);

    val -= floorf(val);
    return val;
}

static int get_tex_x(float wallX, const ray_t *r)
{
    int tex_x = (int)(wallX * TEXH);

    if ((r->side == 0 && r->rayDir.x > 0)
        || (r->side == 1 && r->rayDir.y < 0))
        tex_x = TEXH - tex_x - 1;
    return tex_x;
}

static sfVertex create_wall_vertex(float x, float y, float tex_x, float tex_y)
{
    sfVertex vertex = {
        .position = {x, y},
        .color = sfWhite,
        .texCoords = {tex_x, tex_y}
    };

    return vertex;
}

static void draw_wall_quads(const ray_t *r, const ray_context_t *ctx,
    const int x, const int tex_x)
{
    sfVertexArray *vertices = sfVertexArray_create();
    sfVertex top_left = create_wall_vertex(x, r->drawStart, tex_x, 0.f);
    sfVertex top_right = create_wall_vertex(x + 1, r->drawStart,
        tex_x + 1, 0.f);
    sfVertex bottom_right = create_wall_vertex(x + 1, r->drawEnd,
        tex_x + 1, TEXF);
    sfVertex bottom_left = create_wall_vertex(x, r->drawEnd, tex_x, TEXF);
    sfRenderStates state = {.texture = set_correct_texture(r, ctx),
        .transform = sfTransform_Identity, .blendMode = sfBlendAlpha,
        .shader = ctx->wall_shader};

    sfShader_setFloatUniform(ctx->wall_shader, "distance", r->perpWallDist);
    sfVertexArray_setPrimitiveType(vertices, sfQuads);
    sfVertexArray_append(vertices, top_left);
    sfVertexArray_append(vertices, top_right);
    sfVertexArray_append(vertices, bottom_right);
    sfVertexArray_append(vertices, bottom_left);
    sfRenderWindow_drawVertexArray(ctx->win, vertices, &state);
    sfVertexArray_destroy(vertices);
}

static void cast_one_column(const ray_context_t *ctx, const int x)
{
    ray_t r;
    float wallX = 0.0f;
    int tex_x = 0;

    init_ray(&r, ctx, x);
    calc_step_side(&r, ctx);
    perform_dda(&r, ctx);
    calc_line(&r, ctx);
    wallX = get_wall_x(&r, ctx);
    tex_x = get_tex_x(wallX, &r);
    draw_wall_quads(&r, ctx, x, tex_x);
    ctx->zdbuffer[x] = r.perpWallDist;
}

void cast_rays(ray_context_t *ctx)
{
    rf_maths_t floor_math = get_floor_math(ctx->player, ctx->screenH);
    sfImage *temp_image = sfTexture_copyToImage(ctx->floor_texture);
    const sfUint8 *floorPixels = sfImage_getPixelsPtr(temp_image);

    draw_floor_strips(ctx, &floor_math, floorPixels);
    for (int x = 0; x < ctx->screenW; x++)
        cast_one_column(ctx, x);
    sfImage_destroy(temp_image);
}
