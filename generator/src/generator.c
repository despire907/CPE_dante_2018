/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** getnextline
*/

#include "generator.h"

int check_enter_bis(char *str, char *ptr)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' && str[i] > '9')
            return 84;
        i++;
    }
    i = 0;
    while (ptr[i] != '\0') {
        if (ptr[i] < '0' && ptr[i] > '9')
            return 84;
        i++;
    }
    return 0;
}

int check_enter(int ac, char **av)
{
    if (ac == 3 && atoi(av[1]) > 0 && atoi(av[2]) > 0)
        inperfect_maze(atoi(av[1]), atoi(av[2]));
    else if (ac == 4 && !strcmp(av[3], "perfect") && atoi(av[1]) > 0 &&
    atoi(av[2]) > 0)
        perfect_maze(atoi(av[1]), atoi(av[2]));
    else
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    srand(getpid() * time(NULL));
    if (ac == 3 || ac == 4) {
        if (check_enter_bis(av[1], av[2]) == 84)
            return 84;
        else if (check_enter(ac, av) == 84)
            return 84;
    } else
        return 84;
    return 0;
}