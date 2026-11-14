/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_menu
*/

#include "wolf.h"
#include "positions.h"
#include "textures.h"

static void draw_lore_textures(wolf_t *wolf3d)
{
    sfVector2f positions[] = {
        {LORE_FADE_X, LORE_FADE_Y},
        {LORE_FADE_X, LORE_FADE_Y_500},
        {END, END}
    };
    sfVector2f scales[] = {
        {LORE_FADE_SCALE_X, LORE_DEVIDER_SCALE_Y},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};
    texture_t to_true[] = {DEVIDER1, END};

    set_to_true(wolf3d->tex_manager, to_true);
    draw_texture_multiple(wolf3d, DEVIDER1, &params, 2);
}

static void draw_main_texts(wolf_t *wolf3d)
{
    int to_true[] = {TXT_LORE, TXT_BACK, END};

    set_text_visibility(wolf3d->tex_manager, to_true, true);
    draw_lore_textures(wolf3d);
}

void draw_lore_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    texture_t to_draw[] = {BACK_BTN, END};
    texture_t needscale[] = {BACK_BTN, END};
    sfVector2f positions[] = {{BACK_BTN_X, BACK_BTN_Y}};
    sfVector2f scales[] = {{BTN_SCALE, BTN_SCALE}};

    UNUSED(ctx);
    if (!wolf3d || !wolf3d->window || !wolf3d->tex_manager)
        return;
    if (wolf3d->game_state == IN_MAIN_MENU)
        set_to_true(wolf3d->tex_manager, to_draw);
    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, needscale, scales);
    draw_entities(wolf3d, to_draw);
    draw_main_texts(wolf3d);
}
