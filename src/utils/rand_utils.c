/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** rand_utils
*/

#include "wolf.h"

int rng_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
