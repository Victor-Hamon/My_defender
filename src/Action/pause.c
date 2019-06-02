/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** pause for defender
*/

#include "proto.h"
#include "macro.h"

bool escape(void)
{
    int escape = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && escape != 1)
        escape = 1;
    while (escape) {
        if (!sfKeyboard_isKeyPressed(sfKeyEscape)) {
            return (true);
        }
    }
    return (false);
}

int select_in_pause(g_t *g_t, sfVector2i pos_mouse)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pos_mouse = sfMouse_getPositionRenderWindow(g_t->w_t->game);
        if (pos_mouse.y <= 510 && pos_mouse.y >= 436 && pos_mouse.x >= 865 &&
            pos_mouse.x <= 1180) {
            sfMusic_play(g_t->audio_t->init);
            choose_options(g_t, 2);
            return (0);
        }
    }
        if (pos_mouse.y <= 660 && pos_mouse.y >= 575 && pos_mouse.x >= 1025 &&
            pos_mouse.x <= 1215) {
            sfMusic_play(g_t->audio_t->init);
            return (1);
    }
        if (pos_mouse.y <= 660 && pos_mouse.y >= 575 && pos_mouse.x >= 788 &&
            pos_mouse.x <= 974) {
            sfMusic_play(g_t->audio_t->init);
            return (0);
    }
    return (3);
}

int check_pause(g_t *g_t)
{
    sfVector2f pos;
    sfVector2i pos_mouse;

    pos.x = 400;
    pos.y = 300;
    if (escape()) {
        while (!escape()) {
            sfSprite_setPosition(g_t->sp_t->pause, pos);
            sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->pause, NULL);
            sfRenderWindow_display(g_t->w_t->game);
            if (select_in_pause(g_t, pos_mouse) != 3)
                return (select_in_pause(g_t, pos_mouse));
        }
    }
    return (0);
}