/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include "proto.h"
#include "macro.h"

void move_down_and_up(g_t *g_t, int i, int out_of_range)
{
    if ((int) ((g_t->coord_tabf[i].y) / 30) + 1 < 36 && g_t->move[i]->down == 0
        &&  out_of_range == 0 && g_t->arr_t->map[((int) ((g_t->coord_tabf[i].y)
        / 30)) + 1][(int) (g_t->coord_tabf[i].x / 30)] != '0') {
        g_t->coord_tabf[i].y  += 10;
        return;
    }
    if ((int) ((g_t->coord_tabf[i].y) / 30) - 1 > 0 && g_t->move[i]->up == 0
        &&  out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y)
        / 30) - 1][(int) (g_t->coord_tabf[i].x / 30)] != '0') {
        g_t->coord_tabf[i].y-= 10;
        return;
    }
}

void manage_wave_1(g_t *g_t, int i, int out_of_range)
{
    move_down_and_up(g_t, i, out_of_range);
    if ((int) (g_t->coord_tabf[i].x / 30) + 1 < 64 && g_t->move[i]->right == 0
        && out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y)
        / 30)][(int) (g_t->coord_tabf[i].x / 30) + 1] != '0') {
        g_t->coord_tabf[i].x += 10;
        return;
    }
    if ((int) (g_t->coord_tabf[i].x / 30) - 1 > 0 && g_t->move[i]->left == 0 &&
        out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y) /
        30)][(int) (g_t->coord_tabf[i].x / 30) - 1] != '0') {
        g_t->coord_tabf[i].x -= 10;
        return;
    }
}

void down_and_up(g_t *g_t, int i, int out_of_range)
{
    if (out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y)
        / 30)][(int) (g_t->coord_tabf[i].x / 30)] == 'D') {
        down_move(g_t->move[i]);
        g_t->coord_tabf[i].y  += 30;
    }
    if (out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y)
        / 30)][(int) (g_t->coord_tabf[i].x / 30)] == 'U') {
        up_move(g_t->move[i]);
        g_t->coord_tabf[i].y-= 30;
    }
}

void right_and_left(g_t *g_t, int i, int out_of_range)
{
    if (out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y)
        / 30)][(int) (g_t->coord_tabf[i].x / 30)] == 'R') {
        right_move(g_t->move[i]);
        g_t->coord_tabf[i].x += 30;
    }
    if (out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y)
        / 30)][(int) (g_t->coord_tabf[i].x / 30)] == 'L') {
        left_move(g_t->move[i]);
        g_t->coord_tabf[i].x -= 30;
    }
}

void manage_wave_2(g_t *g_t, int i, int out_of_range)
{
    down_and_up(g_t, i, out_of_range);
    right_and_left(g_t, i, out_of_range);
    if (out_of_range == 0 && g_t->arr_t->map[(int) ((g_t->coord_tabf[i].y)
        / 30)][(int) (g_t->coord_tabf[i].x / 30)] == '4') {
        g_t->game_stat->hp--;
        g_t->mobs[i] = NULL;
    }
}