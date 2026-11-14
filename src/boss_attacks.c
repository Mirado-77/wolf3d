/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** boss_attacks
*/

#include "boss.h"
#include <math.h>

static void boss_dash(wolf_t *wolf, float dir_x, float dir_y)
{
    entity_t boss = ecs_first(&wolf->world, COMP_BOSS);
    float bx = 0.f;
    float by = 0.f;
    float nx;
    float ny;

    if (!ecs_is_valid_entity(&wolf->world, boss))
        return;
    ecs_get_position(&wolf->world, boss, &bx, &by);
    nx = bx + dir_x * BOSS_DASH_DIST;
    ny = by + dir_y * BOSS_DASH_DIST;
    if (nx >= 0 && nx < wolf->map.width && ny >= 0 && ny < wolf->map.height &&
        wolf->map.tiles[(int)nx][(int)ny] == 0) {
        ecs_set_position(&wolf->world, boss, nx, ny);
        }
}

static bool boss_get_pos(wolf_t *wolf, float *bx, float *by, entity_t *id)
{
    entity_t e = ecs_first(&wolf->world, COMP_BOSS);

    if (!ecs_is_valid_entity(&wolf->world, e))
        return false;
    ecs_get_position(&wolf->world, e, bx, by);
    if (id)
        *id = e;
    return true;
}

static void vector_to_player(wolf_t *wolf, sfVector2f *boss_pos,
    sfVector2f *dir, float *dist2)
{
    dir->x = wolf->player.x - boss_pos->x;
    dir->y = wolf->player.y - boss_pos->y;
    *dist2 = (dir->x) * (dir->x) + (dir->y) * (dir->y);
}

void perform_melee(wolf_t *wolf)
{
    entity_t boss;
    sfVector2f boss_pos;
    sfVector2f dir;
    float dist2;
    float len;

    if (!boss_get_pos(wolf, &boss_pos.x, &boss_pos.y, &boss))
        return;
    vector_to_player(wolf, &boss_pos, &dir, &dist2);
    len = sqrtf(dist2);
    if (len > 0.0001f)
        boss_dash(wolf, dir.x / len, dir.y / len);
    ecs_get_position(&wolf->world, boss, &boss_pos.x, &boss_pos.y);
    vector_to_player(wolf, &boss_pos, &dir, &dist2);
    if (dist2 <= MELEE_RANGE * MELEE_RANGE)
        wolf->player.health -= MELEE_DAMAGE;
}
