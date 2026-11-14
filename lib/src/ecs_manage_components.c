/*
** EPITECH PROJECT, 2025
** manage comp
** File description:
** manage comps
*/

#include "../include/ecs.h"

void ecs_add_component(ecs_world_t *w, entity_t e, unsigned int comp)
{
    if (e < w->entity_count)
        w->component_mask[e] |= comp;
}

void ecs_remove_component(ecs_world_t *w, entity_t e, unsigned int comp)
{
    if (e < w->entity_count)
        w->component_mask[e] &= ~comp;
}

bool ecs_has_component(ecs_world_t *w, entity_t e, unsigned int comp)
{
    if (e >= w->entity_count)
        return false;
    return (w->component_mask[e] & comp) == comp;
}
