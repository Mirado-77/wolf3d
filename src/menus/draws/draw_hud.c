/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_hud
*/

#include "wolf.h"
#include "textures.h"
#include "positions.h"
#include "object.h"

static void draw_hearts(wolf_t *wolf3d)
{
    sfVector2f positions[] = {
        {HEART1_X, HEART1_Y},
        {HEART2_X, HEART2_Y},
        {HEART3_X, HEART3_Y},
        {END, END}
    };
    sfVector2f scales[] = {
        {HEART_SCALE, HEART_SCALE},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};
    texture_t to_draw[] = {HEART, END};

    center_origin_entities(wolf3d->tex_manager, to_draw);
    draw_texture_multiple(wolf3d, HEART, &params, 3);
}

static void draw_boss_bar(wolf_t *wolf3d)
{
    texture_t to_draw[] = {BOSS_BAR, BOSS_FILLER, END};
    sfVector2f positions[] = {{BOSS_BAR_X, BOSS_BAR_Y},
        {BOSS_BAR_FILLER_X, BOSS_BAR_FILLER_Y}};
    sfVector2f scale[] = {{BOSS_SCALEX, BOSS_SCALEX},
    {BOSS_SCALEX, BOSS_SCALEX}};

    center_origin_entities(wolf3d->tex_manager, to_draw);
    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scale);
    draw_entities(wolf3d, to_draw);
}

static void draw_items(wolf_t *wolf3d)
{
    texture_t to_draw[] = {HUD_MINIMAP, HUD_ITEMS, END};
    sfVector2f positions[] = {{HUD_MAP_X, HUD_MAP_Y},
        {HUD_ITEMS_X, HUD_ITEMS_Y}};
    sfVector2f scales[] = {
        {MINIMAP_COVER, MINIMAP_COVER}, {HUD_ITEMS_SX, HUD_ITEMS_SY},
    };

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scales);
    draw_entities(wolf3d, to_draw);
}

static void draw_player_stats(wolf_t *wolf3d)
{
    texture_t to_draw[] = {BLOOD_LINE, MANA_LINE, STAMINA_LINE, PLAYER_HUD,
        SKELETON_HEAD, END};
    sfVector2f positions[] = {{BLOOD_LINE_X, BLOOD_LINE_Y},
        {MANA_LINE_X, MANA_LINE_Y}, {STAMINA_LINE_X, STAMINA_LINE_Y},
        {PLAYER_HUD_X, PLAYER_HUD_Y}, {SKELETON_HEAD_X, SKELETON_HEAD_Y}};
    sfVector2f scales[] = {{HUD_SCALEX, HUD_SCALEX}, {HUD_SCALEX, HUD_SCALEX},
        {HUD_SCALEX, HUD_SCALEX}, {HUD_SCALEX, HUD_SCALEX},
        {HEAD_SCALE, HEAD_SCALE},
    };

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scales);
    draw_entities(wolf3d, to_draw);
}

void animate_boss_key(texture_asset_t *asset)
{
    static sfClock *clock = NULL;
    static int frame = 0;
    float seconds;
    sfIntRect rect;

    if (!asset || !asset->sprite || asset->is_loaded == false)
        return;
    if (!clock)
        clock = sfClock_create();
    seconds = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    if (seconds < 0.1f)
        return;
    sfClock_restart(clock);
    frame = (frame + 1) % 27;
    rect.top = 0;
    rect.left = frame * 21;
    rect.width = 21;
    rect.height = 47;
    asset->rect = rect;
}

static float calculate_ratio_kd(player_t *player)
{
    float error = -1.f;

    if (player != NULL) {
        UNUSED(error);
        return player->deaths > 0 ? (float)player->kills / player->deaths :
            (float)player->kills;
    }
    return error;
}

static void draw_selected(wolf_t *wolf)
{
    sfVector2f positions[] = {
        {NOFT(WIN_WIDTH, 120), 100},
        {END, END}
    };
    sfVector2f scales[] = {
        {POFT(KEY_SCALE, 1.7), POFT(KEY_SCALE, 1.2)},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};
    texture_t to_draw[] = {SELECTED2, END};

    center_origin_entities(wolf->tex_manager, to_draw);
    draw_texture_multiple(wolf, SELECTED2, &params, 3);
}

static void draw_kd_overlay(wolf_t *wolf)
{
    texture_t to_draw[] = {HUD_KD, END};
    sfVector2f positions[] = {{NOFT(WIN_WIDTH, 120), 100}};
    sfVector2f scales[] = {{KEY_SCALE, KEY_SCALE}};

    draw_selected(wolf);
    center_origin_entities(wolf->tex_manager, to_draw);
    set_position_entities(wolf->tex_manager, to_draw, positions);
    set_scale_entities(wolf->tex_manager, to_draw, scales);
    draw_entities(wolf, to_draw);
}

static void draw_kd_hud(player_t *player, wolf_t *wolf)
{
    float kd_r = calculate_ratio_kd(player);
    sfColor customColor = sfColor_fromRGBA(168, 141, 117, 255);
    char kd_txt[64];

    if (!wolf->ctx->player->show_kd || kd_r == (float)-1.f)
        return;
    snprintf(kd_txt, sizeof(kd_txt), "Kills: %d\nDeaths: %d\nK/D: %.2f",
        player->kills, player->deaths, kd_r);
    sfText *text = sfText_create();
    sfText_setString(text, kd_txt);
    sfText_setFont(text, wolf->tex_manager->font);
    sfText_setPosition(text, (sfVector2f){NOFT(WIN_WIDTH, 190), 50});
    sfText_setColor(text, customColor);
    sfText_setCharacterSize(text, 34);
    draw_kd_overlay(wolf);
    sfRenderWindow_drawText(wolf->window, text, NULL);
    sfText_destroy(text);
}

static void draw_objectives_txt(wolf_t *wolf3d)
{
    int to_true[] = {TXT_OBJ1, TXT_OBJ2, TXT_OBJ3, END};

    set_text_visibility(wolf3d->tex_manager, to_true, true);
}

static void draw_objective_selected(wolf_t *wolf)
{
    sfVector2f positions[] = {
        {190, POFT(MIDDLE_Y, 45)},
        {END, END}
    };
    sfVector2f scales[] = {
        {POFT(KEY_SCALE, 4.9), POFT(KEY_SCALE, 1.8)},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};
    texture_t to_draw[] = {SELECTED2, END};

    center_origin_entities(wolf->tex_manager, to_draw);
    draw_texture_multiple(wolf, SELECTED2, &params, 3);
}

static void draw_obj_ind(wolf_t *wolf)
{
    sfVector2f positions[] = {
        {30, MIDDLE_Y},
        {30, POFT(MIDDLE_Y, 40)},
        {30, POFT(MIDDLE_Y, 80)},
        {END, END}
    };
    sfVector2f scales[] = {
        {2.3f, 2.3f},
        {END, END}
    };
    texture_draw_params_t params = {positions, scales};
    texture_t to_draw[] = {OBJ_IND, END};

    center_origin_entities(wolf->tex_manager, to_draw);
    draw_texture_multiple(wolf, OBJ_IND, &params, 3);
}

static void draw_objectives_tex(wolf_t *wolf)
{
    texture_t to_draw[] = {HUD_OBJ, END};
    sfVector2f positions[] = {{189, POFT(MIDDLE_Y, 45)}};
    sfVector2f scales[] = {{POFT(KEY_SCALE, 2.0), POFT(KEY_SCALE, 0.5)}};

    draw_objective_selected(wolf);
    center_origin_entities(wolf->tex_manager, to_draw);
    set_position_entities(wolf->tex_manager, to_draw, positions);
    set_scale_entities(wolf->tex_manager, to_draw, scales);
    draw_entities(wolf, to_draw);
    draw_obj_ind(wolf);
}

static void draw_objectives_hud(wolf_t *wolf)
{
    if (wolf->player.show_objectif == false)
        return;
    draw_objectives_txt(wolf);
    draw_objectives_tex(wolf);
}

void draw_hud(wolf_t *wolf3d)
{
    draw_player_stats(wolf3d);
    draw_items(wolf3d);
    draw_boss_bar(wolf3d);
    draw_hearts(wolf3d);
    animate_boss_key(&wolf3d->tex_manager->assets[BOSS_KEY]);
    draw_invetory(wolf3d);
    draw_objectives_hud(wolf3d);
    draw_kd_hud(&wolf3d->player, wolf3d);
}
