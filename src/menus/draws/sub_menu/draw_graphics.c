/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_graphics
*/

/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-sandes.savarimuthu
** File description:
** draw_smenu
*/

#include "wolf.h"
#include "positions.h"

static bool check_window_validity(const wolf_t *wolf3d)
{
    return (wolf3d && wolf3d->window && wolf3d->tex_manager &&
        sfRenderWindow_isOpen(wolf3d->window));
}

static void draw_settings_texts(wolf_t *wolf3d)
{
    int ids[] = {TXT_MODE, TXT_SWITCH, END};

    set_text_visibility(wolf3d->tex_manager, ids, true);
}

static void draw_smenu_entities(wolf_t *wolf3d)
{
    sfVector2f positions[] = {{WINDOW_MODE_X, WINDOW_MODE_Y}};
    sfVector2f scales[] = {{BTN_SCALE_2, BTN_SCALE_2}};
    texture_t to_draw[] = {WINDOW_MODE, END };
    texture_t needscale[] = {WINDOW_MODE, END };

    set_position_entities(wolf3d->tex_manager, to_draw, positions);
    set_scale_entities(wolf3d->tex_manager, needscale, scales);
    draw_entities(wolf3d, to_draw);
}

void draw_graphics_menu(wolf_t *wolf3d, ray_context_t *ctx)
{
    draw_smenu(wolf3d, ctx);
    UNUSED(ctx);
    if (!check_window_validity(wolf3d))
        return;
    draw_settings_texts(wolf3d);
    draw_smenu_entities(wolf3d);
}
