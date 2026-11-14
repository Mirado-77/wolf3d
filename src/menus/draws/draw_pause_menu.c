/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_gamemode
*/

#include "wolf.h"
#include "positions.h"

static void draw_pause_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_CLOSE, TXT_SAVE, TXT_PAUSE, TXT_SETTINGS, END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_pause_entities(wolf_t *wolf3d)
{
    texture_t to_draw[] = {CLOSE_BTN, SAVE_BTN, FADE3, SETTINGS_BTN, END};
    sfVector2f positions[] = {{BACK_BTN_X, BACK_BTN_Y},
        {PLAY_X, PLAY_Y}, {PAUSE_TITLE_DECO_X, PAUSE_TITLE_DECO_Y},
        {SETTING_X, SETTING_Y}};
    sfVector2f scales[] = { {BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE},
        {TITLE_SCALE, TITLE_SCALE}, {BTN_SCALE, BTN_SCALE}};

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scales);
    draw_entities(wolf3d, to_draw);
}

static void set_to_true_pause(wolf_t *wolf3d)
{
    texture_t to_true[] = {FADE3, END};

    set_to_true(wolf3d->tex_manager, to_true);
}

void draw_pause_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    UNUSED(ctx);
    if (!wolf3d || !wolf3d->window || !wolf3d->tex_manager)
        return;
    set_to_true_pause(wolf3d);
    draw_pause_entities(wolf3d);
    draw_pause_texts(wolf3d);
}
