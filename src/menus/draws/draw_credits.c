/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_credits
*/

#include "wolf.h"
#include "positions.h"

static void draw_credits_devider(wolf_t *wolf3d)
{
    sfVector2f positions[] = {
        {POFT(MIDDLE_X, 100), POFT(MIDDLE_Y, 140)},
        {END, END}
    };
    sfVector2f scales[] = {
        {POFT(LORE_FADE_SCALE_X, 3.9), (LORE_DEVIDER_SCALE_Y)},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};
    texture_t to_true[] = {DEVIDER1, END};

    set_to_true(wolf3d->tex_manager, to_true);
    center_origin_entities(wolf3d->tex_manager, to_true);
    draw_texture_multiple(wolf3d, DEVIDER1, &params, 2);
}

static void draw_credits_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_BACK, TXT_MIRA, TXT_SANDES, TXT_PHIL, TXT_C_IN_C,
        TXT_CREDIT_1, TXT_CREDIT_2, TITLE_CREDIT_SPRITE, TXT_CREDIT_3, END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_credits_entities(wolf_t *wolf3d)
{
    texture_t to_draw[] = {BACK_BTN, FADE1, END};
    sfVector2f positions[] = {{BACK_BTN_X, BACK_BTN_Y},
        {TITLE_DECO_X, TITLE_DECO_Y}};
    sfVector2f scales[] = {{BTN_SCALE, BTN_SCALE}, {TITLE_SCALE, TITLE_SCALE}};

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scales);
    draw_entities(wolf3d, to_draw);
}

static void draw_credits_textures(wolf_t *wolf3d)
{
    sfVector2f positions[] = {
        {MIRA_TXT_X, MIRA_TXT_Y},
        {SANDES_TXT_X, SANDES_TXT_Y},
        {PHIL_TXT_X, PHIL_TXT_Y},
        {END, END}
    };
    sfVector2f scales[] = {
        {CREDITS_FADE1_X, CREDITS_FADE1_Y},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};

    draw_texture_multiple(wolf3d, FADE1, &params, 3);
}

void draw_credits_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    UNUSED(ctx);
    if (!wolf3d || !wolf3d->window || !wolf3d->tex_manager)
        return;
    draw_credits_devider(wolf3d);
    draw_credits_entities(wolf3d);
    draw_credits_textures(wolf3d);
    draw_credits_texts(wolf3d);
}
