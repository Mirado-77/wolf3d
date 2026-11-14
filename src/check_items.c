/*
** EPITECH PROJECT, 2025
** check_items
** File description:
** check items in map
*/

#include "wolf.h"
#include "object.h"
#include "ennemies.h"
#include "ecs.h"
#include "raycasting.h"

static void check_type(wolf_t *w, cast_t *cast, ray_context_t *ctx, int type)
{
    if (type == IS_POT_MANA) {
        ctx->player->invetory.pot_mana = true;
        ecs_set_pv(&w->world, cast->entity, DEAD_KEY);
    }
    if (type == IS_KEY) {
        ctx->player->invetory.key = true;
        ecs_set_pv(&w->world, cast->entity, DEAD_KEY);
        ecs_remove_entity(&w->world, cast->entity);
    }
    if (type == IS_POT_PV) {
        ctx->player->invetory.pot_pv = true;
        ecs_set_pv(&w->world, cast->entity, DEAD_KEY);
    }
}

static void check_items_pos(wolf_t *w, cast_t *cast, ray_context_t *ctx)
{
    float2_t pos = {0, 0};
    int type = 0;

    ecs_get_position(&w->world, cast->entity, &pos.x, &pos.y);
    type = ecs_get_texture_path(&w->world, cast->entity);
    if ((int)ctx->player->x == (int)pos.x
        && (int)ctx->player->y == (int)pos.y) {
            check_type(w, cast, ctx, type);
    }
}

void check_items(wolf_t *w, ray_context_t *ctx)
{
    for (size_t i = 0; i < w->ennemies.nb_ennemies; i++) {
        if (ecs_get_texture_path(&w->world, w->ennemies.cast[i].entity)
            > IS_BOSS) {
                check_items_pos(w, &w->ennemies.cast[i], ctx);
            }
    }
}

static void check_items_to_redraw(wolf_t *w, cast_t *cast)
{
    int pv = ecs_get_pv(&w->world, cast->entity);
    float fps = sfTime_asSeconds(sfClock_getElapsedTime(cast->clock));

    if (fps > 15 && pv <= DEAD_KEY
        && ecs_get_texture_path(&w->world, cast->entity) != IS_KEY){
            ecs_set_pv(&w->world, cast->entity, ALIVE_KEY);
            ecs_set_active(&w->world, cast->entity, true);
    }
}

void redraw_items(wolf_t *w)
{
    for (size_t i = 0; i < w->ennemies.nb_ennemies; i++) {
        if (ecs_get_texture_path(&w->world, w->ennemies.cast[i].entity)
            > IS_BOSS) {
                check_items_to_redraw(w, &w->ennemies.cast[i]);
            }
    }
}
