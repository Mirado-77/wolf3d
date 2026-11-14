/*
** EPITECH PROJECT, 2025
** ecs components get/set
** File description:
** ecs components get / set functions 3
*/

#include "../include/ecs.h"

void ecs_set_destination(ecs_world_t *w, entity_t e, float dx, float dy)
{
    float *d;

    if (e < w->entity_count && ecs_array_ensure(&w->destinations, e)) {
        d = (float *)ecs_array_get(&w->destinations, e);
        if (d) {
            d[0] = dx;
            d[1] = dy;
        }
    }
}

void ecs_get_destination(ecs_world_t *w, entity_t e, float *dx, float *dy)
{
    float *d;

    if (e < w->entity_count) {
        d = (float *)ecs_array_get(&w->destinations, e);
        if (d) {
            *dx = d[0];
            *dy = d[1];
        }
    }
}

void ecs_set_delay(ecs_world_t *w, entity_t e, float delay_time)
{
    float *dt;

    if (e < w->entity_count && ecs_array_ensure(&w->delays, e)) {
        dt = (float *)ecs_array_get(&w->delays, e);
        if (dt)
            *dt = delay_time;
    }
}

float ecs_get_delay(ecs_world_t *w, entity_t e)
{
    float *dt;

    if (e < w->entity_count) {
        dt = (float *)ecs_array_get(&w->delays, e);
        if (dt)
            return *dt;
    }
    return 0.0f;
}
