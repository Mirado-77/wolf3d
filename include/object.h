/*
** EPITECH PROJECT, 2025
** object.h
** File description:
** object texture and animation
*/


#ifndef OBJECT_H_
    #define OBJECT_H_
    #include <SFML/Graphics.h>
    #include <stddef.h>
    #include "wolf.h"

typedef enum {
    IS_ENEMIE = 0,
    IS_BOSS = 1,
    IS_KEY = 2,
    IS_POT_MANA = 3,
    IS_POT_PV = 4,
    IS_MASTER = 5,
    IS_GENIE = 6,
    IS_FIRE = 7,
} is_object_t;

    #define SPEED 0.04

typedef struct {
    char *texture_path;
    int text_widght;
    int sprite_widght;
    int nb_frame;
} animation_t;

static const animation_t anime[] = {
    {"assets/Monster.png", 2048, 64, 32},
    {"assets/boss/boss_atlas_64.png", 10880, 128, 86},
    {"assets/key.png", 704, 64, 11},
    {"assets/pot_mana.png", 512, 64, 8},
    {"assets/pot_pv.png", 512, 64, 8},
    {"assets/Master.png", 643, 64, 10},
    {"assets/genie.png", 768, 64, 12},
    {"assets/fire.png", 3834, 64, 15}
};

typedef struct {
    int start;
    int count;
} anim_span_t;

static const anim_span_t boss_spans[BOSS_STATE_COUNT] = {
    [BOSS_IDLE] = {0, 6},
    [BOSS_ATTACK_MELEE] = {6, 32},
    [BOSS_ENRAGED] = {38, 16},
    [BOSS_ATTACK_MELEE_ENRAGED] = {54, 32},
};

void load_vilain_animation(wolf_t *wolf3d, cast_t *sprite, int index);
void load_animation(wolf_t *wolf3d, cast_t *sprite, int index);
void move_ennemie(wolf_t *wolf3d, ray_context_t *ctx,
    entity_t e, float2_t pos);
void draw_invetory(wolf_t *wolf3d);

#endif /* !OBJECT_H_! */
