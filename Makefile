##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compilation file
##

all:
	make -C ./generator
	make -C ./solver

clean:
	make clean -C ./generator
	make clean -C ./solver

fclean:
	make fclean -C ./generator
	make fclean -C ./solver

re:	fclean all

.PHONY: all clean fclean re
