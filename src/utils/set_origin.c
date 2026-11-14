/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** set_origin
*/

#include "wolf.h"

static void center_origin_single_entity(texture_asset_t *asset)
{
    sfIntRect rect;
    sfVector2f origin;

    if (!asset || !asset->sprite || asset->is_loaded == false)
        return;
    rect = sfSprite_getTextureRect(asset->sprite);
    origin.x = rect.width / 2.0f;
    origin.y = rect.height / 2.0f;
    sfSprite_setOrigin(asset->sprite, origin);
}

void center_origin_entities(texture_manager_t *manager, texture_t *entities)
{
    texture_asset_t *asset = NULL;

    if (!manager || !entities)
        return;
    for (int i = 0; entities[i] != END; i++) {
        if (!is_valid_entity(manager, entities[i]))
            continue;
        asset = &manager->assets[entities[i]];
        center_origin_single_entity(asset);
    }
}
