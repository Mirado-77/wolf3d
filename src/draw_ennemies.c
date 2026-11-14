/*
** EPITECH PROJECT, 2025
** draw ennemies
** File description:
** display ennemies
*/

#include "wolf.h"
#include "object.h"
#include "ennemies.h"
#include "raycasting.h"

static void swap(cast_t *xp, cast_t *yp)
{
    cast_t temp = *xp;

    *xp = *yp;
    *yp = temp;
}

static int partition(wolf_t *wolf3d,
    ray_context_t *ctx, size_t low, size_t high)
{
    double pivot = calcul_distance(wolf3d,
        wolf3d->ennemies.cast[high].entity, ctx);
    size_t i = low - 1;

    for (size_t j = low; j <= high - 1; j++) {
        if (calcul_distance(wolf3d,
            wolf3d->ennemies.cast[j].entity, ctx) > pivot) {
                i++;
                swap(&wolf3d->ennemies.cast[i],
                &wolf3d->ennemies.cast[j]);
        }
    }
    swap(&wolf3d->ennemies.cast[i + 1],
        &wolf3d->ennemies.cast[high]);
    return i + 1;
}

static void quick_sort(wolf_t *wolf3d, ray_context_t *ctx, int low, int high)
{
    size_t pi = 0;

    if (low < high) {
        pi = partition(wolf3d, ctx, low, high);
        quick_sort(wolf3d, ctx, low, pi - 1);
        quick_sort(wolf3d, ctx, pi + 1, high);
    }
}

void draw_animation(wolf_t *wolf3d, ray_context_t *ctx, int i)
{
    float2_t pos = {0, 0};
    int texture_index = 0;
    bool active = false;

    ecs_get_position(&wolf3d->world,
            wolf3d->ennemies.cast[i].entity, &pos.x, &pos.y);
    texture_index = ecs_get_texture_path(&wolf3d->world,
        wolf3d->ennemies.cast[i].entity);
    active = ecs_get_active(&wolf3d->world, wolf3d->ennemies.cast[i].entity);
    if (calcul_distance(wolf3d, wolf3d->ennemies.cast[i].entity, ctx)
        < DISTANCE && texture_index == IS_ENEMIE && active == true) {
        move_ennemie(wolf3d, ctx, wolf3d->ennemies.cast[i].entity, pos);
    }
    load_animation(wolf3d, &wolf3d->ennemies.cast[i], texture_index);
    cast_ennemies(ctx, pos, wolf3d->ennemies.cast[i].sprite,
        anime[texture_index].sprite_widght);
}

void draw_ennemies(wolf_t *wolf3d, ray_context_t *ctx)
{
    int pv = 0;

    quick_sort(wolf3d, ctx, 0, wolf3d->ennemies.nb_ennemies - 1);
    for (int i = 0; i < (int)wolf3d->ennemies.nb_ennemies; i++) {
        pv = ecs_get_pv(&wolf3d->world, wolf3d->ennemies.cast[i].entity);
        if (pv == DEAD_KEY) {
            continue;
        }
        draw_animation(wolf3d, ctx, i);
    }
}
