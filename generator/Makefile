##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compilation file
##

CC	= gcc -g

RM	= rm -f

NAME	= generator

SRC	=   generator.c \
        display.c   \
        load_map.c  \
        perfect_maze.c  \
        inperfect_maze.c

OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
