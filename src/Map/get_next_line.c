/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** get next line
*/
#include "../../include/proto.h"
#include "../../include/get_next_line.h"

void my_putchar(char c)
{
    write(1,&c,1);
}

void my_putstr(char *str)
{
    while(*str!=0) {
        my_putchar(*str);
        str++;
    }
}

static char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n < i)
        dest[i] = '\0';
    return (dest);
}

static char *add_to_line(char *line, int n, char *buff, int *s)
{
    char *currlen;
    int flen;

    if (line != 0)
        flen = my_strlen(line);
    else
        flen = 0;
    currlen = malloc((flen + n + 1) * sizeof(*currlen));
    if (line != 0)
        my_strncpy(currlen, line, flen);
    else
        my_strncpy(currlen, "", flen);
    currlen[flen + n] = 0;
    my_strncpy(currlen + flen, buff + *s, n);
    if (line)
        free(line);
    *s = *s + (n + 1);
    return (currlen);
}

char *get_next_line(const int fd)
{
    static char buff[MEM_SIZE];
    static int nbchartoread = 0;
    static int s;
    int n = 0;
    char *line = 0;

    while (1) {
        if (nbchartoread <= s) {
            s = 0;
            if (!(nbchartoread = read(fd, buff, MEM_SIZE)))
                return (line);
            if (nbchartoread == - 1)
                return (NULL);
            n = 0;
        }
        if (buff[s + n] == '\n')
            return (line = add_to_line(line, n, buff, &s));
        if (s + n == nbchartoread - 1)
            line = add_to_line(line, n + 1, buff, &s);
        n = n + 1;
    }
}
