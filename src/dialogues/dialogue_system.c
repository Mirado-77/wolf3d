/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** dialogue_system
*/

#include "wolf.h"
#include "dialogue.h"

static const char *DIALOGUE_TEXTS[] = {
    [DIALOGUE_DISCOVER] = "Ces murs... ils respirent encore la corruption d'antan.",
    [DIALOGUE_BOSS] = "Je sens une presence malefique... Le Shogun doit etre proche.",
    [DIALOGUE_KEY] = "Cette cle... Elle porte les marques d'un sceau sacre.",
    [DIALOGUE_HURT] = "La douleur n'est qu'une illusion... Je dois perseverer.",
    [DIALOGUE_GENIE] = "Attention les monstres peuvent etre partout",
    [DIALOGUE_MASTER] = "Tu rentre dans le palais du crepuscule attention",
};

void display_dialogue(wolf_t *wolf, dialogue_t type)
{
    if (wolf->dialogue.is_active)
        return;
    wolf->dialogue.text = DIALOGUE_TEXTS[type];
    wolf->dialogue.duration = 4.0f;
    wolf->dialogue.is_active = true;
    wolf->dialogue.type = type;
    sfClock_restart(wolf->dialogue.clock);
}

static void render_dialogue_background(wolf_t *wolf)
{
    texture_t to_draw[] = {SELECTED2, END};
    sfVector2f positions[] = {{WIN_WIDTH / 2, NOFT(WIN_HEIGHT, 130)},
        {END, END}};
    sfVector2f scales[] = {{20.0f, 1.0f}, {END, END}};
    texture_draw_params_t params = {positions, scales};

    center_origin_entities(wolf->tex_manager, to_draw);
    set_position_entities(wolf->tex_manager, to_draw, positions);
    set_scale_entities(wolf->tex_manager, to_draw, scales);
    draw_texture_multiple(wolf, SELECTED2, &params, 3);
}

static void render_dialogue_text(wolf_t *wolf)
{
    sfText *text = sfText_create();
    sfFloatRect bounds;
    sfVector2f textPos;

    sfText_setString(text, wolf->dialogue.text);
    sfText_setFont(text, wolf->tex_manager->font);
    sfText_setCharacterSize(text, 34);
    sfText_setColor(text, sfColor_fromRGBA(168, 141, 117, 255));
    bounds = sfText_getLocalBounds(text);
    textPos = wolf->dialogue.pos;
    textPos.x -= bounds.width / 2;
    textPos.y -= bounds.height / 2;
    sfText_setPosition(text, textPos);
    sfRenderWindow_drawText(wolf->window, text, NULL);
    sfText_destroy(text);
}

void render_dialogue(wolf_t *wolf)
{
    float elapsed = sfTime_asSeconds(
        sfClock_getElapsedTime(wolf->dialogue.clock));

    if (!wolf->dialogue.is_active || !wolf->dialogue.text)
        return;
    if (elapsed > wolf->dialogue.duration) {
        wolf->dialogue.is_active = false;
        return;
    }
    render_dialogue_background(wolf);
    render_dialogue_text(wolf);
}
