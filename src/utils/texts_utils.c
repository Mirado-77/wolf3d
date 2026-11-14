/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_texts
*/

#include "wolf.h"
#include "textures.h"

void draw_text_entities(wolf_t *wolf3d)
{
    texture_manager_t *tm = wolf3d->tex_manager;

    for (int i = 0; i < TXT_COUNT; i++) {
        if (!tm->texts[i].visible)
            continue;
        sfRenderWindow_drawText(wolf3d->window, tm->sf_texts[i], NULL);
    }
}

void set_text_visibility(texture_manager_t *tm, const int *ids, bool visible)
{
    int id = 0;

    if (!tm || !tm->texts || !ids)
        return;
    for (int i = 0; ids[i] != END; i++) {
        id = ids[i];
        if (id >= 0 && id < TXT_COUNT)
            tm->texts[id].visible = visible;
    }
}

void hide_all_texts(texture_manager_t *tm)
{
    for (int i = 0; i < TXT_COUNT; i++)
        tm->texts[i].visible = false;
}

void destroy_texts_entities(texture_manager_t *manager, const text_id_t *ids,
    size_t id_count)
{
    size_t i = 0;
    text_id_t id = 0;

    if (!manager || !manager->sf_texts)
        return;
    for (i = 0; i < id_count; i++) {
        id = ids[i];
        if (id >= TXT_COUNT)
            continue;
        if (manager->sf_texts[id]) {
            sfText_destroy(manager->sf_texts[id]);
            manager->sf_texts[id] = NULL;
        }
    }
}
