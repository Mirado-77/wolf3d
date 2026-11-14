/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_weapon
*/

#include <stdio.h>
#include "weapons.h"

static void load_tex(sfTexture **texture, const char *path, bool *ok)
{
    *texture = sfTexture_createFromFile(path, NULL);
    *ok = *ok && (*texture != NULL);
}

static bool init_crosshairs(weapon_t *w)
{
    bool ok = true;
    const char *img[SPELL_MAX] = {
        "assets/xhair/default.png",
        "assets/xhair/default.png"
    };
    const float idle[SPELL_MAX] = {1.5f, 1.5f};
    const float atk[SPELL_MAX] = {2.0f, 2.0f};

    for (int i = 0; i < SPELL_MAX; ++i)
        ok = crosshair_init(&w[i].crosshair, img[i], idle[i], atk[i]) && ok;
    return ok;
}

bool weapon_init(weapon_sys_t *weapon_sys)
{
    bool ok = true;
    const char *idle[SPELL_MAX] = {IDLE_HAND, IDLE_HAND};
    const char *atk0[SPELL_MAX] = {SPELL_1_1, SPELL_2_1};
    const char *atk1[SPELL_MAX] = {SPELL_1_2, SPELL_2_2};
    const char *atk2[SPELL_MAX] = {SPELL_1_3, SPELL_2_3};

    weapon_sys->current = SPELL_1;
    weapon_sys->clock = sfClock_create();
    weapon_sys->attacking = false;
    for (int i = 0; i < SPELL_MAX; ++i) {
        load_tex(&weapon_sys->list[i].idle, idle[i], &ok);
        load_tex(&weapon_sys->list[i].atk[0], atk0[i], &ok);
        load_tex(&weapon_sys->list[i].atk[1], atk1[i], &ok);
        load_tex(&weapon_sys->list[i].atk[2], atk2[i], &ok);
        weapon_sys->list[i].cooldown = COOLDOWN;
        weapon_sys->list[i].damage = DAMAGE;
    }
    ok = ok && init_crosshairs(weapon_sys->list);
    return ok;
}
