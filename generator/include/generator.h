/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct dante_s{
    int nord;
    int sud;
    int hauteur;
    int largeur;
}dante_t;

int main(int ac, char **av);
int check_enter(int ac, char **av);
int check_enter_bis(char *str, char *ptr);
void display_map(char **map, int x, int y);
void chang_map(char **map, int x, int y);
void move_nord_and_sud(char **map, int i, int j, dante_t *dan);
void check_wall(char **map, int i, int j, dante_t *dan);
void check_second_wall(char **map, int i, int j, int tmp);
void perfect_maze_algo(dante_t *dan, char **map);
void perfect_maze(int x, int y);
void init_dan(dante_t *dan, int hauteur, int largeur);
char **load_my_map(char **map, int x, int y);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void inperfect_maze(int x, int y);
void break_down(char **map, int x, int y);

#endif //GENERATOR_H
