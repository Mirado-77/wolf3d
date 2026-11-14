/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_gamemode
*/

#include "wolf.h"
#include "positions.h"

static void draw_gamemode_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_BACK, TXT_MU, TXT_ZO, TXT_CGAME, END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_cards(wolf_t *wolf3d)
{
    sfVector2f positions[] = {{CARD_2_X, CARD_2_Y}, {CARD_3_X, CARD_3_Y},
        {END, END}};
    sfVector2f scales[] = {
        {HUD_SCALEX, HUD_SCALEY},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};

    draw_texture_multiple(wolf3d, CARD_GAME, &params, 2);
}

static void draw_gamemode_textures(wolf_t *wolf3d)
{
    sfVector2f positions[] = {
        {FADE1_GAMEMODE_X, FADE1_GAMEMODE_Y},
        {END, END}
    };
    sfVector2f scales[] = {
        {BTN_SCALE, TITLE_SCALE},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};

    draw_cards(wolf3d);
    draw_texture_multiple(wolf3d, FADE1, &params, 1);
}

static void draw_gamemode_entities(wolf_t *wolf3d)
{
    texture_t to_draw[] = {BACK_BTN, MULTI_BTN, ZOMBIE_BTN, END};
    sfVector2f positions[] = {{BACK_BTN_X, BACK_BTN_Y},
        {MULT_BTN_X, MULT_BTN_Y}, {ZO_BTN_X, ZO_BTN_Y}};
    sfVector2f scales[] = { {BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE},
        {BTN_SCALE, BTN_SCALE}};

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scales);
    draw_entities(wolf3d, to_draw);
}

void draw_gamemode_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    UNUSED(ctx);
    if (!wolf3d || !wolf3d->window || !wolf3d->tex_manager)
        return;
    draw_gamemode_textures(wolf3d);
    draw_gamemode_entities(wolf3d);
    draw_gamemode_texts(wolf3d);
}
