/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** input_handler
*/

#ifndef INPUT_HANDLER_H
    #define INPUT_HANDLER_H

    #include <SFML/Graphics.h>
    #include "player.h"
    #include "wolf.h"
    #include "map.h"

    #define MIN_ENNEMY_DIST 1.0f
    #define MOVE_SPEED 2.0f
    #define CAM_SENSITIVITY 4.0f
    #define SPRINT_FACTOR 2.8f
    #define STAMINA_CONSUMPTION 0.8f

void switch_weapon(player_t *player, float speed, map_t *map, wolf_t *wolf);
void move_forward(player_t *player, float speed, map_t *m, wolf_t *wolf);
void move_backward(player_t *player, float speed, map_t *m, wolf_t *wolf);
void move_left(player_t *player, float speed, map_t *m, wolf_t *wolf);
void move_right(player_t *player, float speed, map_t *m, wolf_t *wolf);
void switch_torch(player_t *player, float speed, map_t *m, wolf_t *wolf);
void consume_health_bottle(player_t *player, float speed, map_t *m,
    wolf_t *wolf);
void consume_mana_bottle(player_t *player, float speed, map_t *m,
    wolf_t *wolf);
void consume_mana_bottle(player_t *player, float speed, map_t *m,
    wolf_t *wolf);
void consume_key(player_t *player);
void toggle_kd_hud(player_t *player, float speed, map_t *m, wolf_t *wolf);

typedef void (*action_func_t)(player_t *, float, map_t *, wolf_t *);

typedef struct {
    sfKeyCode code;
    action_func_t func;
} key_action_t;

static const key_action_t actions[] = {
    {sfKeyZ, &move_forward},
    {sfKeyS, &move_backward},
    {sfKeyD, &move_right},
    {sfKeyQ, &move_left},
    {sfKeyA, &switch_weapon},
    {sfKeyR, &switch_torch},
    {sfKeyL, &consume_health_bottle},
    {sfKeyM, &consume_mana_bottle},
    {sfKeyTab, &toggle_kd_hud},
};

void handle_events(sfRenderWindow *window, wolf_t *wolf3d);
void process_input(player_t *player, float dt,
    wolf_t *wolf, weapon_sys_t *weapons);

#endif
