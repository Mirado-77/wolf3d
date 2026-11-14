/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** set_rotation
*/

#include "wolf.h"

static void rotate_single_entity(texture_asset_t *asset, float angle)
{
    if (!asset || !asset->sprite || asset->is_loaded == false)
        return;
    sfSprite_setRotation(asset->sprite, angle);
}

void rotate_entities(texture_manager_t *manager, texture_t *entities,
    float angle)
{
    texture_asset_t *asset = NULL;

    if (!manager || !entities)
        return;
    for (int i = 0; entities[i] != END; i++) {
        if (!is_valid_entity(manager, entities[i]))
            continue;
        asset = &manager->assets[entities[i]];
        rotate_single_entity(asset, angle);
    }
}
