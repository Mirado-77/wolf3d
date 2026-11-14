/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** dialogue
*/

#ifndef DIALOGUE_H_
    #define DIALOGUE_H_
    #include <SFML/Graphics.h>

typedef enum {
    DIALOGUE_NONE,
    DIALOGUE_DISCOVER,
    DIALOGUE_BOSS,
    DIALOGUE_KEY,
    DIALOGUE_HURT,
    DIALOGUE_GENIE,
    DIALOGUE_MASTER,
} dialogue_t;

typedef struct {
    const char *text;
    float duration;
    sfClock *clock;
    bool is_active;
    sfVector2f pos;
    dialogue_t type;
} dialogue_system_t;

#endif /* !DIALOGUE_H_ */
