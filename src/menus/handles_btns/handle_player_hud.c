/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** handle_player_hud
*/

#include "wolf.h"
#include "textures.h"

static sfIntRect calc_rect(float current, float max, const sfIntRect base)
{
    sfIntRect new_rect = base;
    float ratio = (current / max);

    if (ratio < 0)
        ratio = 0;
    if (ratio > 1)
        ratio = 1;
    new_rect.width = (int)(base.width * ratio);
    if (new_rect.width > base.width)
        new_rect.width = base.width;
    new_rect.top = base.top;
    new_rect.height = base.height;
    new_rect.left = base.left;
    return new_rect;
}

static sfIntRect get_bar_rect(wolf_t *wolf, texture_t entity,
    const sfIntRect base)
{
    if (entity == BLOOD_LINE)
        return calc_rect(wolf->player.health, MAX_HEALTH, base);
    if (entity == STAMINA_LINE)
        return calc_rect(wolf->player.stamina, MAX_STAMINA, base);
    if (entity == MANA_LINE)
        return calc_rect(wolf->player.mana, MAX_MANA, base);
    return base;
}

static void update_hud_textures(wolf_t *wolf, texture_t *hud,
    const sfIntRect *base)
{
    int i = 0;
    sfIntRect new_rect = (sfIntRect){0, 0, 0, 0};

    while (hud[i] != END) {
        if (is_valid_entity(wolf->tex_manager, hud[i])) {
            new_rect = get_bar_rect(wolf, hud[i], base[hud[i]]);
            wolf->tex_manager->assets[hud[i]].rect = new_rect;
        }
        i += 1;
    }
}

void handle_player_hud(wolf_t *wolf, texture_t *hud, const sfIntRect *base)
{
    float elapsed =
        sfTime_asSeconds(sfClock_getElapsedTime(wolf->player.clock));

    if (elapsed >= 0.1) {
        update_hud_textures(wolf, hud, base);
        sfClock_restart(wolf->player.clock);
    }
}
