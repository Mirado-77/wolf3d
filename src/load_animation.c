/*
** EPITECH PROJECT, 2025
** load_animation
** File description:
** e
*/

#include "wolf.h"
#include "object.h"
#include "ennemies.h"
#include <stdio.h>


static void advance_boss_frame(wolf_t *wolf3d, cast_t *sprite)
{
    const boss_t *b = ecs_get_boss(&wolf3d->world, sprite->entity);
    const anim_span_t span = boss_spans[b->state];
    const int frame_px = anime[IS_BOSS].sprite_widght;
    const int first_px = span.start * frame_px;
    const int last_px_incl = (span.start + span.count - 1) * frame_px;

    if (sprite->sprite.add_in_rect < first_px ||
        sprite->sprite.add_in_rect > last_px_incl) {
        sprite->sprite.add_in_rect = first_px;
        return;
    }
    sprite->sprite.add_in_rect += frame_px;
    if (sprite->sprite.add_in_rect > last_px_incl)
        sprite->sprite.add_in_rect = first_px;
}

static void load_boss_animation(wolf_t *wolf3d, cast_t *sprite)
{
    const float elapsed =
        sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock));

    if (elapsed < 0.1f)
        return;
    advance_boss_frame(wolf3d, sprite);
    sfClock_restart(sprite->clock);
}

void load_vilain_animation(wolf_t *wolf3d, cast_t *sprite, int index)
{
    int pv = ecs_get_pv(&wolf3d->world, sprite->entity);
    int add = anime[index].sprite_widght;
    int tex_widght = anime[index].text_widght;
    float fps = sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock));
    double distance = calcul_distance(wolf3d, sprite->entity, wolf3d->ctx);

    if (fps > 0.1 && pv > 0 && distance <= DISTANCE && !ecs_get_active(&wolf3d->world, sprite->entity)){
        sprite->sprite.add_in_rect += add;
        if (sprite->sprite.add_in_rect >= add * 11) {
            sprite->sprite.add_in_rect = add * 11;
            ecs_set_active(&wolf3d->world, sprite->entity, true);
        }
        sfClock_restart(sprite->clock);
    }
    if (fps > 0.1 && pv > 0 && ecs_get_active(&wolf3d->world, sprite->entity)) {
        sprite->sprite.add_in_rect += add;
        if (sprite->sprite.add_in_rect >= add * 17)
            sprite->sprite.add_in_rect = add *11;
        sfClock_restart(sprite->clock);
    }
    if (fps > 0.1 && pv <= 0){
        ecs_set_active(&wolf3d->world, sprite->entity, false);
        sprite->sprite.add_in_rect += add;
        if (sprite->sprite.add_in_rect >= tex_widght - add) {
            sprite->sprite.add_in_rect = tex_widght;
            ecs_set_pv(&wolf3d->world, sprite->entity, DEAD_KEY);
            ecs_remove_entity(&wolf3d->world, sprite->entity);
        }
        sfClock_restart(sprite->clock);
    }
}

static void load_object_animation(wolf_t *wolf3d, cast_t *sprite, int index)
{
    int pv = ecs_get_pv(&wolf3d->world, sprite->entity);
    int add = anime[index].sprite_widght;
    int tex_widght = anime[index].text_widght;
    float fps = sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock));

    if (fps > 0.1 && pv >= 0){
        sprite->sprite.add_in_rect += add;
        if (sprite->sprite.add_in_rect >= tex_widght - add)
            sprite->sprite.add_in_rect = 0;
        sfClock_restart(sprite->clock);
    }
}

static void load_genie_animation(wolf_t *wolf3d, cast_t *sprite, int index)
{
    int pv = ecs_get_pv(&wolf3d->world, sprite->entity);
    int add = anime[index].sprite_widght;
    int tex_widght = anime[index].text_widght;
    float fps = sfTime_asSeconds(sfClock_getElapsedTime(sprite->clock));
    double distance = calcul_distance(wolf3d, sprite->entity, wolf3d->ctx);

    if (distance <= 5) {
        ecs_set_active(&wolf3d->world, sprite->entity, true);
    }
    if (fps > 0.1 && pv > 0 && ecs_get_active(&wolf3d->world, sprite->entity)){
        sprite->sprite.add_in_rect += add;
        if (sprite->sprite.add_in_rect >= tex_widght) {
            sprite->sprite.add_in_rect = add * 10;
        }
        sfClock_restart(sprite->clock);
    }
}

void load_animation(wolf_t *wolf3d, cast_t *sprite, int index)
{
    if (index == IS_ENEMIE) {
        load_vilain_animation(wolf3d, sprite, index);
    }
    if (index == IS_BOSS) {
        load_boss_animation(wolf3d, sprite);
        return;
    }
    if (index == IS_GENIE) {
       load_genie_animation(wolf3d, sprite, index);
       return;
    }
    if (index > IS_BOSS && index != IS_GENIE) {
       load_object_animation(wolf3d, sprite, index);
   }
}
