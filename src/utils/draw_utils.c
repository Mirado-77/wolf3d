/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** setup_menu
*/

#include "wolf.h"

static void draw_single_entity(wolf_t *wolf3d, texture_asset_t *asset)
{
    if (asset->is_loaded == false)
        return;
    if (!asset->sprite)
        return;
    sfSprite_setTextureRect(asset->sprite, asset->rect);
    sfRenderWindow_drawSprite(wolf3d->window, asset->sprite, NULL);
}

void draw_entities(wolf_t *wolf3d, texture_t *entities)
{
    texture_asset_t *asset = NULL;

    if (!wolf3d || !wolf3d->tex_manager || !entities)
        return;
    for (int i = 0; entities[i] != END; i++) {
        if (!is_valid_entity(wolf3d->tex_manager, entities[i]))
            continue;
        asset = &wolf3d->tex_manager->assets[entities[i]];
        draw_single_entity(wolf3d, asset);
    }
}

void undraw_entities(texture_manager_t *manager, texture_t *entities)
{
    if (!manager || !entities)
        return;
    for (int i = 0; entities[i] != END; i++) {
        if (!is_valid_entity(manager, entities[i]))
            continue;
        manager->assets[entities[i]].is_loaded = false;
        sfSprite_setTextureRect(manager->assets[entities[i]].sprite,
            manager->assets[entities[i]].rect);
    }
}

void set_to_true(texture_manager_t *manager, texture_t *entities)
{
    if (!manager || !entities)
        return;
    for (int i = 0; entities[i] != END; i++) {
        if (!is_valid_entity(manager, entities[i]))
            continue;
        manager->assets[entities[i]].is_loaded = true;
    }
}

static void scale_single_entity(texture_asset_t *asset, sfVector2f scale)
{
    if (!asset->sprite)
        return;
    sfSprite_setScale(asset->sprite, scale);
}

void set_scale_entities(texture_manager_t *manager, texture_t *entities,
    sfVector2f *scale)
{
    texture_asset_t *asset = NULL;

    if (!manager || !entities)
        return;
    for (int i = 0; entities[i] != END; i++) {
        if (!is_valid_entity(manager, entities[i]))
            continue;
        asset = &manager->assets[entities[i]];
        scale_single_entity(asset, scale[i]);
    }
}

static void set_single_position(texture_asset_t *asset, sfVector2f position)
{
    if (!asset->sprite)
        return;
    sfSprite_setPosition(asset->sprite, position);
}

void set_position_entities(texture_manager_t *manager, texture_t *entities,
    sfVector2f *positions)
{
    texture_asset_t *asset = NULL;

    if (!manager || !entities || !positions)
        return;
    for (int i = 0; entities[i] != END; i++) {
        if (!is_valid_entity(manager, entities[i]))
            continue;
        asset = &manager->assets[entities[i]];
        set_single_position(asset, positions[i]);
    }
}
