/*
** EPITECH PROJECT, 2025
** ecs components get/set
** File description:
** ecs components get / set functions 6
*/

#include "../include/ecs.h"

void ecs_set_color(ecs_world_t *w, entity_t e, color_t color)
{
    uint8_t *c;

    if (e < w->entity_count && ecs_array_ensure(&w->colors, e)) {
        c = (uint8_t *)ecs_array_get(&w->colors, e);
        if (c) {
            c[0] = color.r;
            c[1] = color.g;
            c[2] = color.b;
            c[3] = color.a;
        }
    }
}

void ecs_get_color(ecs_world_t *w, entity_t e, color_t *color)
{
    uint8_t *c;

    if (e < w->entity_count) {
        c = (uint8_t *)ecs_array_get(&w->colors, e);
        if (c && color) {
            color->r = c[0];
            color->g = c[1];
            color->b = c[2];
            color->a = c[3];
        }
    }
}

void ecs_set_radius(ecs_world_t *w, entity_t e, float r)
{
    float *radius;

    if (e < w->entity_count && ecs_array_ensure(&w->radius, e)) {
        radius = (float *)ecs_array_get(&w->radius, e);
        if (radius)
            *radius = r;
    }
}

float ecs_get_radius(ecs_world_t *w, entity_t e)
{
    float *radius;

    if (e < w->entity_count) {
        radius = (float *)ecs_array_get(&w->radius, e);
        if (radius)
            return *radius;
    }
    return 0.0f;
}
