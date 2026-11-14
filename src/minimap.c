/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** minimap
*/

#include "minimap.h"

void minimap_init(minimap_t *mm, sfRenderWindow *win)
{
    int tile = MINIMAP_TILE_SIZE;
    sfVector2f pos = {10, 10};

    mm->tile = tile;
    mm->pos = pos;
    mm->wall = (sfColor){72, 45, 28, 255};
    mm->floor = (sfColor){189, 155, 25, 250};
    mm->player = sfRed;
    mm->win = win;
}

static void draw_cell(sfRenderWindow *w, const sfVector2f pos,
    const int size, const sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangle, (sfVector2f){size, size});
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setFillColor(rectangle, color);
    sfRenderWindow_drawRectangleShape(w, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
}

static void calculate_view_start(const player_t *player, int half, int *startX,
    int *startY)
{
    int px = (int)player->x;
    int py = (int)player->y;

    *startX = px - half;
    *startY = py - half;
}

static sfColor get_cell_color(const map_t *map, int mapX, int mapY,
    const minimap_t *mm)
{
    sfColor col = mm->floor;

    if (mapX < 0 || mapX >= map->width ||
        mapY < 0 || mapY >= map->height)
        return (sfColor){0, 0, 0, 255};
    if (map->tiles[mapX][mapY])
        col = mm->wall;
    return col;
}

static void draw_minimap_cells(const minimap_t *mm, const map_t *map,
    int startX, int startY)
{
    int view = MINIMAP_VIEW_SIZE;
    int cell = mm->tile;
    int mapX = 0;
    int mapY = 0;
    sfColor col = {0};
    sfVector2f off = mm->pos;
    sfRenderWindow *w = mm->win;

    for (int j = 0; j < view; ++j) {
        for (int i = 0; i < view; ++i) {
            mapX = startX + i;
            mapY = startY + j;
            col = get_cell_color(map, mapX, mapY, mm);
            draw_cell(w, (sfVector2f){off.x + i * cell, off.y + j * cell},
                cell, col);
        }
    }
}

static void draw_player_on_minimap(const minimap_t *mm, const player_t *player,
    int startX, int startY)
{
    int cell = mm->tile;
    float localX = (player->x - startX) * cell - cell * 0.25f;
    float localY = (player->y - startY) * cell - cell * 0.25f;
    sfVector2f off = mm->pos;
    sfRenderWindow * w = mm->win;

    draw_cell(w, (sfVector2f){off.x + localX, off.y + localY}, cell / 2,
        mm->player);
}

void minimap_draw(const minimap_t *mm, const map_t *map,
    const player_t *player)
{
    int half = MINIMAP_VIEW_SIZE / 2;
    int startX;
    int startY;

    calculate_view_start(player, half, &startX, &startY);
    draw_minimap_cells(mm, map, startX, startY);
    draw_player_on_minimap(mm, player, startX, startY);
}
