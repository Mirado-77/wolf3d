/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** boss
*/
#include "wolf.h"
#include "boss.h"
#include "object.h"

static void change_boss_state(boss_t *b, boss_state_t next)
{
    b->state = next;
    b->state_timer = 0.f;
    b->atk_timer = 0.f;
}

void st_idle(wolf_t *wolf, boss_t *b, float dt)
{
    boss_state_t next;
    entity_t boss = ecs_first(&wolf->world, COMP_BOSS);
    double distance = calcul_distance(wolf, boss, wolf->ctx);

    b->state_timer += dt;
    if (b->state_timer > 3.5f && distance <= DISTANCE) {
        next = BOSS_ATTACK_MELEE;
        change_boss_state(b, next);
    }
}

void st_melee(wolf_t *wolf, boss_t *b, float dt)
{
    b->state_timer += dt;
    b->atk_timer += dt;
    if (b->atk_timer > 1.f) {
        perform_melee(wolf);
        b->atk_timer = 0.f;
    }
    if (b->state_timer > 3.f && b->state != BOSS_ENRAGED)
        change_boss_state(b, BOSS_IDLE);
}

void st_enraged(wolf_t *wolf, boss_t *b, float dt)
{
    boss_state_t next;
    entity_t boss = ecs_first(&wolf->world, COMP_BOSS);
    double distance = calcul_distance(wolf, boss, wolf->ctx);

    (void)wolf;
    b->state_timer += dt;
    if (b->state_timer > 2.5f && distance <= DISTANCE_RANGE) {
        wolf->player.health -= DISTANCE_DAMAGE;
    }
    if (b->state_timer > 3.5f) {
        next = BOSS_ATTACK_MELEE_ENRAGED;
        change_boss_state(b, next);
    }
}

void st_melee_enraged(wolf_t *wolf, boss_t *b, float dt)
{
    b->state_timer += dt;
    b->atk_timer += dt;
    if (b->atk_timer > 0.8f) {
        perform_melee(wolf);
        b->atk_timer = 0.f;
    }
    if (b->state_timer > 3.f)
        change_boss_state(b, BOSS_ENRAGED);
}

void boss_update(wolf_t *wolf, float dt)
{
    const entity_t boss_entity = ecs_first(&wolf->world, COMP_BOSS);
    boss_t *boss;
    texture_t boss_enum[] = {BOSS_FILLER, END};

    if (!ecs_is_valid_entity(&wolf->world, boss_entity))
        return;
    boss = ecs_get_boss(&wolf->world, boss_entity);
    if (!boss)
        return;
    boss->hp = ecs_get_pv(&wolf->world, boss_entity);
    handle_boss_bar(wolf, boss_enum, RECT_TEXTURE);
    if (boss->hp < boss->max_hp * 0.5f && boss->state != BOSS_ENRAGED &&
        boss->state != BOSS_ATTACK_MELEE_ENRAGED)
        change_boss_state(boss, BOSS_ENRAGED);
    BOSS_STATE_HANDLER[boss->state](wolf, boss, dt);
    if (boss->hp < 0) {
        ecs_set_pv(&wolf->world, boss_entity, DEAD_KEY);
        ecs_remove_entity(&wolf->world, boss_entity);
    }
}
