/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** network
*/

#ifndef NETWORK_H
    #define NETWORK_H

    #define MAX_PLAYERS 8
    #define PORT 4242
    #define MAX_CLIENTS MAX_PLAYERS
    #define TICK_USEC 50000
    #define PLAYER_SPRITE "assets/Vilain.png"

    struct net_packet_s;
    #define SNAPSHOT_SZ ((int)sizeof(net_game_state_t))
    #define PKT_SZ sizeof(net_packet_t)

typedef enum {
    PKT_STATE = 0,
    PKT_DAMAGE = 1
} pkt_type_t;

typedef struct {
    int id;
    float x;
    float y;
    float dirX;
    float dirY;
    float planeX;
    float planeY;
    float health;
    float stamina;
    float mana;
    int is_alive;
    int kills;
    int deaths;
} net_player_t;

typedef struct {
    int player_count;
    net_player_t players[MAX_PLAYERS];
} net_game_state_t;

typedef struct {
    int attacker_id;
    int target_id;
    float dmg;
} net_damage_t;

typedef struct net_packet_s {
    pkt_type_t type;
    union {
        net_player_t state;
        net_damage_t damage;
    };
} net_packet_t;

typedef struct {
    int fd;
    int id;
} client_info_t;

#endif /* NETWORK_H */
