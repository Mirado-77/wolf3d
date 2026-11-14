/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_pre_multi
*/

#include "wolf.h"
#include "positions.h"

static void draw_pre_multi_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_BACK, TXT_PRE_MULTI, TXT_JOIN, TXT_HOST, END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_pre_multi_entities(wolf_t *wolf3d)
{
    texture_t to_draw[] = {BACK_BTN, HOST_BTN, JOIN_BTN, END};
    sfVector2f positions[] = {{BACK_BTN_X, BACK_BTN_Y},
    {HOST_BTN_X, HOST_BTN_Y}, {JOIN_BTN_X, JOIN_BTN_Y}};
    sfVector2f scales[] = {{BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE},
        {BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE},
        {BTN_SCALE, BTN_SCALE}};

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scales);
    draw_entities(wolf3d, to_draw);
}
// static void draw_pre_multi_input_tex(wolf_t *wolf3d)
// {
//     sfVector2f positions[] = {
//         {JOIN_BTN_X, JOIN_BTN_Y + 120},
//         {JOIN_BTN_X, JOIN_BTN_Y + 230},
//         {END, END}
//     };
//     sfVector2f scales[] = {
//         {BTN_SCALE, BTN_SCALE},
//         {BTN_SCALE, BTN_SCALE},
//         {END, END}
//     };
//     texture_draw_params_t params = {positions, scales};

//     draw_texture_multiple(wolf3d, INPUT, &params, 2);
// }
static void draw_pre_multi_textures(wolf_t *wolf3d)
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

    draw_texture_multiple(wolf3d, FADE1, &params, 1);
}

void draw_pre_multi_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    UNUSED(ctx);
    if (!wolf3d || !wolf3d->window || !wolf3d->tex_manager)
        return;
    draw_pre_multi_textures(wolf3d);
    draw_pre_multi_entities(wolf3d);
    draw_pre_multi_texts(wolf3d);
    draw_sprite_inputs(wolf3d->window, wolf3d->input_fields, NB_INPUT);
}
