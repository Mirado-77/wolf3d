/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_menu
*/

#include "wolf.h"
#include "positions.h"
#include "textures.h"

static void draw_main_texts(wolf_t *wolf3d)
{
    int to_true[] = {TXT_PLAY, TXT_SETTINGS, TXT_GAMEMODE, TXT_LEAVE, TXT_TILE,
        TXT_CREDITS, TXT_BTN_LORE, END};
    int to_false[] = {TXT_BACK, END};

    set_text_visibility(wolf3d->tex_manager, to_true, true);
    set_text_visibility(wolf3d->tex_manager, to_false, false);
}

void draw_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    texture_t to_draw[] = {MAIN_BG, FADE3, PLAY_BTN, SETTINGS_BTN,
        GAMEMODE_BTN, LEAVE_BTN, CREDITS_BTN, LORE_BTN, END};
    texture_t needscale[] = {FADE3, PLAY_BTN, SETTINGS_BTN,
        GAMEMODE_BTN, LEAVE_BTN, CREDITS_BTN, LORE_BTN, END};
    sfVector2f positions[] = {{0, 0}, {TITLE_DECO_X, TITLE_DECO_Y},
        {PLAY_X, PLAY_Y}, {SETTING_X, SETTING_Y}, {GAMEMODE_X, GAMEMODE_Y},
        {LEAVE_X, LEAVE_Y}, {CREDITS_X, CREDITS_Y}, {LEAVE_X, LEAVE_Y + 100}};
    sfVector2f scales[] = {{TITLE_SCALE, TITLE_SCALE}, {BTN_SCALE, BTN_SCALE},
        {BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE},
        {KEY_SCALE, BTN_SCALE}, {BTN_SCALE, BTN_SCALE}};

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
