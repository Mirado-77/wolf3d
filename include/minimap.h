/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** minimap
*/

#ifndef MINIMAP_H
    #define MINIMAP_H
    #include <SFML/Graphics.h>
    #include "map.h"
    #include "player.h"

    #define MINIMAP_TILE_SIZE 10
    #define MINIMAP_VIEW_SIZE 16

typedef struct {
    int tile;
    sfVector2f pos;
    sfColor wall;
    sfColor floor;
    sfColor player;
    sfRenderWindow *win;
} minimap_t;

void minimap_init(minimap_t *mm, sfRenderWindow *win);
void minimap_draw(const minimap_t *mm,
    const map_t *map, const player_t *player);
#endif
