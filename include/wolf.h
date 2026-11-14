/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** wolf
*/

#ifndef WOLF_H_
    #define WOLF_H_
    #include <stdio.h>
    #include "player.h"
    #include "map.h"
    #include "network.h"
    #include "ecs.h"
    #include "weapons.h"
    #include "textures.h"
    #include "raycasting.h"
    #include "minimap.h"
    #include "ennemies.h"
    #include "dialogue.h"
    #include "sound_system.h"
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #define MUSIC_PATH "assets/music.ogg"
    #define FONT_PATH "assets/alagard.ttf"
    #define IP_LENGHT 16
    #define NB_INPUT 2
    #define BITS_PER_PX 32
    #define WIN_TITLE "WOLF3D"
    #define UNUSED(x) (void)(x)
    #define STATE_STACK_SIZE 16
    #define IP_LENGHT 16
    #define ERROR_IP "Error you need to specify an IP adress retry with"
    #define ERROR_IP_1 "\"-I <IP_SERVER>\"\n"
    #define DISPLAY "DISPLAY"

typedef enum {
    IN_GAME = 0,
    IN_SETTING = 1,
    IN_MAIN_MENU = 2,
    IN_PAUSE = 3,
    IN_GAMEMODE = 4,
    IN_BACKROOM = 5,
    IN_MULTI = 6,
    IN_ZOMBIE = 7,
    IN_SUB_AUDIOS = 8,
    IN_SUB_CONTROLS = 9,
    IN_SUB_GRAPHICS = 10,
    IN_PRE_MULTI = 11,
    IN_GAME_OVER = 12,
    IN_CREDITS = 13,
    IN_WIN = 14,
    IN_LORE = 15,
} state_t;

typedef struct slider_s {
    float min_value;
    float max_value;
    float current_value;
    sfVector2f position;
    bool is_dragging;
} slider_t;

typedef struct {
    int id;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfVector2f position;
    bool active;
    char buffer[64];
} sprite_input_field_t;

typedef struct wolf_s {
    sfRenderWindow *window;
    sfMusic *music;
    sfClock *clock;
    sfClock *move_clock;
    player_t player;
    int player_id;
    int player_count;
    int local_player_initialized;
    int sock;
    bool is_dead;
    net_player_t players[MAX_PLAYERS];
    map_t map;
    ecs_world_t world;
    state_t game_state;
    texture_manager_t *tex_manager;
    weapon_sys_t weapons;
    minimap_t minimap;
    ray_context_t *ctx;
    slider_t vol_slider;
    ennemies_t ennemies;
    sfBool is_fullscreen;
    sprite_input_field_t input_fields[NB_INPUT];
    char *ip;
    dialogue_system_t dialogue;
    sound_system_t sound_sys;
} wolf_t;


void display_dialogue(wolf_t *wolf, dialogue_t type);
void render_dialogue(wolf_t *wolf);
void handle_dialogues(wolf_t *wolf3d);
void check_dialogue(wolf_t *wolf3d);


bool init_game(wolf_t *wolf3d, ray_context_t *ctx, char **av, int ac);
bool init_shaders(ray_context_t *ctx);
bool reset_game(wolf_t *wolf3d, ray_context_t *ctx);
bool init_ennemies(wolf_t *wolf3d);
bool init_particule(wolf_t *wolf3d);
void update_frame(wolf_t *wolf3d, ray_context_t *ctx);
void destroy_game(wolf_t *wolf3d, ray_context_t *ctx);

int rng_int(int min, int max);

void switch_to_game(wolf_t *wolf3d);
void quit_game(wolf_t *wolf3d);
void switch_to_settings(wolf_t *wolf3d);
void switch_to_main_menu(wolf_t *wolf3d);
void switch_to_gamemode(wolf_t *wolf3d);
void switch_to_multi(wolf_t *wolf3d);
void switch_to_graphics(wolf_t *wolf3d);
void switch_to_audio(wolf_t *wolf3d);
void switch_to_controls(wolf_t *wolf3d);
void switch_to_pre_multi(wolf_t *wolf3d);
void switch_to_game_over(wolf_t *wolf3d);
void switch_to_credits(wolf_t *wolf3d);
void switch_to_win(wolf_t *wolf3d);
void switch_to_lore(wolf_t *wolf3d);

void render_interface(wolf_t *wolf3d);
void render_scene(wolf_t *wolf3d, ray_context_t *ctx);
void update_game_state(wolf_t *wolf3d, float dt, ray_context_t *ctx);
void manage_time_and_status(wolf_t *wolf3d, float *dt);
void update_stamina_mana(wolf_t *wolf3d);

bool is_valid_entity(texture_manager_t *manager, texture_t entity);
void draw_entities(wolf_t *wolf3d, texture_t *entities);
void set_to_true(texture_manager_t *manager, texture_t *entities);
void undraw_entities(texture_manager_t *manager, texture_t *entities);
void draw_text_entities(wolf_t *wolf3d);
void draw_texture_multiple(wolf_t *wolf3d, texture_t texture_id,
    texture_draw_params_t *params, size_t draw_count);
void set_text_visibility(texture_manager_t *tm, const int *ids, bool visible);
void hide_all_texts(texture_manager_t *tm);
void handle_click(wolf_t *wolf3d, sfEvent event);
void set_scale_entities(texture_manager_t *manager, texture_t *entities,
    sfVector2f *scale);
void set_position_entities(texture_manager_t *manager, texture_t *entities,
    sfVector2f *positions);
void center_origin_entities(texture_manager_t *manager, texture_t *entities);
void rotate_entities(texture_manager_t *manager, texture_t *entities,
    float angle);
void handle_events(sfRenderWindow *window, wolf_t *wolf3d);
void handle_player_hud(wolf_t *wolf, texture_t *hud, const sfIntRect *base);
void handle_boss_bar(wolf_t *wolf, texture_t *boss, const sfIntRect *base);
void decrease_player_stats(wolf_t *wolf, float health_dec,
    float stamina_dec, float mana_dec);
void update_stamina_mana(wolf_t *wolf3d);

typedef void (*btn_action_func_t)(wolf_t *);

typedef struct button_handler_s {
    texture_t btn_type;
    btn_action_func_t action;
} button_handler_t;

static const button_handler_t BUTTON_HANDLERS[] = {
    {PLAY_BTN, &switch_to_game},
    {SETTINGS_BTN, &switch_to_settings},
    {LEAVE_BTN, &quit_game},
    {BACK_BTN, &switch_to_main_menu},
    {GAMEMODE_BTN, &switch_to_gamemode},
    {CLOSE_BTN, &switch_to_game},
    {GRAPHICS_BTN, &switch_to_graphics},
    {AUDIO_BTN, &switch_to_audio},
    {CONTROLS_BTN, &switch_to_controls},
    // {ZOMBIE_BTN, &switch_to_game},
    // {BR_BTN, &switch_to_main_menu},
    {MULTI_BTN, &switch_to_multi},
    {CREDITS_BTN, &switch_to_credits},
    {LORE_BTN, &switch_to_lore},
    // {JOIN_BTN, &switch_to_multi},
    {END, NULL}
};

typedef void (*state_draw_func_t)(wolf_t *, ray_context_t *);

void draw_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_smenu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_gamemode_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_pause_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_graphics_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_audio_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_controls_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_pre_multi_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_game_over_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_credits_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_win_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_lore_menu(wolf_t *wolf3d, ray_context_t *ctx);
void draw_hud(wolf_t *wolf3d);
void update_multiplayer_frame(wolf_t *wolf3d, ray_context_t *ctx);

static const state_draw_func_t MAIN_STATE_HANDLERS[] = {
    [IN_GAME] = &update_frame,
    [IN_SETTING] = &draw_smenu,
    [IN_MAIN_MENU] = &draw_menu,
    [IN_GAMEMODE] = &draw_gamemode_menu,
    [IN_BACKROOM] = &draw_smenu,
    [IN_MULTI] = &update_multiplayer_frame,
    [IN_PRE_MULTI] = &draw_pre_multi_menu,
    [IN_ZOMBIE] = &draw_smenu,
    [IN_PAUSE] = &draw_pause_menu,
    [IN_SUB_GRAPHICS] = &draw_graphics_menu,
    [IN_SUB_AUDIOS] = &draw_audio_menu,
    [IN_SUB_CONTROLS] = &draw_controls_menu,
    [IN_GAME_OVER] = &draw_game_over_menu,
    [IN_CREDITS] = &draw_credits_menu,
    [IN_WIN] = &draw_win_menu,
    [IN_LORE] = &draw_lore_menu,
};

typedef void (*state_btn_func_t)(wolf_t *, sfVector2i);

bool is_btn_clicked(wolf_t *wolf3d, sfVector2i mouse_pos,
    texture_t btn_type);
bool is_btn_hovered(wolf_t *wolf3d, sfVector2i mouse_pos,
    texture_t btn_type);

void handle_settings(wolf_t *wolf3d, sfVector2i mouse_pos);
void handle_main_menu_click(wolf_t *wolf3d, sfVector2i mouse_pos);
void handle_pause_menu_click(wolf_t *wolf3d, sfVector2i mouse_pos);
void handle_gamemode(wolf_t *wolf3d, sfVector2i mouse_pos);
void handle_game(wolf_t *wolf3d, sfVector2i mouse_pos);
void handle_multi_click(wolf_t *wolf3d, sfVector2i mouse_pos);

static const state_btn_func_t BTN_STATE_HANDLERS[] = {
    [IN_SETTING] = &handle_settings,
    [IN_MAIN_MENU] = &handle_main_menu_click,
    [IN_GAMEMODE] = &handle_gamemode,
    [IN_GAME] = &handle_game,
    [IN_PAUSE] = &handle_pause_menu_click,
    [IN_SUB_GRAPHICS] = &handle_settings,
    [IN_SUB_AUDIOS] = &handle_settings,
    [IN_SUB_CONTROLS] = &handle_settings,
    // [IN_BACKROOM] = &handle_backrooms,
    [IN_MULTI] = &handle_multi_click,
    [IN_PRE_MULTI] = &handle_multi_click,
    [IN_GAME_OVER] = &handle_settings,
    [IN_CREDITS] = &handle_settings,
    [IN_WIN] = &handle_settings,
    [IN_LORE] = &handle_settings,
    // [IN_ZOMBIE] = &handle_zombies,
};

void add_entity_to_list(wolf_t *wolf3d, size_t count);
void draw_ennemies(wolf_t *wolf3d, ray_context_t *ctx);

void ecs_apply_damage(ecs_world_t *w, entity_t e, int damage);
void weapon_shoot(weapon_sys_t *weapons, ray_context_t *ctx, wolf_t *wolf);
void weapon_shoot_multi(weapon_sys_t *weapons, ray_context_t *ctx,
    wolf_t *wolf);
void weapon_update(weapon_sys_t *weapon_sys, ray_context_t *ctx, wolf_t *wolf);

bool free_and_null(bool retval, ...);
void destroy_ctx(ray_context_t *ctx);

// INPUT
bool init_input_fields(wolf_t *wolf);
void update_sprite_input_active(sprite_input_field_t *inputs, int count,
    sfVector2f mouse_pos);
void handle_input_events(wolf_t *wolf3d, sprite_input_field_t *inputs,
    int input_count, sfEvent *event);
void draw_sprite_inputs(sfRenderWindow *win, sprite_input_field_t *inputs,
    int count);
void sprite_input_handle_char(sprite_input_field_t *input, sfUint32 unicode);
bool get_ip_from_input(wolf_t *wolf);

void draw_debug_bounds(wolf_t *wolf3d, texture_asset_t *asset);

double calcul_distance(wolf_t *wolf3d,
    entity_t ennemies, ray_context_t *ctx);
void check_items(wolf_t *w, ray_context_t *ctx);
void redraw_items(wolf_t *w);

#endif /* !WOLF_H_ */
