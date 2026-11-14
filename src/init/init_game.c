/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** init_game
*/

#include "wolf.h"
#include "textures.h"
#include "positions.h"
#include "ennemies.h"

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
        .clock = sfClock_create(),
        .invetory = {false, false, false},
        .deaths = 0,
        .kills = 0,
        .show_kd = false,
        .show_objectif = true,
        .state = PLAYER_STATE_NORMAL,
        .last_dialogue_state = PLAYER_STATE_NORMAL,
    };

    return player;
}

static bool init_textures(ray_context_t *ctx)
{
    ctx->wall_texture = sfTexture_createFromFile(WALL_TEXTURE, NULL);
    ctx->floor_texture = sfTexture_createFromFile(FLOOR_TEXTURE, NULL);
    ctx->main_door_texture = sfTexture_createFromFile(DOOR_TEXTURE, NULL);
    ctx->wood_texture = sfTexture_createFromFile(WOOD_TEXTURE, NULL);
    ctx->bricks_texture = sfTexture_createFromFile(BRICKS_TEXTURE, NULL);
    ctx->moss_bricks_texture = sfTexture_createFromFile(BRICKS_MOSS_TEXTURE, NULL);
    ctx->bricks_with_holes = sfTexture_createFromFile(BRICKS_HOLES_TEXTURE, NULL);
    ctx->old_bricks_texture = sfTexture_createFromFile(BRICKS_OLD_TEXTURE, NULL);
    ctx->wood_bricks_texture = sfTexture_createFromFile(WOOD_BRICKS_TEXTURE, NULL);
    ctx->sec_door_texture = sfTexture_createFromFile(SEC_DOOR_TEXTURE, NULL);
    ctx->boss_door_texture = sfTexture_createFromFile(BOSS_DOOR_TEXTURE, NULL);
    return (ctx->wall_texture && ctx->main_door_texture && ctx->floor_texture
        && ctx->wood_texture && ctx->sec_door_texture
        && ctx->boss_door_texture && ctx->bricks_texture && ctx->moss_bricks_texture
        && ctx->wood_bricks_texture);
}

static bool init_ctx(wolf_t *wolf3d, ray_context_t *ctx)
{
    sfVector2u size = sfRenderWindow_getSize(wolf3d->window);

    if (!init_textures(ctx))
        return false;
    ctx->win = wolf3d->window;
    ctx->player = &wolf3d->player;
    ctx->map = &wolf3d->map;
    ctx->screenW = (int)size.x;
    ctx->screenH = (int)size.y;
    ctx->flash_on = false;
    ctx->zdbuffer = malloc(sizeof(double) * ctx->screenW);
    if (!init_shaders(ctx))
        return false;
    sfRenderWindow_setFramerateLimit(ctx->win, 60);
    return (ctx->zdbuffer != NULL);
}

static bool init_window_and_audio(wolf_t *wolf3d)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGHT, BITS_PER_PX};

    wolf3d->window = sfRenderWindow_create(mode, WIN_TITLE, sfResize | sfClose,
        NULL);
    wolf3d->music = sfMusic_createFromFile(MUSIC_PATH);
    wolf3d->clock = sfClock_create();
    return (wolf3d->window != NULL && wolf3d->music != NULL
        && wolf3d->clock != NULL);
}

static bool init_world(wolf_t *wolf3d, ecs_world_t world)
{
    if (!init_window_and_audio(wolf3d))
        return false;
    wolf3d->world = world;
    wolf3d->player = init_player();
    wolf3d->is_dead = false;
    wolf3d->map = load_map(MAP_PATH);
    wolf3d->game_state = IN_MAIN_MENU;
    wolf3d->ip = malloc(sizeof(char) * IP_LENGHT);
    wolf3d->is_dead = false;
    if (!wolf3d->ip)
        return false;
    return true;
}

static void init_vol_slider(wolf_t *wolf3d)
{
    wolf3d->vol_slider = (slider_t){
        .min_value = 0.0f,
        .max_value = 100.0f,
        .current_value = 50.0f,
        .is_dragging = false
    };
}

static bool init_graphics(wolf_t *wolf3d)
{
    wolf3d->tex_manager = create_texture_manager();
    if (!wolf3d->tex_manager || !init_texture_manager(wolf3d->tex_manager))
        return false;
    return weapon_init(&wolf3d->weapons);
}

bool init_ennemies(wolf_t *wolf3d)
{
    FILE *fp = fopen(ENNEMIES_PATH, "r");
    size_t len = 0;
    size_t count = 0;
    char *buff = NULL;

    if (fp == NULL){
        return false;
    }
    while (getline(&buff, &len, fp) != -1) {
        create_ennemies_entity(&wolf3d->world, buff);
        count++;
    }
    wolf3d->ennemies.nb_ennemies = count;
    add_entity_to_list(wolf3d, count);
    free(buff);
    fclose(fp);
    return true;
}

bool parse_ip_flag(char *av[], int i, int ac, char *ip)
{
    ip[0] = '\0';
    if (i >= ac || strcmp(av[i], "-I") != 0)
        return true;
    if (i + 1 >= ac) {
        printf("Error: Missing IP address after -I flag\n");
        return false;
    }
    strncpy(ip, av[i + 1], 15);
    ip[15] = '\0';
    printf("IP address: %s\n", ip);
    return true;
}

static bool init_dialogue_system(wolf_t *wolf)
{
    wolf->dialogue.clock = sfClock_create();
    if (!wolf->dialogue.clock)
        return false;
    wolf->dialogue.text = NULL;
    wolf->dialogue.duration = 0.0f;
    wolf->dialogue.is_active = false;
    wolf->dialogue.pos = (sfVector2f){WIN_WIDTH / 2, NOFT(WIN_HEIGHT, 140)};
    wolf->dialogue.type = DIALOGUE_NONE;
    return true;
}

bool init_game(wolf_t *wolf3d, ray_context_t *ctx, char **av, int ac)
{
    ecs_world_t world;

    ecs_init(&world);
    if (!init_world(wolf3d, world) || !init_ctx(wolf3d, ctx))
        return false;
    if (!init_graphics(wolf3d))
        return false;
    if (!init_ennemies(wolf3d))
        return false;
    if (!parse_ip_flag(av, 1, ac, wolf3d->ip))
        return false;
    if (!init_dialogue_system(wolf3d))
        return false;
    if (!init_sound_system(&wolf3d->sound_sys))
        return false;
    sfMusic_play(wolf3d->music);
    sfMusic_setLoop(wolf3d->music, true);
    sfMusic_setVolume(wolf3d->music, 75.f);
    minimap_init(&wolf3d->minimap, wolf3d->window);
    init_vol_slider(wolf3d);
    wolf3d->ctx = ctx;
    return true;
}
