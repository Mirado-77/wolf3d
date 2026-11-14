##
## EPITECH PROJECT, 2025
## ECS Library
## File description:
## Makefile
##

NAME    = libecs.a
CC      = gcc

CFLAGS  = -Wall -Wextra -Iinclude

SRC     = src/ecs_components.c \
          src/ecs_components_five.c \
          src/ecs_components_four.c \
          src/ecs_components_six.c \
          src/ecs_components_three.c \
          src/ecs_components_two.c \
          src/ecs_entity.c \
          src/ecs_init.c \
          src/ecs_manage_components.c \
          src/ecs_components_pv.c \
          src/ecs_boss_component.c \
          src/ecs_utils.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
