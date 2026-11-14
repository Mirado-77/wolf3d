/*
** EPITECH PROJECT, 2025
** ecs init
** File description:
** ecs init
*/

#include "../include/ecs.h"

static bool ecs_init_arrays(ecs_world_t *w)
{
    if (!ecs_array_init(&w->positions, sizeof(float) * 2) ||
        !ecs_array_init(&w->velocities, sizeof(float) * 2) ||
        !ecs_array_init(&w->radius, sizeof(float)) ||
        !ecs_array_init(&w->sprites, sizeof(void *)) ||
        !ecs_array_init(&w->textures, sizeof(void *)) ||
        !ecs_array_init(&w->destinations, sizeof(float) * 2) ||
        !ecs_array_init(&w->delays, sizeof(float)) ||
        !ecs_array_init(&w->actives, sizeof(char)) ||
        !ecs_array_init(&w->hitboxes, sizeof(float) * 4) ||
        !ecs_array_init(&w->rotations, sizeof(float)) ||
        !ecs_array_init(&w->scales, sizeof(float) * 2) ||
        !ecs_array_init(&w->colors, sizeof(uint8_t) * 4) ||
        !ecs_array_init(&w->pv, sizeof(int)) ||
        !ecs_array_init(&w->bosses, sizeof(boss_t)) ||
        !ecs_array_init(&w->texure_path, sizeof(int)))
        return false;
    return true;
}

bool ecs_resize_arrays(ecs_world_t *w, size_t new_cap)
{
    if (!ecs_array_resize(&w->positions, new_cap) ||
        !ecs_array_resize(&w->velocities, new_cap) ||
        !ecs_array_resize(&w->radius, new_cap) ||
        !ecs_array_resize(&w->sprites, new_cap) ||
        !ecs_array_resize(&w->textures, new_cap) ||
        !ecs_array_resize(&w->destinations, new_cap) ||
        !ecs_array_resize(&w->delays, new_cap) ||
        !ecs_array_resize(&w->actives, new_cap) ||
        !ecs_array_resize(&w->hitboxes, new_cap) ||
        !ecs_array_resize(&w->rotations, new_cap) ||
        !ecs_array_resize(&w->scales, new_cap) ||
        !ecs_array_resize(&w->colors, new_cap) ||
        !ecs_array_resize(&w->pv, new_cap) ||
        !ecs_array_resize(&w->bosses, new_cap) ||
        !ecs_array_resize(&w->texure_path, new_cap))
        return false;
    return true;
}

static void free_basic_arrays(ecs_world_t *w)
{
    if (w->positions.data)
        free(w->positions.data);
    if (w->velocities.data)
        free(w->velocities.data);
    if (w->radius.data)
        free(w->radius.data);
    if (w->sprites.data)
        free(w->sprites.data);
    if (w->textures.data)
        free(w->textures.data);
    if (w->destinations.data)
        free(w->destinations.data);
    if (w->pv.data)
        free(w->pv.data);
}

static void free_additional_arrays(ecs_world_t *w)
{
    if (w->delays.data)
        free(w->delays.data);
    if (w->actives.data)
        free(w->actives.data);
    if (w->hitboxes.data)
        free(w->hitboxes.data);
    if (w->rotations.data)
        free(w->rotations.data);
    if (w->scales.data)
        free(w->scales.data);
    if (w->colors.data)
        free(w->colors.data);
}

static void free_all_arrays(ecs_world_t *w)
{
    free_basic_arrays(w);
    free_additional_arrays(w);
}

void ecs_init(ecs_world_t *w)
{
    w->entity_capacity = BASE_CAPACITY;
    w->entity_count = 0;
    w->component_mask = malloc(sizeof(unsigned int) * w->entity_capacity);
    if (!w->component_mask)
        return;
    memset(w->component_mask, 0, sizeof(unsigned int) * w->entity_capacity);
    if (!ecs_init_arrays(w)) {
        free(w->component_mask);
        w->component_mask = NULL;
    }
}

void ecs_destroy(ecs_world_t *w)
{
    if (w->component_mask)
        free(w->component_mask);
    free_all_arrays(w);
    memset(w, 0, sizeof(*w));
}
