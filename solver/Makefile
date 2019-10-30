##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compilation file
##

CC	= gcc -g

RM	= rm -f

NAME    = solver

SRC	=   solver.c    \
        get_next_line.c \
        tools.c \
        map_reader.c    \
        display_function.c  \
        pos_check.c \
        wall_finder.c

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
