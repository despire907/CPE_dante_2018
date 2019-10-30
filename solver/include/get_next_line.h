/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** macros
*/

char *get_next_line(int fd);
int my_str_c_len(char *str, char c);
char *my_str_c_dup(char *src, char *second_src);
char *stock_filler(char *buff, char *stock);
char *read_function(int fd, char *buff, char *stock, char *final);

#ifndef READ_SIZE
#define READ_SIZE 5
#endif
