/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** shoot
*/

#include "wolf.h"
#include "weapons.h"
#include <sys/socket.h>
#include "raycasting.h"
#include "object.h"

void send_damage(int attacker, int target, float dmg, int sock)
{
    net_packet_t p = {.type = PKT_DAMAGE};

    p.damage.attacker_id = attacker;
    p.damage.target_id = target;
    p.damage.dmg = dmg;
    send(sock, &p, sizeof(p), MSG_NOSIGNAL);
}

void ecs_apply_damage(ecs_world_t *w, entity_t e, int damage)
{
    int pv;

    if (!ecs_has_component(w, e, COMP_PV))
        return;
    pv = ecs_get_pv(w, e);
    pv -= damage;
    ecs_set_pv(w, e, pv);
}

static bool check_ennemy_hit(ray_context_t *ctx, float2_t enemy_pos)
{
    double inv_det = 1.0 / (ctx->player->planeX * ctx->player->dirY
        - ctx->player->dirX * ctx->player->planeY);
    double sprite_x = enemy_pos.x - ctx->player->x;
    double sprite_y = enemy_pos.y - ctx->player->y;
    double transform_x = inv_det * (ctx->player->dirY * sprite_x
        - ctx->player->dirX * sprite_y);
    double transform_y = inv_det * (-ctx->player->planeY * sprite_x
        + ctx->player->planeX * sprite_y);
    int sprite_screenX = 0;
    int sprite_width = 0;
    int half = 0;

    if (transform_y <= 0)
        return false;
    sprite_screenX =
        (int)((ctx->screenW / 2) * (1 + transform_x / transform_y));
    sprite_width = abs((int)(ctx->screenH / transform_y));
    half = sprite_width / 2;
    return (sprite_screenX + half >= ctx->screenW / 2
            && sprite_screenX - half <= ctx->screenW / 2);
}

void weapon_shoot(weapon_sys_t *weapons, ray_context_t *ctx, wolf_t *wolf)
{
    float2_t pos;
    entity_t entity;

    if (!weapons->attacking
        || sfTime_asSeconds(sfClock_getElapsedTime(weapons->clock)) > 0.1f
        || wolf->player.mana <= 2)
        return;
    wolf->player.mana -= 20;
    for (size_t i = 0; i < wolf->ennemies.nb_ennemies; i++) {
        entity = wolf->ennemies.cast[i].entity;
        ecs_get_position(&wolf->world, entity, &pos.x, &pos.y);
        if (ecs_get_texture_path(&wolf->world, entity) > IS_BOSS)
            continue;
        if (check_ennemy_hit(ctx, pos)
            && calcul_distance(wolf, entity, ctx) <= DISTANCE) {
            ecs_apply_damage(&wolf->world, entity,
                weapons->list[weapons->current].damage);
            break;
        }
    }
}

void weapon_shoot_multi(weapon_sys_t *weapons, ray_context_t *ctx,
    wolf_t *wolf)
{
    float2_t pos;

    if (!weapons->attacking
        || sfTime_asSeconds(sfClock_getElapsedTime(weapons->clock)) > 0.1f
        || wolf->player.mana < 20)
        return;
    wolf->player.mana -= 20;
    for (int i = 0; i < wolf->player_count; i++) {
        if (i == wolf->player_id || !wolf->players[i].is_alive)
            continue;
        pos.x = wolf->players[i].x;
        pos.y = wolf->players[i].y;
        if (check_ennemy_hit(ctx, pos)) {
            send_damage(wolf->player_id,
                wolf->players[i].id, DAMAGE, wolf->sock);
            break;
        }
    }
}
