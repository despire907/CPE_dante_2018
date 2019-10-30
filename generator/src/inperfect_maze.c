/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include "generator.h"

void break_down(char **map, int x, int y)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp = (x * y) / 2;

    while (i < tmp) {
        j = rand() % y;
        k = rand() % x;
        if (map[j][k] == '1')
            map[j][k] = '0';
        i++;
    }
}

void inperfect_maze(int x, int y)
{
    char **map;
    dante_t dan;

    init_dan(&dan, y, x);
    if ((map = mem_alloc_2d_array(x, y)) == NULL)
        return ;
    map = load_my_map(map, x, y);
    perfect_maze_algo(&dan, map);
    break_down(map, x, y);
    chang_map(map, x, y);
}