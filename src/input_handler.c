/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** input_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include "wolf.h"
#include "input_handler.h"

void handle_events(sfRenderWindow *window, wolf_t *wolf3d)
{
    sfEvent event;

    if (!window || !wolf3d)
        return;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (!sfRenderWindow_hasFocus(window))
            return;
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return;
        }
        handle_click(wolf3d, event);
    }
}

static void rotate(player_t *player, float angle)
{
    float old_dir_x = player->dirX;
    float old_plane_x = player->planeX;
    float cos_angle = cosf(angle);
    float sin_angle = sinf(angle);

    player->dirX = player->dirX * cos_angle - player->dirY * sin_angle;
    player->dirY = old_dir_x * sin_angle + player->dirY * cos_angle;
    player->planeX = player->planeX * cos_angle - player->planeY * sin_angle;
    player->planeY = old_plane_x * sin_angle + player->planeY * cos_angle;
}

void process_joystick(player_t *player, float dt,
    wolf_t *wolf, weapon_sys_t *weapons)
{
    float speed = MOVE_SPEED * dt;
    float rota_speed = CAM_SENSITIVITY * dt;
    float x = sfJoystick_getAxisPosition(0, sfJoystickX);
    float y = sfJoystick_getAxisPosition(0, sfJoystickY);
    float rx = sfJoystick_getAxisPosition(0, sfJoystickU);

    if (y < -30)
        move_forward(player, speed, &wolf->map, wolf);
    if (y > 30)
        move_backward(player, speed, &wolf->map, wolf);
    if (x < -30)
        move_left(player, speed, &wolf->map, wolf);
    if (x > 30)
        move_right(player, speed, &wolf->map, wolf);
    if (rx > 30)
        rotate(player, -rota_speed);
    if (rx < -30)
        rotate(player, rota_speed);
    if (sfJoystick_isButtonPressed(0, 0))
        weapon_trigger(weapons);
    if (sfJoystick_isButtonPressed(0, 3))
        open_door(&wolf->map, (int)(player->x + player->dirX * 0.8f),
            (int)(player->y + player->dirY * 0.8f), player);
    if (sfJoystick_isButtonPressed(0, 2))
        switch_torch(player, speed, &wolf->map, wolf);
    if (sfJoystick_isButtonPressed(0, 4))
        consume_mana_bottle(player, speed, &wolf->map, wolf);
    if (sfJoystick_isButtonPressed(0, 5))
        consume_health_bottle(player, speed, &wolf->map, wolf);
    if (sfJoystick_isButtonPressed(0, 1))
        switch_weapon(player, speed, &wolf->map, wolf);
    if (!sfJoystick_isButtonPressed(0, 7))
        player->show_kd = false;
}

void process_input(player_t *player, float dt,
    wolf_t *wolf, weapon_sys_t *weapons)
{
    float speed = MOVE_SPEED * dt;
    float rota_speed = CAM_SENSITIVITY * dt;

    if (!sfRenderWindow_hasFocus(wolf->window) || wolf->is_dead)
        return;
    for (size_t i = 0; i < sizeof(actions) / sizeof(actions[0]); ++i) {
        if (sfKeyboard_isKeyPressed(actions[i].code))
            actions[i].func(player, speed, &wolf->map, wolf);
    }
    if (!sfKeyboard_isKeyPressed(sfKeyTab))
        player->show_kd = false;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        rotate(player, rota_speed);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        rotate(player, -rota_speed);
    if (sfMouse_isButtonPressed(sfMouseLeft) ||
        sfKeyboard_isKeyPressed(sfKeyE))
        weapon_trigger(weapons);
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        open_door(&wolf->map, (int)(player->x + player->dirX * 0.8f),
            (int)(player->y + player->dirY * 0.8f), player);
    }
    if (sfJoystick_isConnected(0) == sfTrue) {
        process_joystick(player, dt, wolf, weapons);
    }
}
