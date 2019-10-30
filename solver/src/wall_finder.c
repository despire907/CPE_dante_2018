/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** wall finder function
*/

#include "solver.h"

int move_on(position_t *pos)
{
    if (down_check(pos) == 1) {
        pos->y = pos->y + 1;
        pos->maze[pos->y][pos->x] = 'o';
        return 0;
    }
    if (right_check(pos) == 1) {
        pos->x = pos->x + 1;
        pos->maze[pos->y][pos->x] = 'o';
        return 0;
    }
    if (left_check(pos) == 1) {
        pos->x = pos->x - 1;
        pos->maze[pos->y][pos->x] = 'o';
        return 0;
    }
    if (top_check(pos) == 1) {
        pos->y = pos->y - 1;
        pos->maze[pos->y][pos->x] = 'o';
        return 0;
    }
    return 0;
}

void move_back(position_t *pos)
{
    pos->maze[pos->y][pos->x] = '1';
    if (right_check(pos) == 2) {
        pos->x = pos->x + 1;
    }
    if (left_check(pos) == 2) {
        pos->x = pos->x - 1;
    }
    if (top_check(pos) == 2) {
        pos->y = pos->y - 1;
    }
    if (down_check(pos) == 2) {
        pos->y = pos->y + 1;
    }
}

void back_in_time(position_t *pos)
{
    while (pos->x != pos->save_x || pos->y != pos->save_y) {
        if (pos_found(pos) == no_way || pos_found(pos) == one_way) {
            move_back(pos);
        }
    }
}

int sub_finder(position_t *pos, int line, int column)
{
    if (pos->x < (column / 2) && pos->y > (line / 2) && right_check(pos) == 1)
        return right;
    if (pos->x > (column / 2) && pos->y < (line / 2) && down_check(pos) == 1)
        return down;
    if (pos->x < (column / 2) && pos->y < (line / 2) && right_check(pos) == 1)
        return right;
    if (pos->x > (column / 2) && pos->y > (line / 2) && right_check(pos) == 1)
        return right;
    return 0;
}

void direction_finder(position_t *pos)
{
    int line = line_counter(pos->maze);
    int column = my_strlen(pos->maze[0]);
    int check = sub_finder(pos, line, column);

    pos->save_x = pos->x;
    pos->save_y = pos->y;
    if (check == right)
        pos->x = pos->x + 1;
    else if (check == down)
        pos->y = pos->y + 1;
    else {
        if (top_check(pos) == 1)
            pos->y = pos->y - 1;
        else if (left_check(pos) == 1) {
            pos->x = pos->x - 1;
        }
    }
    pos->maze[pos->y][pos->x] = 'o';
}