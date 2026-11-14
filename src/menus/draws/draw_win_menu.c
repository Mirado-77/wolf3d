/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_win
*/

#include "wolf.h"
#include "positions.h"

static void draw_win_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_BACK, TXT_GAME_WIN, END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_win_textures(wolf_t *wolf3d)
{
    sfVector2f positions[] = {
        {GAME_OVER_FADE1_X, GAME_OVER_FADE1_Y},
        {END, END}
    };
    sfVector2f scales[] = {
        {TITLE_SCALE, TITLE_SCALE},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};

    draw_texture_multiple(wolf3d, FADE1, &params, 2);
}

static void draw_win_entities(wolf_t *wolf3d)
{
    texture_t to_draw[] = {WIN_BG, BACK_BTN, END};
    sfVector2f positions[] = {{0, 0}, {BACK_BTN_X, BACK_BTN_Y}};
    sfVector2f scales[] = {{2.609f, 2.609f}, {BTN_SCALE, BTN_SCALE}};

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scales);
    draw_entities(wolf3d, to_draw);
}

void draw_win_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    UNUSED(ctx);
    if (!wolf3d || !wolf3d->window || !wolf3d->tex_manager)
        return;
    draw_win_entities(wolf3d);
    draw_win_textures(wolf3d);
    draw_win_texts(wolf3d);
}
