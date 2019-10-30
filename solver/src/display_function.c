/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** display function
*/

#include <stddef.h>
#include <unistd.h>
#include "solver.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void tab_display(char **maze)
{
    int y = 0;

    while (maze[y] != NULL) {
        my_putstr(maze[y]);
        my_putchar('\n');
        y = y + 1;
    }
}