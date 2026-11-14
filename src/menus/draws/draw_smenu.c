/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_smenu
*/

#include "wolf.h"
#include "positions.h"

static bool check_window_validity(const wolf_t *wolf3d)
{
    return (wolf3d && wolf3d->window && wolf3d->tex_manager &&
        sfRenderWindow_isOpen(wolf3d->window));
}

static void draw_settings_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_BACK, TXT_S_IN_S, TXT_AUDIO, TXT_GRAPHICS, TXT_CONTROLS,
        END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_smenu_entities(wolf_t *wolf3d)
{
    sfVector2f positions[] = {{BACK_BTN_X, BACK_BTN_Y},
    {AUDIO_BTN_X, AUDIO_BTN_Y}, {GRAPHICS_BTN_X, GRAPHICS_BTN_Y},
        {CONTROLS_BTN_X, CONTROLS_BTN_Y}};
    sfVector2f scales[] = {{BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE},
    {BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE}};
    texture_t to_draw[] = {BACK_BTN, AUDIO_BTN, GRAPHICS_BTN, CONTROLS_BTN,
        END };
    texture_t needscale[] = {BACK_BTN, AUDIO_BTN, GRAPHICS_BTN, CONTROLS_BTN,
        END };

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, needscale, scales);
    draw_entities(wolf3d, to_draw);
}

static void draw_smenu_textures(wolf_t *wolf3d)
{
    sfVector2f positions[] = {
        {TITLE_SCREN_X, TITLE_SCREN_Y},
        {SETTING_FADE_X, SETTING_FADE_Y},
        {END, END}
    };
    sfVector2f scales[] = {
        {SETTINGS_FADE_SCALEX, TITLE_SCALE},
        {SETTINGS_FADE_SCALEX, SETTINGS_FADE_SCALEY},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};

    draw_texture_multiple(wolf3d, FADE1, &params, 2);
}

void draw_smenu(wolf_t *wolf3d, ray_context_t *ctx)
{
    UNUSED(ctx);
    if (!check_window_validity(wolf3d))
        return;
    draw_settings_texts(wolf3d);
    draw_smenu_textures(wolf3d);
    draw_smenu_entities(wolf3d);
}
