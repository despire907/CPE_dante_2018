/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include "generator.h"

void move_nord_and_sud(char **map, int i, int j, dante_t *dan)
{
    if (i - 1 >= 0 && map[i - 1][j] == '1')
        dan->nord = 1;
    if (j - 1 >= 0 && map[i][j - 1] == '1')
        dan->sud = 1;
}

void check_wall(char **map, int i, int j, dante_t *dan)
{
    if (i - 1 >= 0 && dan->nord == 1 && dan->sud == 0)
        map[i - 1][j] = '0';
    if (j - 1 >= 0 && dan->nord == 0 && dan->sud == 1)
        map[i][j - 1] = '0';
}

void check_second_wall(char **map, int i, int j, int tmp)
{
    tmp = rand() % 2;
    if (j - 1 >= 0 && tmp == 0)
        map[i][j - 1] = '0';
    else if (i - 1 >= 0 && tmp == 1)
        map[i - 1][j] = '0';
}

void perfect_maze_algo(dante_t *dan, char **map)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (i < dan->hauteur) {
        j = 0;
        dan->nord = 0;
        dan->sud = 0;
        while  (j < dan->largeur) {
            if (i == 0)
                map[0][0] = '0';
            move_nord_and_sud(map, i, j, dan);
            check_wall(map, i, j, dan);
            if (dan->nord == 1 && dan->sud == 1)
                check_second_wall(map, i, j, tmp);
            j = j + 2;
        }
        i = i + 2;
    }
}

void perfect_maze(int x, int y)
{
    dante_t dan;
    char **map;

    init_dan(&dan, y, x);
    if ((map = mem_alloc_2d_array(x, y)) == NULL)
        return ;
    map = load_my_map(map, x, y);
    perfect_maze_algo(&dan, map);
    chang_map(map, x, y);
}