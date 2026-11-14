/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** load_map_texture
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include "raycasting.h"

sfTexture *set_correct_texture(const ray_t *r, const ray_context_t *ctx)
{
    const int tile_id = ctx->map->tiles[r->mapCoord.x][r->mapCoord.y];

    if (tile_id == TILE_DOOR_MAIN)
        return ctx->main_door_texture;
    if (tile_id == TILE_DOOR_SIDE)
        return ctx->sec_door_texture;
    if (tile_id == TILE_DOOR_BOSS)
        return ctx->boss_door_texture;
    if (tile_id == TILE_WOOD)
        return ctx->wood_texture;
    if (tile_id == TILE_STONE_BRICKS)
        return ctx->bricks_texture;
    if (tile_id == TILE_BRICKS_MOSS)
        return ctx->moss_bricks_texture;
    if (tile_id == TILE_BRICKS_HOLES)
        return ctx->bricks_with_holes;
    if (tile_id == TILE_OLD_STONES)
        return ctx->old_bricks_texture;
    if (tile_id == TILE_WOOD_BRICKS)
        return ctx->wood_bricks_texture;
    return ctx->wall_texture;
}
