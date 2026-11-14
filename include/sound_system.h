/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** sound_system
*/

#ifndef SOUND_SYSTEM_H_
    #define SOUND_SYSTEM_H_

    #include <SFML/Audio.h>
    #include <stdbool.h>

typedef enum {
    SOUND_SPRINT,
    SOUND_WEAPON_SWITCH,
    SOUND_SHOOT,
    SOUND_FOOTSTEP,
    SOUND_HURT,
    SOUND_POTION,
    SOUND_MAX
} sound_effect_t;

typedef struct {
    sfSound *sounds[SOUND_MAX];
    sfSoundBuffer *buffers[SOUND_MAX];
    bool is_playing[SOUND_MAX];
} sound_system_t;

bool init_sound_system(sound_system_t *system);
void destroy_sound_system(sound_system_t *system);
void play_sound(sound_system_t *sys, sound_effect_t effect);

#endif /* !SOUND_SYSTEM_H_ */
