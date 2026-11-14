/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_multiple_instances
*/
#include "wolf.h"
#include "textures.h"

static void draw_single_texture(wolf_t *wolf3d, texture_t texture_id,
    sfVector2f position, sfVector2f scale)
{
    texture_asset_t *asset = &wolf3d->tex_manager->assets[texture_id];

    sfSprite_setPosition(asset->sprite, position);
    sfSprite_setScale(asset->sprite, scale);
    sfRenderWindow_drawSprite(wolf3d->window, asset->sprite, NULL);
}

static size_t get_array_length(sfVector2f *array)
{
    size_t length = 0;

    while (array[length].x != END && array[length].y != END)
        ++length;
    return length;
}

void draw_texture_multiple(wolf_t *wolf3d, texture_t texture_id,
    texture_draw_params_t *params, size_t draw_count)
{
    texture_asset_t *asset = NULL;
    sfVector2f position = {0};
    sfVector2f scale = {0};

    if (!wolf3d || !wolf3d->tex_manager ||
        !is_valid_entity(wolf3d->tex_manager, texture_id))
        return;
    asset = &wolf3d->tex_manager->assets[texture_id];
    if (!asset->sprite)
        return;
    for (size_t i = 0; i < draw_count; ++i) {
        position = params->positions[i % get_array_length(params->positions)];
        scale = params->scales[i % get_array_length(params->scales)];
        draw_single_texture(wolf3d, texture_id, position, scale);
    }
}
