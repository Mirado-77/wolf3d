/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** handle_input_event
*/

#include "wolf.h"

void handle_text_input(sprite_input_field_t *inputs, int input_count,
    sfEvent *event)
{
    for (int i = 0; i < input_count; i++) {
        if (inputs[i].active)
            sprite_input_handle_char(&inputs[i], event->text.unicode);
    }
}

void handle_input_events(wolf_t *wolf3d, sprite_input_field_t *inputs,
    int input_count, sfEvent *event)
{
    sfVector2i mpos;
    sfVector2f fpos;

    if (event->type == sfEvtMouseButtonPressed) {
        mpos = sfMouse_getPositionRenderWindow(wolf3d->window);
        fpos = (sfVector2f){mpos.x, mpos.y};
        update_sprite_input_active(inputs, input_count, fpos);
    }
    if (event->type == sfEvtTextEntered)
        handle_text_input(inputs, input_count, event);
    get_ip_from_input(wolf3d);
}
