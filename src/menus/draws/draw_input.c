/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_input
*/

#include "wolf.h"

void draw_sprite_inputs(sfRenderWindow *win, sprite_input_field_t *inputs,
    int count)
{
    for (int i = 0; i < count; i++) {
        sfRenderWindow_drawSprite(win, inputs[i].sprite, NULL);
        sfRenderWindow_drawText(win, inputs[i].text, NULL);
    }
}
