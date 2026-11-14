/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** handle_settings
*/

#include "wolf.h"

static void handle_slider_click(wolf_t *wolf3d, sfVector2i mouse_pos)
{
    texture_asset_t *slider = &wolf3d->tex_manager->assets[VOLUME_SLIDER];
    sfFloatRect slider_bounds = sfSprite_getGlobalBounds(slider->sprite);
    float relative_x;
    float new_volume;

    if (!sfFloatRect_contains(&slider_bounds, mouse_pos.x, mouse_pos.y))
        return;
    relative_x = (mouse_pos.x - slider_bounds.left) / slider_bounds.width;
    if (relative_x < 0)
        relative_x = 0;
    else if (relative_x > 1)
        relative_x = 1;
    new_volume = wolf3d->vol_slider.min_value +
        (wolf3d->vol_slider.max_value - wolf3d->vol_slider.min_value) *
        relative_x;
    wolf3d->vol_slider.current_value = new_volume;
    sfMusic_setVolume(wolf3d->music, new_volume);
}

void handle_settings(wolf_t *wolf3d, sfVector2i mouse_pos)
{
    const button_handler_t *handler = BUTTON_HANDLERS;

    handle_slider_click(wolf3d, mouse_pos);
    while (handler->btn_type != END) {
        if (is_btn_clicked(wolf3d, mouse_pos, handler->btn_type))
            handler->action(wolf3d);
        handler++;
    }
    return;
}
