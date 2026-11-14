/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** movements
*/

#include "input_handler.h"
#include "object.h"


static bool collide_with_ennemies(float x, float y, wolf_t *w)
{
    float2_t pos = {0, 0};
    float dx;
    float dy;
    int text = 0;

    for (size_t i = 0; i < w->ennemies.nb_ennemies; ++i) {
        text = ecs_get_texture_path(&w->world, w->ennemies.cast[i].entity);
        if ((text != IS_ENEMIE && text != IS_MASTER && text != IS_GENIE) ||
            ecs_get_pv(&w->world, w->ennemies.cast[i].entity) == DEAD_KEY)
                continue;
        ecs_get_position(&w->world, w->ennemies.cast[i].entity,
            &pos.x, &pos.y);
        dx = x - pos.x;
        dy = y - pos.y;
        if (dx * dx + dy * dy < MIN_ENNEMY_DIST * MIN_ENNEMY_DIST)
            return true;
    }
    return false;
}

void switch_weapon(player_t *player, float speed, map_t *map, wolf_t *wolf)
{
    (void)player;
    (void)speed;
    (void)map;
    if (wolf->weapons.current == 0)
        wolf->weapons.current = 1;
    else
        wolf->weapons.current = 0;
}

static bool can_move_to(float x, float y, const map_t *map, wolf_t *wolf)
{
    return x >= 0 && x < map->width &&
        y >= 0 && y < map->height &&
        map->tiles[(int)x][(int)y] == 0 &&
        !collide_with_ennemies(x, y, wolf);
}

static void compute_target(const player_t *p, float speed,
    bool sprint, sfVector2f *t_pos)
{
    float factor = sprint ? SPRINT_FACTOR : 1.0f;

    t_pos->x = p->x + p->dirX * speed * factor;
    t_pos->y = p->y + p->dirY * speed * factor;
}

static void update_stamina(wolf_t *wolf, bool sprint)
{
    if (!sprint)
        return;
    wolf->player.stamina -= STAMINA_CONSUMPTION;
    if (wolf->player.stamina < 0.0f)
        wolf->player.stamina = 0.0f;
}

static bool can_sprint(const wolf_t *wolf)
{
    float left_trigger;

    if (sfKeyboard_isKeyPressed(sfKeyLShift) && wolf->player.stamina > 2.0f)
        return true;
    if (sfJoystick_isConnected(0)) {
        left_trigger = sfJoystick_getAxisPosition(0, sfJoystickZ);
        if (left_trigger > 20 && wolf->player.stamina > 2.0f) {
            return true;
        }
    }
    return false;
}

void move_forward(player_t *player, float speed, map_t *map, wolf_t *wolf)
{
    bool sprint = can_sprint(wolf);
    sfVector2f t_pos = {0};

    compute_target(player, speed, sprint, &t_pos);
    update_stamina(wolf, sprint);
    if (can_move_to(t_pos.x, player->y, map, wolf))
        player->x = t_pos.x;
    if (can_move_to(player->x, t_pos.y, map, wolf))
        player->y = t_pos.y;
    sfSound_setVolume(wolf->sound_sys.sounds[SOUND_FOOTSTEP], 100.f);
    play_sound(&wolf->sound_sys, SOUND_FOOTSTEP);
}

void move_backward(player_t *player, float speed, map_t *map, wolf_t *wolf)
{
    float new_x = player->x - player->dirX * speed;
    float new_y = player->y - player->dirY * speed;

    if (new_x >= 0 && new_x < map->width &&
        player->y >= 0 && player->y < map->height &&
        !collide_with_ennemies(new_x, player->y, wolf) &&
        map->tiles[(int)new_x][(int)player->y] == 0)
        player->x = new_x;
    if (player->x >= 0 && player->x < map->width &&
        new_y >= 0 && new_y < map->height &&
        !collide_with_ennemies(player->x, new_y, wolf) &&
        map->tiles[(int)player->x][(int)new_y] == 0)
        player->y = new_y;
}

void move_right(player_t *player, float speed, map_t *map, wolf_t *wolf)
{
    float new_x = player->x + player->dirY * speed;
    float new_y = player->y - player->dirX * speed;

    if (new_x >= 0 && new_x < map->width &&
        player->y >= 0 && player->y < map->height &&
        !collide_with_ennemies(new_x, player->y, wolf) &&
        map->tiles[(int)new_x][(int)player->y] == 0)
        player->x = new_x;
    if (player->x >= 0 && player->x < map->width &&
        new_y >= 0 && new_y < map->height &&
        !collide_with_ennemies(player->x, new_y, wolf) &&
        map->tiles[(int)player->x][(int)new_y] == 0)
        player->y = new_y;
}

void move_left(player_t *player, float speed, map_t *map, wolf_t *wolf)
{
    float new_x = player->x - player->dirY * speed;
    float new_y = player->y + player->dirX * speed;

    if (new_x >= 0 && new_x < map->width &&
        player->y >= 0 && player->y < map->height &&
        !collide_with_ennemies(new_x, player->y, wolf) &&
        map->tiles[(int)new_x][(int)player->y] == 0)
        player->x = new_x;
    if (player->x >= 0 && player->x < map->width &&
        new_y >= 0 && new_y < map->height &&
        !collide_with_ennemies(player->x, new_y, wolf) &&
        map->tiles[(int)player->x][(int)new_y] == 0)
        player->y = new_y;
}
