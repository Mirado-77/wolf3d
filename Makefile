##
## EPITECH PROJECT, 2025
## wolf3D
## File description:
## Makefile
##

NAME    = wolf3D

CC      = gcc

SRC =   src/raycasting.c \
        src/draw_ennemies.c \
        src/init/init_weapon.c \
        src/init/init_game.c \
        src/init/init_ennemies.c \
        src/main.c \
        src/manage_game.c \
        src/reset_game.c \
        src/load_map_texture.c \
        src/map.c \
        src/utils/free_multiples.c \
        src/utils/texture_manager.c \
        src/utils/set_origin.c \
        src/utils/set_rotation.c \
        src/utils/draw_utils.c \
        src/utils/draw_multiple_instances.c \
        src/utils/texts_utils.c \
        src/utils/rand_utils.c \
        src/utils/is_valid_entity.c \
        src/utils/calc_distance.c \
        src/crosshair.c \
        src/minimap.c \
        src/weapons.c \
        src/menus/switch/switch_to_settings.c \
        src/menus/switch/switch_to_gamemode.c \
        src/menus/switch/quit_game.c \
        src/menus/switch/switch_to_main_menu.c \
        src/menus/switch/switch_to_game_over.c \
        src/menus/switch/switch_to_game.c \
        src/menus/switch/switch_to_multi.c \
        src/menus/switch/switch_to_credits.c \
        src/menus/switch/switch_to_lore.c \
        src/menus/switch/sub_menu/switch_to_graphics.c \
        src/menus/switch/sub_menu/switch_to_audio.c \
        src/menus/switch/sub_menu/switch_to_controls.c \
        src/menus/switch/sub_menu/switch_to_pre_multi.c \
        src/menus/switch/switch_to_win.c \
        src/menus/handles_btns/handle_settings.c \
        src/menus/handles_btns/handle_game.c \
        src/menus/handles_btns/handle_main_menu.c \
        src/menus/handles_btns/handle_pause_menu.c \
        src/menus/handles_btns/handle_player_hud.c \
        src/menus/handles_btns/handle_gamemode.c \
        src/menus/handles_btns/handle_multi_click.c \
        src/menus/draws/draw_gamemode.c \
        src/menus/draws/draw_smenu.c \
        src/menus/draws/draw_hud.c \
        src/menus/draws/draw_menu.c \
        src/menus/draws/draw_pause_menu.c \
        src/menus/draws/draw_lore.c \
        src/menus/draws/sub_menu/draw_graphics.c \
        src/menus/draws/sub_menu/draw_audio.c \
        src/menus/draws/sub_menu/draw_controls.c \
        src/menus/draws/sub_menu/draw_pre_multi.c \
        src/menus/draws/draw_game_over.c \
        src/menus/draws/draw_win_menu.c \
        src/menus/draws/draw_credits.c \
        src/menus/draws/draw_inventory.c \
        src/menus/handle_click.c \
        src/cast_ennemies.c \
        src/input_handler.c \
        src/movements.c \
        src/boss_attacks.c \
        src/boss.c \
        src/shoot.c \
        src/inventory.c \
        src/ennemies_movement.c \
        src/load_animation.c \
        src/floor_rendering.c \
        src/destroy/destroy_ctx.c \
        bonus/src/multiplayer.c \
        src/debug/print_debug_bounds.c \
        src/menus/handle_input/handle_input_event.c \
        src/menus/handle_input/handle_input_char.c \
        src/menus/handle_input/update_input_focus.c \
        src/menus/handle_input/get_ip_from_input.c \
        src/menus/draws/draw_input.c \
        src/init/init_input.c \
        src/torch.c \
        src/init/init_shaders.c \
        src/check_items.c \
        src/menus/handles_btns/handle_boss_bar.c \
        src/HUD/toggle_kd_hud.c \
        src/check_dialogue_state.c \
        src/dialogues/dialogue_system.c \
        src/sound/sound_system.c \

OBJ     = $(SRC:.c=.o)

INCS    = -iquoteinclude -iquotelib/include -iquotebonus/include

CFLAGS  = -Wall -Wextra $(INCS)

LDFLAGS = -Llib -lecs -lm -lcsfml-graphics -lcsfml-window -lcsfml-system \
			-lcsfml-audio

all: lib $(NAME)

lib:
	make -C lib

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -C lib clean

fclean: clean
	rm -f $(NAME)
	make -C lib fclean

re: fclean all

gdb: CFLAGS += -g -O0
gdb: re
	gdb ./$(NAME)

.PHONY: all lib clean fclean re
