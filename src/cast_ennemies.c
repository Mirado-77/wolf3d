/*
** EPITECH PROJECT, 2025
** ennemies
** File description:
** ennemies
*/

#include "map.h"
#include "raycasting.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ennemies.h"

void init_sprite(sprite_t *sprite, ray_context_t *ctx, float2_t ennemie_pos)
{
    double invDet = (ctx->player->planeX * ctx->player->dirY
        - ctx->player->dirX * ctx->player->planeY);

    invDet = 1.0 / (invDet);
    sprite->sprite_pos.x = ennemie_pos.x - ctx->player->x;
    sprite->sprite_pos.y = ennemie_pos.y - ctx->player->y;
    sprite->transform.x = invDet * (ctx->player->dirY * sprite->sprite_pos.x
        - ctx->player->dirX * sprite->sprite_pos.y);
    sprite->transform.y = invDet * (-ctx->player->planeY * sprite->sprite_pos.x
        + ctx->player->planeX * sprite->sprite_pos.y);
}

void calc_height_width(sprite_t *sprite, ray_context_t *ctx, int spriteScreenX)
{
    sprite->spriteHeight = abs((int)(ctx->screenH / sprite->transform.y));
    sprite->Drawstart.y = -sprite->spriteHeight / 2 + ctx->screenH / 2;
    sprite->Drawend.y = sprite->spriteHeight / 2 + ctx->screenH / 2;
    sprite->spriteWidth = abs((int)(ctx->screenH / sprite->transform.y));
    sprite->Drawstart.x = -sprite->spriteWidth / 2 + spriteScreenX;
    sprite->Drawend.x = sprite->spriteWidth / 2 + spriteScreenX;
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

static void draw_sprite(sprite_t *sprite, ray_context_t *ctx,
    const int x, const int tex_x)
{
    sfVertexArray *vertices = sfVertexArray_create();
    sfVertex top_left = create_wall_vertex(x, sprite->Drawstart.y, tex_x, 0.f);
    sfVertex top_right = create_wall_vertex(x + 1, sprite->Drawstart.y,
        tex_x + 1, 0.f);
    sfVertex bottom_right = create_wall_vertex(x, sprite->Drawend.y,
        tex_x + 1, 64.f);
    sfVertex bottom_left = create_wall_vertex(x + 1, sprite->Drawend.y,
        tex_x, 64.f);
    sfRenderStates state = {0};

    sfVertexArray_setPrimitiveType(vertices, sfQuads);
    sfVertexArray_append(vertices, top_left);
    sfVertexArray_append(vertices, top_right);
    sfVertexArray_append(vertices, bottom_right);
    sfVertexArray_append(vertices, bottom_left);
    state.texture = sprite->vilain_texture;
    state.transform = sfTransform_Identity;
    state.blendMode = sfBlendAlpha;
    sfRenderWindow_drawVertexArray(ctx->win, vertices, &state);
    sfVertexArray_destroy(vertices);
}

void cast_ennemies(ray_context_t *ctx, float2_t ennemie_pos,
    sprite_t sprite, int sprite_widght)
{
    int spriteScreenX = 0;
    int tex_x;

    init_sprite(&sprite, ctx, ennemie_pos);
    if (fabs(sprite.transform.y) < 1e-4f)
        return;
    spriteScreenX = (int)((ctx->screenW / 2) *
        (1 + sprite.transform.x / sprite.transform.y));
    calc_height_width(&sprite, ctx, spriteScreenX);
    for (int stripe = sprite.Drawstart.x;
        stripe < sprite.Drawend.x; stripe++) {
        tex_x = (int)(256 * (stripe -
            (-sprite.spriteWidth / 2 + spriteScreenX))
            * sprite_widght / sprite.spriteWidth) / 256;
        if (sprite.transform.y > 0 && stripe > 0 &&
            stripe < ctx->screenW && sprite.transform.y
                < ctx->zdbuffer[stripe]) {
                draw_sprite(&sprite, ctx, stripe, tex_x + sprite.add_in_rect);
            }
    }
}
