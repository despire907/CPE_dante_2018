/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "solver.h"

void way_finder(position_t *pos)
{
    int way = pos_found(pos);

    if (way == one_way)
        move_on(pos);
    if (way == no_way)
        back_in_time(pos);
    if (way == cross)
        move_on(pos);
    if (pos->x == (my_strlen(pos->maze[0]) - 1)
    && pos->y == (line_counter(pos->maze) - 1))
        pos->end = 1;
}

int solver(char **maze)
{
    position_t *pos = position_create(maze);

    pos->maze[pos->y][pos->x] = 'o';
    while (pos->end != 1) {
        way_finder(pos);
    }
    free(pos);
    return 0;
}

int maze_check(char **maze)
{
    int y = 0;
    int x = 0;

    while (maze[y] != NULL) {
        x = 0;
        while (maze[y][x] != '\0') {
            if (maze[y][x] != '*' && maze[y][x] != 'X')
                return 84;
            x = x + 1;
        }
        y = y + 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    char **maze;

    if (ac != 2)
        return 84;
    maze = open_maze(av[1]);
    if (maze == NULL)
        return 84;
    if (maze_check(maze) == 84)
        return 84;
    if (solver(maze) == 84)
        return 84;
    tab_display(maze);
    free_tab(maze);
    return 0;
}