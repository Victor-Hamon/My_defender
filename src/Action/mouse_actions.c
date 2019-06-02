/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** functions that manage the actions of the mouse
*/
#include "proto.h"
#include "macro.h"

bool is_click_true(void)
{
    int click = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && click != 1)
        click = 1;
    while (click) {
        return (true);
    }
    return (false);
}
