/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** create index for mydefender
*/
#include "macro.h"
#include "proto.h"
#include "struct.h"

char **create_tab(void)
{
    char **tab = malloc(NB_SPRITE * sizeof *tab);
    if (tab != NULL)  {
       size_t i;
       for (i = 0; i < 2; i++) {
          tab[i] = NULL;
       }
    }
    return tab;
}

char *fill_with_char(void)
{
    char *tab = malloc(sizeof(char) * NB_SPRITE);
    for (int i = 0; i < NB_SPRITE; ++i) {
        tab[i] = sprites_char[i];
    }
    return (tab);
}

int create_map_tab(int fd, char **map)
{
    int line_nb = 0;

    while(line_nb < 36) {
        map[line_nb] = get_next_line(fd);
        line_nb++;
    }
    close(fd);
    return 0;
}

int find_rank(char c, char *index)
{
    for (int i = 0; i < NB_SPRITE; ++i) {
        if (c == index[i]) {
            return (i);
        }
    }
    return (0);
}