/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_input
*/

#include "wolf.h"

void set_field_basics(wolf_t *wolf, int i, sfVector2f pos_text)
{
    wolf->input_fields[i].id = i;
    wolf->input_fields[i].active = false;
    wolf->input_fields[i].buffer[0] = '\0';
    wolf->input_fields[i].position = pos_text;
}

void set_field_sprite(wolf_t *wolf, int i, sfVector2f pos_input)
{
    sfVector2f scale = {BTN_SCALE, BTN_SCALE};
    texture_t id = INPUT;

    wolf->input_fields[i].texture = sfTexture_copy(
        wolf->tex_manager->assets[id].texture);
    wolf->input_fields[i].sprite = sfSprite_create();
    sfSprite_setPosition(wolf->input_fields[i].sprite, pos_input);
    sfSprite_setTexture(wolf->input_fields[i].sprite,
        wolf->input_fields[i].texture, sfTrue);
    sfSprite_setScale(wolf->input_fields[i].sprite, scale);
}

void set_field_text(wolf_t *wolf, int i, sfVector2f pos_text)
{
    char *placeholders[] = {"Username", "IP Address"};
    sfColor color = sfColor_fromRGBA(168, 141, 117, 255);

    wolf->input_fields[i].text = sfText_create();
    sfText_setFont(wolf->input_fields[i].text, wolf->tex_manager->font);
    sfText_setCharacterSize(wolf->input_fields[i].text, 24);
    sfText_setPosition(wolf->input_fields[i].text, pos_text);
    sfText_setString(wolf->input_fields[i].text, placeholders[i]);
    sfText_setFillColor(wolf->input_fields[i].text, color);
}

void setup_input_field(wolf_t *wolf, int i, sfVector2f pos_text,
    sfVector2f pos_input)
{
    set_field_basics(wolf, i, pos_text);
    set_field_sprite(wolf, i, pos_input);
    set_field_text(wolf, i, pos_text);
}

bool init_input_fields(wolf_t *wolf)
{
    sfVector2f positions_text[] = {
        {JOIN_BTN_X + 55, JOIN_BTN_Y + 105},
        {JOIN_BTN_X + 55, JOIN_BTN_Y + 205}
    };
    sfVector2f positions_input[] = {
        {JOIN_BTN_X, JOIN_BTN_Y + 90},
        {JOIN_BTN_X, JOIN_BTN_Y + 190},
        {END, END}
    };

    for (int i = 0; i < NB_INPUT; i++) {
        setup_input_field(wolf, i, positions_text[i], positions_input[i]);
    }
    return true;
}
