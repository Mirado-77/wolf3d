/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** weapon
*/
#ifndef WEAPONS_H
    #define WEAPONS_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "crosshair.h"

    #define DAMAGE 10.0f
    #define COOLDOWN 0.4f
    #define HAND_POS_X_OFFSET 40
    #define HAND_POS_Y_OFFSET 233
    #define IDLE_HAND "assets/spells/free_hands.png"
    #define SPELL_1_1 "assets/spells/spell_1_1.png"
    #define SPELL_1_2 "assets/spells/spell_1_2.png"
    #define SPELL_1_3 "assets/spells/spell_1_3.png"
    #define SPELL_2_1 "assets/spells/spell_2_1.png"
    #define SPELL_2_2 "assets/spells/spell_2_2.png"
    #define SPELL_2_3 "assets/spells/spell_2_3.png"
    #define SPELL_LIGHT "assets/spells/torch_player.png"

typedef enum {
    SPELL_1,
    SPELL_2,
    SPELL_MAX
} weapon_id_t;

typedef struct weapon_s {
    sfTexture *idle;
    sfTexture *atk[3];
    float cooldown;
    float damage;
    crosshair_t crosshair;
} weapon_t;

typedef struct {
    weapon_t list[SPELL_MAX];
    weapon_id_t current;
    sfClock *clock;
    bool attacking;
} weapon_sys_t;

bool weapon_init(weapon_sys_t *weapon_sys);
void weapon_destroy(const weapon_sys_t *weapon_sys);

void weapon_trigger(weapon_sys_t *weapon_sys);
void weapon_draw(const weapon_sys_t *weapon_sys, sfRenderWindow *win,
    int screenW, int screenH);

#endif
