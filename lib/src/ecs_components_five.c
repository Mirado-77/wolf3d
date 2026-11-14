/*
** EPITECH PROJECT, 2025
** ecs components get/set
** File description:
** ecs components get / set functions 5
*/

#include "../include/ecs.h"

void ecs_set_rotation(ecs_world_t *w, entity_t e, float angle)
{
    float *ang;

    if (e < w->entity_count && ecs_array_ensure(&w->rotations, e)) {
        ang = (float *)ecs_array_get(&w->rotations, e);
        if (ang)
            *ang = angle;
    }
}

float ecs_get_rotation(ecs_world_t *w, entity_t e)
{
    float *ang;

    if (e < w->entity_count) {
        ang = (float *)ecs_array_get(&w->rotations, e);
        if (ang)
            return *ang;
    }
    return 0.0f;
}

void ecs_set_scale(ecs_world_t *w, entity_t e, float sx, float sy)
{
    float *s;

    if (e < w->entity_count && ecs_array_ensure(&w->scales, e)) {
        s = (float *)ecs_array_get(&w->scales, e);
        if (s) {
            s[0] = sx;
            s[1] = sy;
        }
    }
}

void ecs_get_scale(ecs_world_t *w, entity_t e, float *sx, float *sy)
{
    float *s;

    if (e < w->entity_count) {
        s = (float *)ecs_array_get(&w->scales, e);
        if (s) {
            *sx = s[0];
            *sy = s[1];
        }
    }
}
