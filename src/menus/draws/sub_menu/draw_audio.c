/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_graphics
*/

/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_smenu
*/

#include "wolf.h"
#include "positions.h"

static float calculate_volume_percent(const wolf_t *wolf3d)
{
    return (wolf3d->vol_slider.current_value - wolf3d->vol_slider.min_value) /
        (wolf3d->vol_slider.max_value - wolf3d->vol_slider.min_value);
}

static void update_handle_position(sfVector2f *positions, float volume_percent,
    wolf_t *wolf3d)
{
    texture_asset_t *slider = &wolf3d->tex_manager->assets[VOLUME_SLIDER];
    sfFloatRect slider_bounds = sfSprite_getGlobalBounds(slider->sprite);

    positions[1].x = positions[0].x + (slider_bounds.width * volume_percent);
    positions[1].y = positions[0].y + slider_bounds.height / 2;
}

static bool check_window_validity(const wolf_t *wolf3d)
{
    return (wolf3d && wolf3d->window && wolf3d->tex_manager &&
        sfRenderWindow_isOpen(wolf3d->window));
}

static void draw_audio_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_VOLUME, END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_smenu_entities(wolf_t *wolf3d)
{
    sfVector2f positions[] = {{VOL_SLIDER_X, VOL_SLIDER_Y},
        {VOL_SLIDER_HANDLE_X, VOL_SLIDER_HANDLE_Y}};
    sfVector2f scales[] = {{BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE}};
    texture_t to_draw[] = {VOLUME_SLIDER, SLIDER_HANDLE, END};
    texture_t needscale[] = {VOLUME_SLIDER, SLIDER_HANDLE, END};
    texture_t center_origin[] = {SLIDER_HANDLE, END};
    float volume_percent;

    volume_percent = calculate_volume_percent(wolf3d);
    update_handle_position(positions, volume_percent, wolf3d);
    center_origin_entities(wolf3d->tex_manager, center_origin);
    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, needscale, scales);
    draw_entities(wolf3d, to_draw);
}

void draw_audio_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    draw_smenu(wolf3d, ctx);
    if (!check_window_validity(wolf3d))
        return;
    draw_audio_texts(wolf3d);
    draw_smenu_entities(wolf3d);
}
