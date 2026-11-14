/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** handle_click
*/

#include "wolf.h"

bool is_btn_clicked(wolf_t *wolf3d, sfVector2i mouse_pos,
    texture_t btn_type)
{
    sfFloatRect btn_bounds;
    texture_asset_t *btn = NULL;

    if (!wolf3d->tex_manager)
        return false;
    btn = &wolf3d->tex_manager->assets[btn_type];
    if (!btn->sprite)
        return false;
    if (btn->is_loaded == false)
        return false;
    btn_bounds = sfSprite_getGlobalBounds(btn->sprite);
    return sfFloatRect_contains(&btn_bounds, mouse_pos.x, mouse_pos.y);
}

bool is_btn_hovered(wolf_t *wolf3d, sfVector2i mouse_pos,
    texture_t btn_type)
{
    sfFloatRect btn_bounds;
    texture_asset_t *btn = NULL;
    float mx;
    float my;

    if (!wolf3d->tex_manager)
        return false;
    btn = &wolf3d->tex_manager->assets[btn_type];
    if (!btn->sprite || btn->is_loaded == false)
        return false;
    btn_bounds = sfSprite_getGlobalBounds(btn->sprite);
    mx = (float)mouse_pos.x;
    my = (float)mouse_pos.y;
    return sfFloatRect_contains(&btn_bounds, mx, my);
}

static bool check_event_validity(wolf_t *wolf3d, sfEvent event)
{
    if (!wolf3d || !wolf3d->window || !wolf3d->tex_manager ||
        !sfRenderWindow_isOpen(wolf3d->window))
        return false;
    if (event.type != sfEvtMouseButtonPressed)
        return false;
    return true;
}

void handle_click(wolf_t *wolf3d, sfEvent event)
{
    sfVector2i mouse_pos;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyD
        && event.key.control) {
        sfRenderWindow_close(wolf3d->window);
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        wolf3d->game_state = IN_PAUSE;
        return;
    }
    if (!check_event_validity(wolf3d, event))
        return;
    mouse_pos = sfMouse_getPositionRenderWindow(wolf3d->window);
    BTN_STATE_HANDLERS[wolf3d->game_state](wolf3d, mouse_pos);
}
