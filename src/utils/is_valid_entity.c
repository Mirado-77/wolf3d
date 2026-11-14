/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** is_valid_entity
*/

#include "wolf.h"

bool is_valid_entity(texture_manager_t *manager, texture_t entity)
{
    if ((entity < 0 || entity >= (texture_t)manager->count)
        && manager->assets[entity].is_loaded == false)
            return false;
    return true;
}
