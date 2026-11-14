/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** texture_manager
*/

#include "textures.h"
#include "wolf.h"
#include <stdlib.h>

static bool init_text_entities(texture_manager_t *manager)
{
    sfColor customColor = sfColor_fromRGBA(168, 141, 117, 255);

    if (!manager || !manager->font)
        return false;
    for (int i = 0; i < TXT_COUNT; i++) {
        manager->texts[i] = TEXT_ENTITIES[i];
        manager->sf_texts[i] = sfText_create();
        if (!manager->sf_texts[i])
            continue;
        sfText_setFont(manager->sf_texts[i], manager->font);
        sfText_setString(manager->sf_texts[i], manager->texts[i].str);
        sfText_setCharacterSize(manager->sf_texts[i], manager->texts[i].size);
        sfText_setPosition(manager->sf_texts[i], manager->texts[i].pos);
        sfText_setFillColor(manager->sf_texts[i], customColor);
    }
    return true;
}

static bool init_text(texture_manager_t *manager)
{
    manager->font = sfFont_createFromFile(FONT_PATH);
    if (!manager->font)
        return false;
    manager->texts = malloc(sizeof(text_entity_t) * TXT_COUNT);
    if (!manager->texts) {
        free(manager->font);
        return false;
    }
    manager->sf_texts = malloc(sizeof(sfText *) * TXT_COUNT);
    if (!manager->sf_texts)
        return free_and_null(false, manager->font, manager->texts);
    if (!init_text_entities(manager))
        return free_and_null(false, manager->font, manager->texts,
            manager->sf_texts);
    return true;
}

texture_manager_t *create_texture_manager(void)
{
    texture_manager_t *manager = malloc(sizeof(texture_manager_t));

    if (!manager)
        return NULL;
    manager->count = sizeof(TEXTURES_PATHS) / sizeof(TEXTURES_PATHS[0]);
    manager->assets = malloc(sizeof(texture_asset_t) * manager->count);
    if (!manager->assets) {
        free(manager);
        return NULL;
    }
    for (size_t i = 0; i < manager->count; i++) {
        manager->assets[i].sprite = NULL;
        manager->assets[i].texture = NULL;
        manager->assets[i].rect = RECT_TEXTURE[i];
        manager->assets[i].is_loaded = false;
    }
    manager->initialized = false;
    return manager;
}

static bool init_asset(texture_asset_t *asset, const char *path)
{
    asset->texture = sfTexture_createFromFile(path, NULL);
    if (!asset->texture)
        return false;
    asset->sprite = sfSprite_create();
    if (!asset->sprite) {
        sfTexture_destroy(asset->texture);
        return false;
    }
    sfSprite_setTexture(asset->sprite, asset->texture, sfTrue);
    sfSprite_setTextureRect(asset->sprite, asset->rect);
    asset->is_loaded = true;
    return true;
}

bool init_texture_manager(texture_manager_t *manager)
{
    if (!manager || manager->initialized)
        return false;
    for (size_t i = 0; i < manager->count; i++) {
        if (!init_asset(&manager->assets[i], TEXTURES_PATHS[i]))
            return false;
    }
    if (!init_text(manager))
        return false;
    manager->initialized = true;
    return true;
}

sfSprite *get_sprite(texture_manager_t *manager, texture_t id)
{
    if (!manager || !manager->initialized || id >= (texture_t)manager->count
        || id < 0)
        return NULL;
    return manager->assets[id].sprite;
}

sfTexture *get_texture(texture_manager_t *manager, texture_t id)
{
    if (!manager || !manager->initialized || id >= (texture_t)manager->count
        || id < 0)
        return NULL;
    return manager->assets[id].texture;
}

static void destroy_text(texture_manager_t *manager)
{
    for (int i = 0; i < TXT_COUNT; i++) {
        if (manager->sf_texts[i])
            sfText_destroy(manager->sf_texts[i]);
    }
}

static void destroy_text_manager(texture_manager_t *manager)
{
    if (!manager)
        return;
    if (manager->sf_texts) {
        destroy_text(manager);
        free(manager->sf_texts);
        manager->sf_texts = NULL;
    }
    if (manager->texts) {
        free(manager->texts);
        manager->texts = NULL;
    }
    if (manager->font) {
        sfFont_destroy(manager->font);
        manager->font = NULL;
    }
}

void destroy_texture_manager(texture_manager_t *manager)
{
    if (!manager)
        return;
    for (size_t i = 0; i < manager->count; i++) {
        if (manager->assets[i].sprite)
            sfSprite_destroy(manager->assets[i].sprite);
        if (manager->assets[i].texture)
            sfTexture_destroy(manager->assets[i].texture);
        printf("[DEBUG (QUIT GAME)] Entitty [%s] has been destroyed !\n",
            TEXTURES_PATHS[i]);
    }
    destroy_text_manager(manager);
    free(manager->assets);
    free(manager);
}
