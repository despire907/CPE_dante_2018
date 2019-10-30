/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** tools function
*/

#include <stdlib.h>
#include <stddef.h>
#include "solver.h"

int my_strlen(char *str)
{
    int count = 0;

    if (str == NULL)
        return 0;
    while (str[count] != '\0') {
        count = count + 1;
    }
    return count;
}

char *my_strdup(char *src)
{
    int count = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[count] != '\0') {
        dest[count] = src[count];
        count = count + 1;
    }
    dest[count] = '\0';
    return (dest);
}

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i = i + 1;
    }
}

int line_counter(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i = i + 1;
    }
    return i;
}

position_t *position_create(char **maze)
{
    position_t *new = malloc(sizeof(position_t));

    if (new == NULL)
        exit(84);
    new->maze = maze;
    new->x = 0;
    new->y = 0;
    new->end = 0;
    new->save_x = 0;
    new->save_y = 0;
    return new;
}
