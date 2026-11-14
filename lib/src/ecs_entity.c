/*
** EPITECH PROJECT, 2025
** ecs entity
** File description:
** ecs entity
*/

#include "../include/ecs.h"
#include <stdio.h>

static bool ecs_grow(ecs_world_t *w)
{
    size_t new_cap = w->entity_capacity * 2;
    unsigned int *new_mask = malloc(sizeof(unsigned int) * new_cap);

    if (!new_mask)
        return false;
    memset(new_mask, 0, new_cap * sizeof(unsigned int));
    for (size_t i = 0; i < w->entity_count; i++)
        new_mask[i] = w->component_mask[i];
    free(w->component_mask);
    w->component_mask = new_mask;
    w->entity_capacity = new_cap;
    return ecs_resize_arrays(w, new_cap);
}

entity_t ecs_first(ecs_world_t *w, unsigned int comp_mask)
{
    for (size_t i = 0; i < w->entity_count; i++) {
        if ((w->component_mask[i] & comp_mask) == comp_mask)
            return (entity_t)i;
    }
    return (entity_t)-1;
}

entity_t ecs_next(ecs_world_t *w, unsigned int comp_mask, entity_t current)
{
    for (size_t i = current + 1; i < w->entity_count; i++) {
        if ((w->component_mask[i] & comp_mask) == comp_mask)
            return (entity_t)i;
    }
    return (entity_t)-1;
}

bool ecs_is_valid_entity(ecs_world_t *w, entity_t e)
{
    return (e < w->entity_count);
}

entity_t ecs_create_entity(ecs_world_t *w)
{
    if (w->entity_count == w->entity_capacity) {
        if (!ecs_grow(w))
            return (entity_t)-1;
    }
    w->component_mask[w->entity_count] = 0;
    w->entity_count++;
    return w->entity_count - 1;
}

void ecs_remove_entity(ecs_world_t *w, entity_t e)
{
    if (e >= w->entity_count)
        return;
    w->component_mask[e] = 0;
}
