/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** weapons
*/

#include "wolf.h"
#include "weapons.h"
#include "raycasting.h"

void weapon_destroy(const weapon_sys_t *weapon_sys)
{
    for (int i = 0; i < SPELL_MAX; ++i) {
        sfTexture_destroy(weapon_sys->list[i].idle);
        sfTexture_destroy(weapon_sys->list[i].atk[0]);
        sfTexture_destroy(weapon_sys->list[i].atk[1]);
        sfTexture_destroy(weapon_sys->list[i].crosshair.texture);
    }
    sfClock_destroy(weapon_sys->clock);
}

void weapon_trigger(weapon_sys_t *weapon_sys)
{
    if (weapon_sys->attacking)
        return;
    weapon_sys->attacking = true;
    sfClock_restart(weapon_sys->clock);
}

void weapon_update(weapon_sys_t *weapon_sys, ray_context_t *ctx, wolf_t *wolf)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime
    (weapon_sys->clock));

    if (weapon_sys->attacking && time <
        weapon_sys->list[weapon_sys->current].cooldown) {
        if (wolf->game_state == IN_MULTI)
            weapon_shoot_multi(weapon_sys, ctx, wolf);
        else
            weapon_shoot(weapon_sys, ctx, wolf);
    }
    if (weapon_sys->attacking && time >
    weapon_sys->list[weapon_sys->current].cooldown) {
        weapon_sys->attacking = false;
    }
}

void weapon_draw(const weapon_sys_t *weapon_sys, sfRenderWindow *win,
    int screenW, int screenH)
{
    const weapon_t *weapon = &weapon_sys->list[weapon_sys->current];
    const bool atk = weapon_sys->attacking;
    const sfTexture *tex = atk ? weapon->atk[(sfTime_asSeconds(
        sfClock_getElapsedTime(weapon_sys->clock)) > 0.1f)] : weapon->idle;
    sfSprite *sp = sfSprite_create();
    sfVector2f scale = {3, 3};
    sfVector2f pos = {screenW / 2 - HAND_POS_X_OFFSET,
        screenH - HAND_POS_Y_OFFSET};
    xhair_ctx_t ctx = {win, screenW, screenH, weapon_sys->attacking};

    sfSprite_setTexture(sp, (sfTexture *)tex, sfTrue);
    sfSprite_setPosition(sp, pos);
    sfSprite_setScale(sp, scale);
    sfRenderWindow_drawSprite(win, sp, NULL);
    sfSprite_destroy(sp);
    crosshair_draw(&weapon->crosshair, &ctx);
}
