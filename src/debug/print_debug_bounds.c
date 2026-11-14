/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** print_debug_bounds
*/

#include "wolf.h"

void draw_debug_bounds(wolf_t *wolf3d, texture_asset_t *asset)
{
    sfRectangleShape *debug_rect;
    sfFloatRect bounds;
    sfVector2f size;
    sfVector2f pos;

    if (!wolf3d || !asset || !asset->sprite)
        return;
    bounds = sfSprite_getGlobalBounds(asset->sprite);
    size = (sfVector2f){bounds.width, bounds.height};
    pos = (sfVector2f){bounds.left, bounds.top};
    debug_rect = sfRectangleShape_create();
    if (!debug_rect)
        return;
    sfRectangleShape_setPosition(debug_rect, pos);
    sfRectangleShape_setSize(debug_rect, size);
    sfRectangleShape_setOutlineColor(debug_rect, sfRed);
    sfRectangleShape_setOutlineThickness(debug_rect, 2.0f);
    sfRectangleShape_setFillColor(debug_rect, sfTransparent);
    sfRenderWindow_drawRectangleShape(wolf3d->window, debug_rect, NULL);
    sfRectangleShape_destroy(debug_rect);
}
