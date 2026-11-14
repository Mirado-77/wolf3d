/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** boss
*/

#ifndef BOSS_H_
    #define BOSS_H_
    #include "wolf.h"

    #define BOSS_HP 1500
    #define BOSS_DASH_DIST 3.f
    #define MELEE_RANGE 1.4f
    #define DISTANCE_RANGE 20.f
    #define DISTANCE_DAMAGE 1.f
    #define MELEE_DAMAGE 20.f

typedef void (*boss_state_fn_t)(wolf_t *wolf, boss_t *boss, float dt);

void perform_melee(wolf_t *wolf);
void distance_attack(wolf_t *wolf);

void st_idle(wolf_t *wolf, boss_t *b, float dt);
void st_melee(wolf_t *wolf, boss_t *b, float dt);
void st_distance(wolf_t *wolf, boss_t *b, float dt);
void st_enraged(wolf_t *wolf, boss_t *b, float dt);
void st_melee_enraged(wolf_t *wolf, boss_t *b, float dt);

static const boss_state_fn_t BOSS_STATE_HANDLER[BOSS_STATE_COUNT] = {
    [BOSS_IDLE] = &st_idle,
    [BOSS_ATTACK_MELEE] = &st_melee,
    [BOSS_ENRAGED] = &st_enraged,
    [BOSS_ATTACK_MELEE_ENRAGED] = &st_melee_enraged,
};

void boss_update(wolf_t *wolf, float dt);
entity_t create_boss(ecs_world_t *w, float x, float y);

#endif /* BOSS_H_ */
