/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** map reader function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "solver.h"

char **create_maze(char *file, int fd)
{
    char *temp = get_next_line(fd);
    int count = my_strlen(temp);
    char **maze;
    int i = 1;
    struct stat buff;

    stat(file, &buff);
    maze = malloc(sizeof(char *) * ((buff.st_size / count) + 1));
    if (maze == NULL)
        return NULL;
    maze[0] = my_strdup(temp);
    while (temp != NULL) {
        temp = get_next_line(fd);
        if (temp != NULL) {
            maze[i] = my_strdup(temp);
            i = i + 1;
        }
    }
    maze[i] = NULL;
    return maze;
}

char **open_maze(char *file)
{
    char **maze;
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return NULL;
    maze = create_maze(file, fd);
    if (maze == NULL)
        return NULL;
    return maze;
}