/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** header for get_next_line
*/

#ifndef GET_NEXT_LINEH
#define GET_NEXT_LINEH

void my_putchar(char c);
void my_putstr(char *str);
char *get_next_line(const int fd);
static char *my_strncpy(char *dest, char *src, int n);
static char *add_to_line(char *line, int treat, char *buff, int *start);

#define MEM_SIZE 4096

#endif