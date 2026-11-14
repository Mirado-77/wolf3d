/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_graphics
*/

#include "wolf.h"
#include "positions.h"

static void draw_controls_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_KEY_A, TXT_KEY_Z, TXT_KEY_E, TXT_KEY_S,
        TXT_KEY_Q, TXT_KEY_D, TXT_KEY_ARROW_L, TXT_KEY_ARROW_R, TXT_KEY_SHIFT,
        TXT_KEY_F, TXT_KEY_R, TXT_KEY_MANA, TXT_KEY_HEALTH, END
    };

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_col_one(wolf_t *wolf3d)
{
    sfVector2f positions[] = { {KEY_A_X, KEY_A_Y}, {KEY_Z_X, KEY_Z_Y},
        {KEY_E_X, KEY_E_Y}, {KEY_S_X, KEY_S_Y}, {KEY_Q_X, KEY_Q_Y},
        {KEY_D_X, KEY_D_Y}, {KEY_ARROW_L_X, KEY_ARROW_L_Y},
        {KEY_ARROW_R_X, KEY_ARROW_R_Y}, {KEY_SHIFT_X, KEY_SHIFT_Y}
    };
    sfVector2f scales[] = {
        {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE},
        {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE},
        {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE},
    };
    texture_t to_draw[] = {KEY_A, KEY_Z, KEY_E, KEY_S, KEY_Q, KEY_D,
        KEY_ARROW_L, KEY_ARROW_R, KEY_SHIFT, END};
    texture_t needscale[] = {KEY_A, KEY_D, KEY_E, KEY_Q, KEY_S, KEY_Z,
        KEY_ARROW_L, KEY_ARROW_R, KEY_SHIFT, END};

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, needscale, scales);
    draw_entities(wolf3d, to_draw);
}

static void draw_col_two(wolf_t *wolf3d)
{
    sfVector2f positions[] = {{KEY_F_X, KEY_F_Y}, {KEY_R_X, KEY_R_Y},
        {KEY_HB_X, KEY_HB_Y}, {KEY_MB_X, KEY_MB_Y}
    };
    sfVector2f scales[] = {
        {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE}, {KEY_SCALE, KEY_SCALE},
        {KEY_SCALE, KEY_SCALE}
    };
    texture_t to_draw[] = {KEY_F, KEY_R, KEY_H, KEY_M, END};
    texture_t needscale[] = {KEY_F, KEY_R, KEY_H, KEY_M, END};

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, needscale, scales);
    draw_entities(wolf3d, to_draw);
}

static void draw_controls_entities(wolf_t *wolf3d)
{
    draw_col_one(wolf3d);
    draw_col_two(wolf3d);
}

void draw_controls_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    draw_smenu(wolf3d, ctx);
    draw_controls_texts(wolf3d);
    draw_controls_entities(wolf3d);
}
