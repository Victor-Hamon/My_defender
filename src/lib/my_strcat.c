/*
** EPITECH PROJECT, 2018
** Task02
** File description:
** Function that concatenate two strings
*/
char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;

    for(i = 0; dest[i] != '\0'; ++i);
    for(j = 0; src[j] != '\0'; ++j, ++i) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return (dest);
}
