/*
** EPITECH PROJECT, 2024
** ecs components get/set
** File description:
** ecs components get / set functions
*/

#include "../include/ecs.h"

void ecs_set_position(ecs_world_t *w, entity_t e, float x, float y)
{
    float *p;

    if (e < w->entity_count && ecs_array_ensure(&w->positions, e)) {
        p = (float *)ecs_array_get(&w->positions, e);
        if (p) {
            p[0] = x;
            p[1] = y;
        }
    }
}

void ecs_get_position(ecs_world_t *w, entity_t e, float *x, float *y)
{
    float *p;

    if (e < w->entity_count) {
        p = (float *)ecs_array_get(&w->positions, e);
        if (p) {
            *x = p[0];
            *y = p[1];
        }
    }
}

void ecs_set_velocity(ecs_world_t *w, entity_t e, float vx, float vy)
{
    float *v;

    if (e < w->entity_count && ecs_array_ensure(&w->velocities, e)) {
        v = (float *)ecs_array_get(&w->velocities, e);
        if (v) {
            v[0] = vx;
            v[1] = vy;
        }
    }
}

void ecs_get_velocity(ecs_world_t *w, entity_t e, float *vx, float *vy)
{
    float *v;

    if (e < w->entity_count) {
        v = (float *)ecs_array_get(&w->velocities, e);
        if (v) {
            *vx = v[0];
            *vy = v[1];
        }
    }
}
