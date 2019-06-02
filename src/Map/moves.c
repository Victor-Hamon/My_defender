/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include "proto.h"
#include "macro.h"

t_move **init_move(g_t *g_t)
{
    t_move **move = malloc(sizeof(t_move *) * g_t->nb_mob);
    for (int i = 0; i < g_t->nb_mob; i++) {
        move[i] = malloc(sizeof(t_move));
        move[i]->up = 0;
        move[i]->down = 0;
        move[i]->right = 0;
        move[i]->left = 0;
    }
    return (move);
}

void up_move(t_move *move)
{
    move->up = 0;
    move->down = 1;
    move->right = 0;
    move->left = 0;
}

void down_move(t_move *move)
{
    move->up = 1;
    move->down = 0;
    move->right = 0;
    move->left = 0;
}

void right_move(t_move *move)
{
    move->up = 0;
    move->down = 0;
    move->right = 0;
    move->left = 1;
}

void left_move(t_move *move)
{
    move->up = 0;
    move->down = 0;
    move->right = 1;
    move->left = 0;
}