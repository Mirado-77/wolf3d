/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_ennemies
*/

#include "boss.h"
#include "wolf.h"
#include "stdbool.h"
#include "ennemies.h"
#include "object.h"
#include <stdio.h>
#include <stdlib.h>

entity_t create_boss_entity(ecs_world_t *w, float x, float y)
{
    entity_t e = ecs_create_entity(w);
    boss_t data = {0};

    ecs_add_component(w, e, COMP_POSITION | COMP_ACTIVE | COMP_PV
        | COMP_TEXTURE | COMP_BOSS | COMP_TEXTURE_PATH);
    ecs_set_position(w, e, x, y);
    ecs_set_pv(w, e, BOSS_HP);
    data.max_hp = BOSS_HP;
    data.hp = BOSS_HP;
    data.state = BOSS_IDLE;
    data.state_timer = 0.f;
    data.atk_timer = 0.f;
    ecs_set_boss(w, e, data);
    ecs_set_active(w, e, true);
    return e;
}

static entity_t create_enemies_object(ecs_world_t *w,
    float x, float y)
{
    entity_t e = ecs_create_entity(w);

    ecs_add_component(w, e, COMP_POSITION | COMP_ACTIVE
        | COMP_PV | COMP_TEXTURE_PATH);
    ecs_set_position(w, e, x, y);
    ecs_set_active(w, e, false);
    ecs_set_pv(w, e, ALIVE_KEY);
    return e;
}

void create_ennemies_entity(ecs_world_t *w, char *line)
{
    entity_t e = 0;
    float2_t pos;
    int texture;

    sscanf(line, "%f %f %d", &pos.x, &pos.y, &texture);
    if (texture == 1) {
        e = create_boss_entity(w, pos.x, pos.y);
        ecs_set_texture_path(w, e, texture);
        return;
    }
    e = create_enemies_object(w, pos.x, pos.y);
    ecs_set_texture_path(w, e, texture);
}

void add_entity_to_list(wolf_t *wolf3d, size_t count)
{
    entity_t entity = 0;
    size_t i = 0;
    int text_path = 0;

    wolf3d->ennemies.cast = malloc(sizeof(cast_t) * count);
    if (!wolf3d->ennemies.cast) {
        return;
    }
    entity = ecs_first(&wolf3d->world, COMP_POSITION | COMP_ACTIVE | COMP_PV);
    while (entity != (entity_t)-1) {
        text_path = ecs_get_texture_path(&wolf3d->world, entity);
        wolf3d->ennemies.cast[i].entity = entity;
        memset(&wolf3d->ennemies.cast[i].sprite, 0, sizeof(sprite_t));
        wolf3d->ennemies.cast[i].sprite.vilain_texture =
            sfTexture_createFromFile(anime[text_path].texture_path, NULL);
        wolf3d->ennemies.cast[i].clock = sfClock_create();
        entity = ecs_next(&wolf3d->world,
            COMP_POSITION | COMP_ACTIVE | COMP_PV, entity);
        i++;
    }
}
