/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include "generator.h"

void display_map(char **map, int x, int y)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (i < y) {
        j = 0;
        while (j < x) {
            if (i == y - 1 && j == x - 1 && map[i][j] == '1') {
                printf("*");
                tmp = 1;
            } if (map[i][j] == '0')
                printf("*");
            if (map[i][j] == '1' && tmp != 1)
                printf("X");
            j++;
        }
        i++;
        if (i < y)
            printf("\n");
    }
}

void chang_map(char **map, int x, int y)
{
    int i = 0;
    int j = 0;

    while (i < y - 1)
        i++;
    while (j < x - 1)
        j++;
    if (map[i][j - 1] == '1' && map[i - 1][j] == '1')
        map[i][j - 1] = '0';
    display_map(map, x, y);
}