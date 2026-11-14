/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** ecs_boss_component
*/

#include "../include/ecs.h"

void ecs_set_boss(ecs_world_t *w, entity_t e, boss_t data)
{
    ecs_add_component(w, e, COMP_BOSS);
    ecs_array_ensure(&w->bosses, e);
    ((boss_t *)w->bosses.data)[e] = data;
}

boss_t *ecs_get_boss(ecs_world_t *w, entity_t e)
{
    if (!ecs_has_component(w, e, COMP_BOSS))
        return NULL;
    return &((boss_t *)w->bosses.data)[e];
}
