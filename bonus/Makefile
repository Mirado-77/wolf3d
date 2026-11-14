##
## EPITECH PROJECT, 2025
## wolf3D
## File description:
## Makefile
##

NAME    = 	server

CC      =	gcc

SRC 	=	src/server.c \

OBJ     = 	$(SRC:.c=.o)

INCS    = 	-iquoteinclude

CFLAGS  = 	-Wall -Wextra $(INCS) -pedantic -std=c11 -O2 -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

gdb: CFLAGS += -g3
gdb: re
	gdb ./$(NAME)

.PHONY: all lib clean fclean re
