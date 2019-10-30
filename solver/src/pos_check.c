/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** macros
*/

#include "solver.h"

int pos_found(position_t *pos)
{
    int check = 0;

    if (right_check(pos) == 1)
        check = check + 1;
    if (left_check(pos) == 1)
        check = check + 1;
    if (top_check(pos) == 1)
        check = check + 1 ;
    if (down_check(pos) == 1)
        check = check + 1;
    if (check == 0)
        return no_way;
    if (check == 1)
        return one_way;
    else if (check >= 2)
        return cross;
    else {
        return 0;
    }
}

int right_check(position_t *pos)
{
    if ((pos->x + 1) <= (my_strlen(pos->maze[0]) - 1)) {
        if (pos->maze[pos->y][pos->x + 1] == '*') {
            return 1;
        }
        if (pos->maze[pos->y][pos->x + 1] == 'o')
            return 2;
    }
    return 0;
}

int left_check(position_t *pos)
{
    if ((pos->x - 1) >= 0) {
        if (pos->maze[pos->y][pos->x - 1] == '*') {
            return 1;
        }
        if (pos->maze[pos->y][pos->x - 1] == 'o')
            return 2;
    }
    return 0;
}

int top_check(position_t *pos)
{
    if ((pos->y - 1) >= 0) {
        if (pos->maze[pos->y - 1][pos->x] == '*') {
            return 1;
        }
        if (pos->maze[pos->y - 1][pos->x] == 'o')
            return 2;
    }
    return 0;
}

int down_check(position_t *pos)
{
    if ((pos->y + 1) <= (line_counter(pos->maze) - 1)) {
        if (pos->maze[pos->y + 1][pos->x] == '*') {
            return 1;
        }
        if (pos->maze[pos->y + 1][pos->x] == 'o')
            return 2;
    }
    return 0;
}