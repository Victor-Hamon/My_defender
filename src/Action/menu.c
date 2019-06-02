/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** menu for my_defender
*/

#include "proto.h"
#include "macro.h"

int check_pos_mouse(g_t *g_t, sfVector2i pos_mouse)
{
    if (pos_mouse.y <= 752 && pos_mouse.y >= 331 && pos_mouse.x >= 1334 &&
        pos_mouse.x <= 1471) {
        g_t->sp_t->vol_rect.top = (pos_mouse.y - 331);
        sfMusic_setVolume(g_t->audio_t->ambiance, (423 -
            g_t->sp_t->vol_rect.top) / 4.21);
    }
    if (pos_mouse.y <= 683 && pos_mouse.y >= 530 && pos_mouse.x >= 250
        && pos_mouse.x <= 605)
        return (1);
    else if (pos_mouse.y <= 683 && pos_mouse.y >= 530 && pos_mouse.x >= 250
        && pos_mouse.x <= 605)
        return (1);
    return (0);
}

void choose_options(g_t *g_t, int i)
{
    int status = 1;
    sfVector2i pos_mouse;
    sfVector2f pos_vol;

    pos_vol.x = 1334;
    pos_vol.y = 331;
    while (status == 1) {
        pos_mouse = sfMouse_getPositionRenderWindow(g_t->w_t->game);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (check_pos_mouse(g_t, pos_mouse) == 1)
                return;
        pos_vol.y = 331 + g_t->sp_t->vol_rect.top;
        sfSprite_setPosition(g_t->sp_t->volume, pos_vol);
        sfSprite_setTextureRect(g_t->sp_t->volume, g_t->sp_t->vol_rect);
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->o_menu, NULL);
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->volume, NULL);
        sfRenderWindow_display(g_t->w_t->game);
        sfRenderWindow_clear(g_t->w_t->game, sfBlack);
        }
    }
}

void display_highlights(g_t *g_t, sfVector2i pos_mouse)
{
    if (pos_mouse.y <= 730 && pos_mouse.y >= 650 && pos_mouse.x >= 865 &&
        pos_mouse.x <= 1155) {
        sfSprite_setPosition(g_t->sp_t->quit, g_t->vec_t->pos_quit);
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->quit, NULL);
    }
    if (pos_mouse.y >= 25 && pos_mouse.y <= 325 && pos_mouse.x >= 1665 &&
        pos_mouse.x <= 1810) {
        sfSprite_setPosition(g_t->sp_t->opt, g_t->vec_t->pos_opt);
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->opt, NULL);
    }
    if (pos_mouse.y >= 595 && pos_mouse.y <= 703 && pos_mouse.x >= 1485 &&
        pos_mouse.x <= 1715) {
        sfSprite_setPosition(g_t->sp_t->play, g_t->vec_t->pos_play);
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->play, NULL);
    }
}

int which_choice(g_t *g_t, sfVector2i pos_mouse)
{
    if (pos_mouse.y <= 730 && pos_mouse.y >= 650 && pos_mouse.x >= 865 &&
        pos_mouse.x <= 1155) {
        sfMusic_play(g_t->audio_t->init);
        return (2);
    }
    if (pos_mouse.y >= 25 && pos_mouse.y <= 325 && pos_mouse.x >= 1665 &&
        pos_mouse.x <= 1810) {
        sfMusic_play(g_t->audio_t->init);
        choose_options(g_t, 1);
        return (0);
    }
    if (pos_mouse.y >= 595 && pos_mouse.y <= 703 && pos_mouse.x >= 1485 &&
        pos_mouse.x <= 1715) {
        sfMusic_play(g_t->audio_t->init);
        return (1);
    }
    return (0);
}

int display_menu(g_t *g_t)
{
    int choice = 0;
    sfVector2i pos_mouse;

    sfMusic_play(g_t->audio_t->ambiance);
    while (choice == 0) {
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->start_m, NULL);
        pos_mouse = sfMouse_getPositionRenderWindow(g_t->w_t->game);
        display_highlights(g_t, pos_mouse);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            choice = which_choice(g_t, pos_mouse);
        }
        sfRenderWindow_display(g_t->w_t->game);
        sfRenderWindow_clear(g_t->w_t->game, sfBlack);
    }
    if (choice == 2)
        return (2);
    return (1);
}