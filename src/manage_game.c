/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** manage_game
*/

#include "wolf.h"
#include "boss.h"
#include "input_handler.h"
#include "dialogue.h"

void update_stamina_mana(wolf_t *wolf3d)
{
    wolf3d->player.stamina += (wolf3d->player.stamina < 199) ? 0.2f : 0;
    wolf3d->player.mana += (wolf3d->player.mana < 199) ? 0.5f : 0;
}

void manage_time_and_status(wolf_t *wolf3d, float *dt)
{
    sfTime elapsed = sfClock_getElapsedTime(wolf3d->clock);
    entity_t e = ecs_first(&wolf3d->world, COMP_BOSS);
    boss_t *boss = ecs_get_boss(&wolf3d->world, e);

    *dt = sfTime_asSeconds(elapsed);
    sfClock_restart(wolf3d->clock);
    if (wolf3d->player.health <= 0) {
        wolf3d->is_dead = true;
        switch_to_game_over(wolf3d);
        reset_game(wolf3d, wolf3d->ctx);
    }
    if (boss != NULL) {
        if (boss->hp <= 0) {
            switch_to_win(wolf3d);
            reset_game(wolf3d, wolf3d->ctx);
        }
    }
}

void update_game_state(wolf_t *wolf3d, float dt, ray_context_t *ctx)
{
    process_input(&wolf3d->player, dt, wolf3d, &wolf3d->weapons);
    update_stamina_mana(wolf3d);
    boss_update(wolf3d, dt);
    check_items(wolf3d, ctx);
    redraw_items(wolf3d);
}

void render_scene(wolf_t *wolf3d, ray_context_t *ctx)
{
    cast_rays(ctx);
    draw_ennemies(wolf3d, ctx);
    weapon_update(&wolf3d->weapons, ctx, wolf3d);
    weapon_draw(&wolf3d->weapons, wolf3d->window, ctx->screenW, ctx->screenH);
}

void render_interface(wolf_t *wolf3d)
{
    texture_t hud[] = {BLOOD_LINE, MANA_LINE, STAMINA_LINE, END};

    handle_player_hud(wolf3d, hud, RECT_TEXTURE);
    minimap_draw(&wolf3d->minimap, &wolf3d->map, &wolf3d->player);
    draw_hud(wolf3d);
}

void handle_dialogues(wolf_t *wolf3d)
{
    dialogue_t dialogue;

    if (wolf3d->player.state != wolf3d->player.last_dialogue_state) {
        dialogue = PLAYER_STATE_DIALOGUES[wolf3d->player.state];
        if (dialogue != DIALOGUE_NONE)
            display_dialogue(wolf3d, dialogue);
        wolf3d->player.last_dialogue_state = wolf3d->player.state;
    }
    render_dialogue(wolf3d);
}   
