/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** update_input_focus
*/

#include "wolf.h"

void update_sprite_input_active(sprite_input_field_t *inputs, int count,
    sfVector2f mouse_pos)
{
    sfFloatRect bounds;

    for (int i = 0; i < count; i++) {
        bounds = sfSprite_getGlobalBounds(inputs[i].sprite);
        inputs[i].active = sfFloatRect_contains(&bounds, mouse_pos.x,
            mouse_pos.y);
        printf("ACTIVE ? %d\n", inputs[i].active);
    }
}
