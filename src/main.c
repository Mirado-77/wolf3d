/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** main
*/

#include "wolf.h"
#include "boss.h"
#include "ennemies.h"
#include "input_handler.h"
#include "textures.h"
#include <stdlib.h>

static void destroy_clocks(wolf_t *wolf3d)
{
    if (wolf3d->player.clock != NULL) {
        sfClock_destroy(wolf3d->player.clock);
        wolf3d->player.clock = NULL;
    }
    if (wolf3d->clock != NULL) {
        sfClock_destroy(wolf3d->clock);
        wolf3d->clock = NULL;
    }
    if (wolf3d->dialogue.clock != NULL) {
        sfClock_destroy(wolf3d->dialogue.clock);
        wolf3d->dialogue.clock = NULL;
    }
}

void destroy_game(wolf_t *wolf3d, ray_context_t *ctx)
{
    if (!wolf3d)
        return;
    destroy_clocks(wolf3d);
    destroy_ctx(ctx);
    if (wolf3d->tex_manager != NULL)
        destroy_texture_manager(wolf3d->tex_manager);
    free_map(&wolf3d->map);
    if (wolf3d->music != NULL)
        sfMusic_destroy(wolf3d->music);
    weapon_destroy(&wolf3d->weapons);
    if (wolf3d->window != NULL)
        sfRenderWindow_destroy(wolf3d->window);
    if (wolf3d->ip != NULL)
        free(wolf3d->ip);
    ecs_destroy(&wolf3d->world);
    free(wolf3d);
}

void update_frame(wolf_t *wolf3d, ray_context_t *ctx)
{
    float dt;

    manage_time_and_status(wolf3d, &dt);
    update_game_state(wolf3d, dt, ctx);
    render_scene(wolf3d, ctx);
    render_interface(wolf3d);
    check_dialogue(wolf3d);
    handle_dialogues(wolf3d);
}

int launch_game(int ac, char **av)
{
    wolf_t *wolf3d = malloc(sizeof(wolf_t));
    ray_context_t ctx;
    sfColor customColor = sfColor_fromRGBA(24, 24, 27, 255);

    if (!init_game(wolf3d, &ctx, av, ac)) {
        destroy_game(wolf3d, &ctx);
        return ERROR;
    }
    wolf3d->local_player_initialized = 0;
    while (sfRenderWindow_isOpen(wolf3d->window)) {
        sfRenderWindow_clear(wolf3d->window, customColor);
        handle_events(wolf3d->window, wolf3d);
        MAIN_STATE_HANDLERS[wolf3d->game_state](wolf3d, &ctx);
        draw_text_entities(wolf3d);
        sfRenderWindow_display(wolf3d->window);
    }
    destroy_game(wolf3d, &ctx);
    return SUCCESS;
}

int main(int ac, char **av)
{
    if (!getenv(DISPLAY))
        return ERROR;
    return launch_game(ac, av);
}
