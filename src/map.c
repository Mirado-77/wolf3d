/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** map
*/

#include <stdlib.h>
#include <stdio.h>
#include "map.h"

int open_door(map_t *m, int x, int y, player_t *player)
{
    int t;

    if (x < 0 || y < 0 || x >= m->width || y >= m->height)
        return 0;
    t = m->tiles[x][y];
    if (!is_door(t))
        return 0;
    if (t != TILE_DOOR_BOSS)
        m->tiles[x][y] = TILE_EMPTY;
    if (t == TILE_DOOR_BOSS && player->invetory.key == true) {
        m->tiles[x][y] = TILE_EMPTY;
        consume_key(player);
    }
    return t;
}

map_t load_map(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    map_t m = {0};

    fscanf(fp, "%d %d", &m.width, &m.height);
    m.tiles = malloc(sizeof(int *) * m.width);
    for (int x = 0; x < m.width; ++x) {
        m.tiles[x] = malloc(sizeof(int) * m.height);
    }
    for (int y = 0; y < m.height; ++y)
        for (int x = 0; x < m.width; ++x)
            fscanf(fp, "%d", &m.tiles[x][y]);
    fclose(fp);
    return m;
}

void free_map(map_t *m)
{
    for (int x = 0; x < m->width; ++x)
        free(m->tiles[x]);
    free(m->tiles);
    *m = (map_t){0};
}
