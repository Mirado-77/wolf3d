/*
** EPITECH PROJECT, 2024
** ecs 2d
** File description:
** Sandes's 2d ecs lib
*/

#ifndef ECS_H_
    #define ECS_H_
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stdint.h>

    #define BASE_CAPACITY 1000
    #define ERROR 84
    #define SUCCESS 0

typedef unsigned int entity_t;

enum {
    COMP_POSITION = 1 << 0,
    COMP_VELOCITY = 1 << 1,
    COMP_SPRITE = 1 << 2,
    COMP_TEXTURE = 1 << 3,
    COMP_RADIUS = 1 << 4,
    COMP_DESTINATION = 1 << 5,
    COMP_DELAY = 1 << 6,
    COMP_ACTIVE = 1 << 7,
    COMP_HITBOX = 1 << 8,
    COMP_ROTATION = 1 << 9,
    COMP_SCALE = 1 << 10,
    COMP_COLOR = 1 << 11,
    COMP_PV = 1 << 12,
    COMP_BOSS = 1 << 13,
    COMP_TEXTURE_PATH = 1 << 14
};

typedef enum {
    BOSS_IDLE,
    BOSS_ATTACK_MELEE,
    BOSS_ENRAGED,
    BOSS_ATTACK_MELEE_ENRAGED,
    BOSS_STATE_COUNT
} boss_state_t;

typedef struct {
    float max_hp;
    float hp;
    boss_state_t state;
    float state_timer;
    float atk_timer;
} boss_t;

typedef struct {
    void *data;
    size_t elem_size;
    size_t count;
    size_t capacity;
} ecs_array_t;

typedef struct {
    unsigned int *component_mask;
    size_t entity_count;
    size_t entity_capacity;

    ecs_array_t positions;
    ecs_array_t velocities;
    ecs_array_t radius;
    ecs_array_t sprites;
    ecs_array_t textures;
    ecs_array_t destinations;
    ecs_array_t delays;
    ecs_array_t actives;
    ecs_array_t hitboxes;
    ecs_array_t rotations;
    ecs_array_t scales;
    ecs_array_t colors;
    ecs_array_t btn;
    ecs_array_t pv;
    ecs_array_t bosses;
    ecs_array_t texure_path;
} ecs_world_t;

typedef struct {
    float x_off;
    float y_off;
    float width;
    float height;
} hitbox_t;

typedef struct {
    float x;
    float y;
} position_t;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} color_t;

typedef void (*btn_action_t)(entity_t, ecs_world_t *, void *);

// ECS
void ecs_init(ecs_world_t *w);
void ecs_destroy(ecs_world_t *w);
entity_t ecs_create_entity(ecs_world_t *w);
void ecs_remove_entity(ecs_world_t *w, entity_t e);
bool ecs_is_valid_entity(ecs_world_t *w, entity_t e);
bool ecs_resize_arrays(ecs_world_t *w, size_t new_cap);

void ecs_add_component(ecs_world_t *w, entity_t e, unsigned int comp);
void ecs_remove_component(ecs_world_t *w, entity_t e, unsigned int comp);
bool ecs_has_component(ecs_world_t *w, entity_t e, unsigned int comp);

// ARRAY
bool ecs_array_init(ecs_array_t *a, size_t elem_size);
bool ecs_array_resize(ecs_array_t *a, size_t new_cap);
bool ecs_array_ensure(ecs_array_t *a, size_t index);
void *ecs_array_get(ecs_array_t *a, size_t index);

// SET/GET COMP
void ecs_set_position(ecs_world_t *w, entity_t e, float x, float y);
void ecs_get_position(ecs_world_t *w, entity_t e, float *x, float *y);

void ecs_set_velocity(ecs_world_t *w, entity_t e, float vx, float vy);
void ecs_get_velocity(ecs_world_t *w, entity_t e, float *vx, float *vy);

void ecs_set_radius(ecs_world_t *w, entity_t e, float r);
float ecs_get_radius(ecs_world_t *w, entity_t e);

void ecs_set_sprite(ecs_world_t *w, entity_t e, void *sprite);
void *ecs_get_sprite(ecs_world_t *w, entity_t e);

void ecs_set_texture(ecs_world_t *w, entity_t e, void *tex);
void *ecs_get_texture(ecs_world_t *w, entity_t e);

void ecs_set_destination(ecs_world_t *w, entity_t e, float dx, float dy);
void ecs_get_destination(ecs_world_t *w, entity_t e, float *dx, float *dy);

void ecs_set_delay(ecs_world_t *w, entity_t e, float delay_time);
float ecs_get_delay(ecs_world_t *w, entity_t e);

void ecs_set_active(ecs_world_t *w, entity_t e, bool active);
bool ecs_get_active(ecs_world_t *w, entity_t e);

void ecs_set_hitbox(ecs_world_t *w, entity_t e, hitbox_t hitbox);
void ecs_get_hitbox(ecs_world_t *w, entity_t e, hitbox_t *hitbox);

void ecs_set_rotation(ecs_world_t *w, entity_t e, float angle);
float ecs_get_rotation(ecs_world_t *w, entity_t e);

void ecs_set_scale(ecs_world_t *w, entity_t e, float sx, float sy);
void ecs_get_scale(ecs_world_t *w, entity_t e, float *sx, float *sy);

void ecs_set_color(ecs_world_t *w, entity_t e, color_t color);
void ecs_get_color(ecs_world_t *w, entity_t e, color_t *color);

void ecs_set_pv(ecs_world_t *w, entity_t e, int pv);
int ecs_get_pv(ecs_world_t *w, entity_t e);

void ecs_set_boss(ecs_world_t *w, entity_t e, boss_t data);
boss_t *ecs_get_boss(ecs_world_t *w, entity_t e);

void ecs_set_texture_path(ecs_world_t *w, entity_t e, int text);
int ecs_get_texture_path(ecs_world_t *w, entity_t e);

entity_t ecs_first(ecs_world_t *w, unsigned int comp_mask);
entity_t ecs_next(ecs_world_t *w, unsigned int comp_mask, entity_t current);

#endif
