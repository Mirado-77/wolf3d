/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** quit_game
*/

#include "wolf.h"

void quit_game(wolf_t *wolf3d)
{
    sfRenderWindow_close(wolf3d->window);
    return;
}
