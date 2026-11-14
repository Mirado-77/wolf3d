/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** crosshair
*/

#include "crosshair.h"

bool crosshair_init(crosshair_t *crosshair, const char *path,
    float idle_scale, float attack_scale)
{
    crosshair->texture = sfTexture_createFromFile(path, NULL);
    crosshair->idle_scale = idle_scale;
    crosshair->attack_scale = attack_scale;
    return crosshair->texture != NULL;
}

void crosshair_draw(const crosshair_t *crosshair, const xhair_ctx_t *ctx)
{
    sfSprite *sprite = sfSprite_create();
    const sfVector2u size = sfTexture_getSize(crosshair->texture);
    const sfVector2f o = {size.x * 0.5f, size.y * 0.5f};
    float scale = ctx->attacking ?
        crosshair->attack_scale : crosshair->idle_scale;

    sfSprite_setTexture(sprite, crosshair->texture, sfTrue);
    sfSprite_setOrigin(sprite, o);
    sfSprite_setPosition(sprite, (sfVector2f){ctx->W * 0.5f, ctx->H * 0.5f});
    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
    sfRenderWindow_drawSprite(ctx->win, sprite, NULL);
    sfSprite_destroy(sprite);
}
