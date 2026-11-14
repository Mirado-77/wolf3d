/*
** EPITECH PROJECT, 2025
** draw_inventory.c
** File description:
** draw object in hud
*/

#include "wolf.h"
#include "textures.h"
#include "positions.h"


static void draw_boss_key(wolf_t *wolf3d)
{
    texture_t to_draw[] = {BOSS_KEY, END};
    sfVector2f positions[] = {{BOSS_KEY_X, BOSS_KEY_Y}};
    sfVector2f scale[] = {{BOSS_KEY_SX, BOSS_KEY_SY}};

    center_origin_entities(wolf3d->tex_manager, to_draw);
    rotate_entities(wolf3d->tex_manager, to_draw, KEY_ANGLE);
    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scale);
    draw_entities(wolf3d, to_draw);
}

static void draw_spell_preview(wolf_t *wolf3d)
{
    texture_t to_draw[] = {PREVIEW_SP1, PREVIEW_SP2, PREVIEW_SP3, END};
    sfVector2f positions[] = {{SPELL_1_3_X, SPELL_1_3_Y},
        {SPELL_2_3_X, SPELL_2_3_Y}, {SPELL_3_3_X, SPELL_3_3_Y}};
    sfVector2f scale[] = {{SPELL_SCALE, SPELL_SCALE},
        {SPELL2_SCALE, SPELL2_SCALE}, {TORCH_SCALE, TORCH_SCALE}};

    center_origin_entities(wolf3d->tex_manager, to_draw);
    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scale);
    draw_entities(wolf3d, to_draw);
}

static void draw_bottles_mana(wolf_t *wolf3d)
{
    texture_t to_draw[] = {MANA_BOTLE, END};
    sfVector2f positions[] = {{MANA_BOTLE_X, MANA_BOTLE_Y}};
    sfVector2f scale[] = {{BOTTLE_SX, BOTTLE_SY}};

    center_origin_entities(wolf3d->tex_manager, to_draw);
    rotate_entities(wolf3d->tex_manager, to_draw, BOTTLE_ANGLE);
    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scale);
    draw_entities(wolf3d, to_draw);
}

static void draw_bottles_hp(wolf_t *wolf3d)
{
    texture_t to_draw[] = {HEALTH_BOTLE, END};
    sfVector2f positions[] = {{HEALTH_BOTLE_X, HEALTH_BOTLE_Y}};
    sfVector2f scale[] = {{BOTTLE_SX, BOTTLE_SY}};

    center_origin_entities(wolf3d->tex_manager, to_draw);
    rotate_entities(wolf3d->tex_manager, to_draw, BOTTLE_ANGLE);
    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, to_draw, scale);
    draw_entities(wolf3d, to_draw);
}

void draw_invetory(wolf_t *wolf3d)
{
    if (wolf3d->ctx->player->invetory.pot_mana){
        draw_bottles_mana(wolf3d);
        wolf3d->player.state = PLAYER_STATE_FIRST_ROOM;
    }
    if (wolf3d->ctx->player->invetory.pot_pv){
        draw_bottles_hp(wolf3d);
    }
    if (wolf3d->ctx->player->invetory.key){
        draw_boss_key(wolf3d);
        wolf3d->player.state = PLAYER_STATE_FOUND_KEY;
    }
    draw_spell_preview(wolf3d);
}
