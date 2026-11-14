/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** sound_system
*/

#include "sound_system.h"
#include <stdbool.h>
#include <stdio.h>

static const char *SOUND_PATH[SOUND_MAX] = {
    [SOUND_HURT] = "assets/sounds/hurt.ogg",
    [SOUND_POTION] = "assets/sounds/potion.ogg",
    [SOUND_FOOTSTEP] = "assets/sounds/walking.ogg",
    [SOUND_SPRINT] = NULL,
    [SOUND_WEAPON_SWITCH] = NULL,
    [SOUND_SHOOT] = NULL,
};

bool init_sound_system(sound_system_t *sys)
{
    for (int i = 0; i < SOUND_MAX; i++) {
        sys->buffers[i] = NULL;
        sys->sounds[i] = NULL;
        sys->is_playing[i] = false;
    }
    for (int i = 0; i < SOUND_MAX; i++) {
        if (SOUND_PATH[i] == NULL)
            continue;
        sys->buffers[i] = sfSoundBuffer_createFromFile(SOUND_PATH[i]);
        if (!sys->buffers[i]) {
            printf("Failed to load sound: %s\n", SOUND_PATH[i]);
            continue;
        }
        sys->sounds[i] = sfSound_create();
        if (!sys->sounds[i]) {
            sfSoundBuffer_destroy(sys->buffers[i]);
            sys->buffers[i] = NULL;
            continue;
        }
        sfSound_setBuffer(sys->sounds[i], sys->buffers[i]);
    }
    return true;
}

void destroy_sound_system(sound_system_t *sys)
{
    for (int i = 0; i < SOUND_MAX; i++) {
        sfSound_destroy(sys->sounds[i]);
        sfSoundBuffer_destroy(sys->buffers[i]);
    }
}

void play_sound(sound_system_t *sys, sound_effect_t effect)
{
    if (effect < 0 || effect >= SOUND_MAX)
        return;
    if (!sys || !sys->sounds[effect] || !sys->buffers[effect])
        return;
    sfSoundStatus status = sfSound_getStatus(sys->sounds[effect]);
    if (status == sfPlaying)
        return;
    sfSound_play(sys->sounds[effect]);
}
