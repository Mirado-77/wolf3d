/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** get_ip_from_input
*/

#include "wolf.h"
#include <string.h>

bool get_ip_from_input(wolf_t *wolf)
{
    int i = 0;
    char *src = NULL;

    for (i = 0; i < NB_INPUT; i++) {
        if (wolf->input_fields[i].id == 1) {
            src = wolf->input_fields[i].buffer;
            strncpy(wolf->ip, src, IP_LENGHT - 1);
            wolf->ip[IP_LENGHT - 1] = '\0';
            return true;
        }
    }
    return false;
}
