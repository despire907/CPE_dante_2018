/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include "generator.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **str;
    int max_rows = nb_rows + (nb_rows - 1);
    int max_cols = nb_cols + (nb_cols - 1);
    int i = 0;

    if (nb_rows == 0 || nb_cols == 0)
        return NULL;
    if ((str = malloc(sizeof(char *) * (max_cols + 1))) == NULL)
        return NULL;
    while (i < max_cols){
        if ((str[i] = malloc(sizeof(char) * (max_rows + 1))) == NULL)
            return NULL;
        i++;
    }
    str[i] = NULL;
    return (str);
}

char **load_my_map(char **map, int x, int y)
{
    int i = 0;
    int j = 0;

    while (i < y + (y - 1)){
        j = 0;
        while (j < x + (x - 1)){
            if (j % 2 == 0 && i % 2 == 0)
                map[i][j] = '0';
            else if (j % 2 != 0 && i % 2 == 0)
                map[i][j] = '1';
            else if (i % 2 != 0)
                map[i][j] = '1';
            j++;
        }
        map[i][j] = '\0';
        i++;
    }
    return map;
}

void init_dan(dante_t *dan, int hauteur, int largeur)
{
    dan->nord = 0;
    dan->sud = 0;
    dan->hauteur = hauteur + (hauteur - 1);
    dan->largeur = largeur + (largeur - 1);
}