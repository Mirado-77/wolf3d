/*
** EPITECH PROJECT, 2024
** ecs utilities
** File description:
** utilities for ecs
*/

#include "../include/ecs.h"

bool ecs_array_init(ecs_array_t *a, size_t elem_size)
{
    a->elem_size = elem_size;
    a->count = 0;
    a->capacity = 1000;
    a->data = malloc(a->capacity * a->elem_size);
    if (!a->data)
        return false;
    memset(a->data, 0, a->capacity * a->elem_size);
    return true;
}

bool ecs_array_resize(ecs_array_t *a, size_t new_cap)
{
    void *new_data = malloc(new_cap * a->elem_size);
    size_t i;
    char *old_elem_pos;
    char *new_elem_pos;

    if (new_cap <= a->capacity)
        return true;
    if (!new_data)
        return false;
    memset(new_data, 0, new_cap * a->elem_size);
    for (i = 0; i < a->count; i++) {
        old_elem_pos = (char *)a->data + i * a->elem_size;
        new_elem_pos = (char *)new_data + i * a->elem_size;
        for (size_t j = 0; j < a->elem_size; j++)
            new_elem_pos[j] = old_elem_pos[j];
    }
    free(a->data);
    a->data = new_data;
    a->capacity = new_cap;
    return true;
}

bool ecs_array_ensure(ecs_array_t *a, size_t index)
{
    size_t new_cap;

    if (index < a->capacity)
        return true;
    new_cap = a->capacity * 2;
    while (new_cap <= index)
        new_cap *= 2;
    return ecs_array_resize(a, new_cap);
}

void *ecs_array_get(ecs_array_t *a, size_t index)
{
    if (index >= a->capacity)
        return NULL;
    return (char *)a->data + index * a->elem_size;
}
