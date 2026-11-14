/*
** EPITECH PROJECT, 2024
** ecs components get/set
** File description:
** ecs components get / set functions
*/

#include "../include/ecs.h"

void ecs_set_pv(ecs_world_t *w, entity_t e, int pv)
{
    int *p;

    if (e < w->entity_count && ecs_array_ensure(&w->pv, e)) {
        p = (int *)ecs_array_get(&w->pv, e);
        if (p) {
            *p = pv;
        }
    }
}

int ecs_get_pv(ecs_world_t *w, entity_t e)
{
    int *p;

    if (e < w->entity_count) {
        p = (int *)ecs_array_get(&w->pv, e);
        if (p) {
            return *p;
        }
    }
    return -1;
}

void ecs_set_texture_path(ecs_world_t *w, entity_t e, int text)
{
    int *p;

    if (e < w->entity_count && ecs_array_ensure(&w->texure_path, e)) {
        p = (int *)ecs_array_get(&w->texure_path, e);
        if (p) {
            *p = text;
        }
    }
}

int ecs_get_texture_path(ecs_world_t *w, entity_t e)
{
    int *p;

    if (e < w->entity_count) {
        p = (int *)ecs_array_get(&w->texure_path, e);
        if (p) {
            return *p;
        }
    }
    return -1;
}
