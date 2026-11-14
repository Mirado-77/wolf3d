/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** handle_boss_bar
*/

#include "wolf.h"
#include "ecs.h"

sfIntRect calc_rect(float current, float max, const sfIntRect base)
{
    sfIntRect new_rect = base;
    float ratio = current / max;

    if (ratio < 0)
        ratio = 0;
    if (ratio > 1)
        ratio = 1;
    new_rect.width = (int)(base.width * ratio);
    if (new_rect.width > base.width)
        new_rect.width = base.width;
    new_rect.left = base.left + (base.width - new_rect.width) / 2;
    new_rect.top = base.top;
    new_rect.height = base.height;
    return new_rect;
}

sfIntRect get_boss_bar_rect(wolf_t *wolf, texture_t entity,
    const sfIntRect base)
{
    entity_t e = ecs_first(&wolf->world, COMP_BOSS);
    boss_t *boss_ecs = ecs_get_boss(&wolf->world, e);

    if (boss_ecs == NULL)
        return base;
    if (entity == BOSS_FILLER && boss_ecs->max_hp > 0)
        return calc_rect(boss_ecs->hp, boss_ecs->max_hp, base);
    return base;
}

void update_boss_textures(wolf_t *wolf, texture_t *boss, const sfIntRect *base)
{
    int i = 0;
    sfIntRect new_rect;

    while (boss[i] != END) {
        if (is_valid_entity(wolf->tex_manager, boss[i])) {
            new_rect = get_boss_bar_rect(wolf, boss[i], base[boss[i]]);
            wolf->tex_manager->assets[boss[i]].rect = new_rect;
        }
        i = i + 1;
    }
}

void handle_boss_bar(wolf_t *wolf, texture_t *boss, const sfIntRect *base)
{
    update_boss_textures(wolf, boss, base);
}
