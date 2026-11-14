/*
** EPITECH PROJECT, 2025
** ecs components get/set
** File description:
** ecs components get / set functions 4
*/

#include "../include/ecs.h"

void ecs_set_active(ecs_world_t *w, entity_t e, bool active)
{
    char *a;

    if (e < w->entity_count && ecs_array_ensure(&w->actives, e)) {
        a = (char *)ecs_array_get(&w->actives, e);
        if (a)
            *a = active ? 1 : 0;
    }
}

bool ecs_get_active(ecs_world_t *w, entity_t e)
{
    char *a;

    if (e < w->entity_count) {
        a = (char *)ecs_array_get(&w->actives, e);
        if (a)
            return *a == 1;
    }
    return false;
}

void ecs_set_hitbox(ecs_world_t *w, entity_t e, hitbox_t hitbox)
{
    float *hb;

    if (e < w->entity_count && ecs_array_ensure(&w->hitboxes, e)) {
        hb = (float *)ecs_array_get(&w->hitboxes, e);
        if (hb) {
            hb[0] = hitbox.x_off;
            hb[1] = hitbox.y_off;
            hb[2] = hitbox.width;
            hb[3] = hitbox.height;
        }
    }
}

void ecs_get_hitbox(ecs_world_t *w, entity_t e, hitbox_t *hitbox)
{
    float *hb;

    if (e < w->entity_count) {
        hb = (float *)ecs_array_get(&w->hitboxes, e);
        if (hb && hitbox) {
            hitbox->x_off = hb[0];
            hitbox->y_off = hb[1];
            hitbox->width = hb[2];
            hitbox->height = hb[3];
        }
    }
}
