/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** crosshair
*/

#ifndef CROSSHAIR_H
    #define CROSSHAIR_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>

typedef struct {
    sfRenderWindow *win;
    int W;
    int H;
    int attacking;
} xhair_ctx_t;

typedef struct {
    sfTexture *texture;
    float idle_scale;
    float attack_scale;
} crosshair_t;

bool crosshair_init(crosshair_t *crosshair, const char *path, float idleScale,
    float atkScale);
void crosshair_draw(const crosshair_t *crosshair, const xhair_ctx_t *ctx);

#endif
