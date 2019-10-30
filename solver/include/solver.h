/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** macros
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "struct.h"

enum pos_e {top = 1, right = 2, down = 3, left = 4,
cross = 5, no_way = 6, one_way = 7};

void way_finder(position_t *pos);
int solver(char **maze);
int maze_check(char **maze);
int main(int argc, char **argv);

char *my_strdup(char *src);
int my_strlen(char *str);
void free_tab(char **tab);
int line_counter(char **tab);
position_t *position_create(char **maze);

void my_putchar(char c);
void my_putstr(char *str);
void tab_display(char **maze);

char **create_maze(char *file, int fd);
char **open_maze(char *file);

int pos_found(position_t *pos);
int right_check(position_t *pos);
int left_check(position_t *pos);
int top_check(position_t *pos);
int down_check(position_t *pos);

int move_on(position_t *pos);
void back_in_time(position_t *pos);
void move_back(position_t *pos);
int sub_finder(position_t *pos, int line, int column);
void direction_finder(position_t *pos);

#endif //SOLVER_H