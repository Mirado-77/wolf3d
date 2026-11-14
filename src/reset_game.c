/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** reset_game
*/

#include "wolf.h"

static player_t init_player(void)
{
    player_t player = {
        .x = 3.f,
        .y = 3.f,
        .dirX = -1.f,
        .dirY = 0.f,
        .planeX = 0.f,
        .planeY = 0.66f,
        .health = MAX_HEALTH,
        .stamina = MAX_STAMINA,
        .mana = MAX_MANA,
        .clock = sfClock_create()
    };

    return player;
}

static void destroy_ennemies(wolf_t *wolf3d)
{
    for (size_t i = 0; i < wolf3d->ennemies.nb_ennemies; i++) {
        ecs_remove_entity(&wolf3d->world, wolf3d->ennemies.cast[i].entity);
        sfClock_destroy(wolf3d->ennemies.cast[i].clock);
        if (wolf3d->ennemies.cast[i].sprite.vilain_texture != NULL) {
            sfTexture_destroy(wolf3d->ennemies.cast[i].sprite.vilain_texture);
            wolf3d->ennemies.cast[i].sprite.vilain_texture = NULL;
        }
    }
    free(wolf3d->ennemies.cast);
}

bool reset_game(wolf_t *wolf3d, ray_context_t *ctx)
{
    free_map(&wolf3d->map);
    destroy_ennemies(wolf3d);
    wolf3d->player = init_player();
    ctx->player = &wolf3d->player;
    wolf3d->is_dead = false;
    wolf3d->map = load_map(MAP_PATH);
    if (!ctx->player || init_ennemies(wolf3d) == false)
        return false;
    return true;
}
