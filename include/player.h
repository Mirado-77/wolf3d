/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** camera
*/

#ifndef CAMERA_H
    #define CAMERA_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "dialogue.h"

    #define MAX_PLAYERS 8
    #define MAX_HEALTH 100
    #define MAX_STAMINA 200
    #define MAX_MANA 500

typedef enum {
    PLAYER_STATE_NORMAL,
    PLAYER_STATE_FIRST_ROOM,
    PLAYER_STATE_FOUND_KEY,
    PLAYER_STATE_NEAR_BOSS,
    PLAYER_STATE_HURT,
    PLAYER_STATE_NEAR_GENIE,
    PLAYER_STATE_NEAR_MASTER,
} player_state_t;

typedef struct {
    bool pot_pv;
    bool pot_mana;
    bool key;
} inventory_t;

typedef struct {
    int id;
    bool is_alive;
    char *pseudo;
    float x;
    float y;
    float dirX;
    float dirY;
    float planeX;
    float planeY;
    float health;
    float stamina;
    float mana;
    sfClock *clock;
    int kills;
    int deaths;
    inventory_t invetory;
    bool show_kd;
    bool show_objectif;
    player_state_t state;
    player_state_t last_dialogue_state;
} player_t;


// Type pour stocker le dialogue associé à chaque état
static const dialogue_t PLAYER_STATE_DIALOGUES[] = {
    [PLAYER_STATE_NORMAL] = DIALOGUE_NONE,
    [PLAYER_STATE_FIRST_ROOM] = DIALOGUE_DISCOVER,
    [PLAYER_STATE_FOUND_KEY] = DIALOGUE_KEY,
    [PLAYER_STATE_NEAR_BOSS] = DIALOGUE_BOSS,
    [PLAYER_STATE_HURT] = DIALOGUE_HURT,
    [PLAYER_STATE_NEAR_GENIE] = DIALOGUE_GENIE,
    [PLAYER_STATE_NEAR_MASTER] = DIALOGUE_MASTER,
};
// POSITION ; VECTEUR DIRECTIONNEL ; CAMERA PLANE ( pour la FOV )

#endif
