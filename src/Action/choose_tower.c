/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** fuctions that allows the player to choose a turret to build
*/
#include <math.h>
#include "proto.h"
#include "macro.h"

void dispay_turret_panel(g_t *g_t)
{
    sfVector2f pos_mousef;

    g_t->vec_t->pos_mouse = sfMouse_getPositionRenderWindow(g_t->w_t->game);
    pos_mousef.x = g_t->vec_t->pos_mouse.x - 0.0f;
    pos_mousef.y = g_t->vec_t->pos_mouse.y - 0.0f;
    sfSprite_setPosition(g_t->sp_t->turret_panel, g_t->vec_t->pos_t_panel);
    if (pos_mousef.x >= 1775) {
        if (g_t->vec_t->pos_t_panel.x > 1775)
            g_t->vec_t->pos_t_panel.x -= 10;
    } else if (pos_mousef.x <= 1775 && g_t->vec_t->pos_t_panel.x < 1890)
        g_t->vec_t->pos_t_panel.x += 5;
    sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->turret_panel, NULL);
    select_turret(g_t, pos_mousef);
}

void select_turret(g_t *g_t, sfVector2f pos_mousef)
{
    drag(g_t, pos_mousef);
    drop(g_t, pos_mousef);
    choose_tower(g_t, pos_mousef);
}

bool check_if_posable(int rankx, int ranky, g_t *g_t)
{
    bool check = true;

    if (rankx >= 65 || ranky >= 35)
        return (false);
    (g_t->arr_t->layer[ranky][rankx] <= '1') ? check = false : 0;
    (g_t->arr_t->layer[ranky + 1][rankx] <= '1') ? check = false : 0;
    (g_t->arr_t->layer[ranky + 1][rankx + 1] <= '1') ? check = false : 0;
    (g_t->arr_t->layer[ranky][rankx + 1] <= '1') ? check = false : 0;
    (g_t->arr_t->map[ranky][rankx] != '0') ? check = false : 0;
    (g_t->arr_t->map[ranky + 1][rankx + 1] != '0') ? check = false : 0;
    (g_t->arr_t->map[ranky + 1][rankx] != '0') ? check = false : 0;
    (g_t->arr_t->map[ranky][rankx + 1] != '0') ? check = false : 0;
    return (check);
}
