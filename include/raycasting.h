/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** raycasting
*/

#ifndef RAYCASTING_H
    #define RAYCASTING_H

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Shader.h>
    #include "player.h"
    #include "map.h"

    #define TEXW 64
    #define TEXF 64.f
    #define TEXH 64
    #define TEXMASK 63
    #define FLOOR_OPAQUENESS 150
    #define MAX_WALL_DISTANCE 20.0f
    #define MAX_FLOOR_DISTANCE 17.0f
    #define WALL_SHADER "shaders/wall_shader.frag"
    #define FLOOR_SHADER "shaders/floor_shader.frag"
    #define WALL_TEXTURE "assets/textures/wall1.png"
    #define FLOOR_TEXTURE "assets/textures/floor1.png"
    #define WOOD_TEXTURE "assets/textures/wall2.png"
    #define BRICKS_TEXTURE "assets/textures/stones/bricks.png"
    #define BRICKS_MOSS_TEXTURE "assets/textures/stones/stones_with_moss.png"
    #define BRICKS_OLD_TEXTURE "assets/textures/stones/stones_without_moss.png"
    #define WOOD_BRICKS_TEXTURE "assets/textures/wall_with_bricks.png"
    #define BRICKS_HOLES_TEXTURE "assets/textures/stones/stones_with_holes.png"
    #define DOOR_TEXTURE "assets/textures/door1.png"
    #define SEC_DOOR_TEXTURE "assets/textures/door2.png"
    #define BOSS_DOOR_TEXTURE "assets/textures/boss_door.png"


typedef struct {
    float x;
    float y;
} float2_t;

typedef struct {
    int x;
    int y;
} int2_t;

typedef struct {
    float cameraX;
    float2_t rayDir;
    int2_t mapCoord;
    float2_t deltaDist;
    float2_t sideDist;
    int2_t step;
    int hit;
    int side;
    float perpWallDist;
    int lineHeight;
    int drawStart;
    int drawEnd;
} ray_t;

typedef struct {
    sfRenderWindow *win;
    player_t *player;
    map_t *map;
    int screenW;
    int screenH;
    sfTexture *wall_texture;
    sfTexture *floor_texture;
    sfTexture *main_door_texture;
    sfTexture *sec_door_texture;
    sfTexture *boss_door_texture;
    sfTexture *wood_texture;
    sfTexture *bricks_texture;
    sfTexture *moss_bricks_texture;
    sfTexture *bricks_with_holes;
    sfTexture *old_bricks_texture;
    sfTexture *wood_bricks_texture;
    double *zdbuffer;
    sfShader *wall_shader;
    sfShader *floor_shader;
    bool flash_on;
} ray_context_t;

typedef struct {
    int x;
    int start;
    int end;
    sfColor color;
} line_t;

typedef struct {
    float dirX0;
    float dirY0;
    float dirX1;
    float dirY1;
    float posZ;
} rf_maths_t;

typedef struct floor_data_s {
    const sfUint8 *tex_pixels;
    sfUint8 *frame_buffer;
    const rf_maths_t *floor_math;
} floor_data_t;

typedef struct floor_vars_s {
    float p;
    float rowDist;
    float stepX;
    float stepY;
    float floorX;
    float floorY;
} floor_vars_t;

void cast_rays(ray_context_t *ctx);
rf_maths_t get_floor_math(const player_t *player, int screenH);
void draw_floor_texture(ray_context_t *ctx, sfImage *img);
void draw_floor_strips(ray_context_t *ctx,
    const rf_maths_t *floor_math, const sfUint8 *tex_pixels);
sfTexture *set_correct_texture(const ray_t *r, const ray_context_t *ctx);

#endif
