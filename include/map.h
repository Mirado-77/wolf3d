/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** map
*/

#ifndef MAP_H
    #define MAP_H
    #include <stdbool.h>
    #include "player.h"

    #define MAP_PATH "configs/map_config.txt"
    #define MAP_MULTI "configs/map_multi.txt"

typedef enum {
    TILE_EMPTY = 0,
    TILE_WALL = 1,
    TILE_DOOR_MAIN = 2,
    TILE_DOOR_SIDE = 3,
    TILE_DOOR_BOSS = 4,
    TILE_WOOD = 5,
    TILE_STONE_BRICKS = 6,
    TILE_BRICKS_MOSS = 7,
    TILE_BRICKS_HOLES = 8,
    TILE_OLD_STONES = 9,
    TILE_WOOD_BRICKS = 10,
} tile_t;

typedef struct {
    int width;
    int height;
    int **tiles;
} map_t;

static inline bool is_blocking(int t)
{
    return t == TILE_WALL || t >= 2;
}

static inline bool is_door(int t)
{
    return t >= 2 && t <= 4;
}

map_t load_map(const char *filename);
void free_map(map_t *map);

int open_door(map_t *m, int x, int y, player_t *player);

#endif
