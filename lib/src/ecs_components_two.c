/*
** EPITECH PROJECT, 2025
** ecs components get/set
** File description:
** ecs components get / set functions 2
*/

#include "../include/ecs.h"

void ecs_set_sprite(ecs_world_t *w, entity_t e, void *sprite)
{
    void **s;

    if (e < w->entity_count && ecs_array_ensure(&w->sprites, e)) {
        s = (void **)ecs_array_get(&w->sprites, e);
        if (s)
            *s = sprite;
    }
}

void *ecs_get_sprite(ecs_world_t *w, entity_t e)
{
    void **s;

    if (e < w->entity_count) {
        s = (void **)ecs_array_get(&w->sprites, e);
        if (s)
            return *s;
    }
    return NULL;
}

void ecs_set_texture(ecs_world_t *w, entity_t e, void *tex)
{
    void **t;

    if (e < w->entity_count && ecs_array_ensure(&w->textures, e)) {
        t = (void **)ecs_array_get(&w->textures, e);
        if (t)
            *t = tex;
    }
}

void *ecs_get_texture(ecs_world_t *w, entity_t e)
{
    void **t;

    if (e < w->entity_count) {
        t = (void **)ecs_array_get(&w->textures, e);
        if (t)
            return *t;
    }
    return NULL;
}
