/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** multiplayer
*/

#ifndef MULTIPLAYER_H
    #define MULTIPLAYER_H
    #include "wolf.h"

    #define LOCAL_IP "127.0.0.1"

void multiplayer_init(wolf_t *wolf, char *ip);

int connect_to_server(wolf_t *wolf, const char *ip);

void send_player_state(wolf_t *wolf);
int receive_players_state(wolf_t *wolf);

#endif
