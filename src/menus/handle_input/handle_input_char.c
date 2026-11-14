/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** handle_input_char
*/

#include "wolf.h"

void sprite_input_handle_char(sprite_input_field_t *input, sfUint32 unicode)
{
    int len = strlen(input->buffer);

    if (unicode == 8 && len > 0) {
        input->buffer[len - 1] = '\0';
    } else if (unicode >= 32 && unicode < 128 && len < 63) {
        input->buffer[len] = (char)unicode;
        input->buffer[len + 1] = '\0';
    }
    sfText_setString(input->text, input->buffer);
}
