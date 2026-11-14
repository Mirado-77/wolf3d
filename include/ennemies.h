/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** sprite
*/

#ifndef ENNEMIES_H_
    #define ENNEMIES_H_
    #include "ecs.h"
    #include <SFML/Graphics.h>
    #include "raycasting.h"
    #define SPRITE_WIDGHT 48
    #define ENNEMIES_PATH "configs/ennemies_config.txt"
    #define TEXTURE_PATH_VILAIN "assets/Vilain.png"
    #define DEAD_KEY -42
    #define ALIVE_KEY 15
    #define ENNEMI_DAMAGE 0.5f
    #define DISTANCE 100
    #define SCALE 2
    #define MOVE 64

typedef struct {
    float2_t sprite_pos;
    float2_t transform;
    int2_t Drawstart;
    int2_t Drawend;
    int spriteWidth;
    int spriteHeight;
    sfTexture *vilain_texture;
    int add_in_rect;
} sprite_t;

typedef struct {
    entity_t entity;
    sprite_t sprite;
    sfClock *clock;
} cast_t;

typedef struct {
    cast_t *cast;
    size_t nb_ennemies;
} ennemies_t;

void create_ennemies_entity(ecs_world_t *w, char *line);
void cast_ennemies(ray_context_t *ctx, float2_t ennemie_pos,
    sprite_t sprite, int sprite_widght);
entity_t create_boss_entity(ecs_world_t *w, float x, float y);

#endif /* ENNEMIES_H_ */
