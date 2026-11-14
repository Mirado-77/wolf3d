/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** handle_main_menu
*/

#include "wolf.h"

void handle_pause_menu_click(wolf_t *wolf3d, sfVector2i mouse_pos)
{
    const button_handler_t *handler = BUTTON_HANDLERS;

    while (handler->btn_type != END) {
        if (is_btn_clicked(wolf3d, mouse_pos, handler->btn_type)) {
            handler->action(wolf3d);
        }
        handler++;
    }
}
