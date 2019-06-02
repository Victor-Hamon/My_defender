/*
** EPITECH PROJECT, 2018
** Task03
** File description:
** function that reverses a string
*/
#include <stdlib.h>
int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i;
    int tablength = my_strlen(str) - 1;
    char *stock = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (i = 0; str[i] != '\0'; i++)
        stock[i] = str[tablength - i];
    for (i = 0; str[i] != '\0'; i++)
        str[i] = stock[i];
    return(str);
}
