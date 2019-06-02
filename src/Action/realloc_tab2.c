/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include <math.h>
#include "proto.h"
#include "macro.h"

void set_new_turret_rec(g_t *g_t)
{
    g_t->turrets->rect_tur[g_t->nb_tur - 1].top = g_t->tmp_t->tmp_r.top;
    g_t->turrets->rect_tur[g_t->nb_tur - 1].left = g_t->tmp_t->tmp_r.left;
    g_t->turrets->rect_tur[g_t->nb_tur - 1].height = g_t->tmp_t->tmp_r.height;
    g_t->turrets->rect_tur[g_t->nb_tur - 1].width = g_t->tmp_t->tmp_r.width;
}

int *my_realloc_type(g_t *g_t)
{
    int *tmp_type;

    tmp_type = malloc(sizeof(int) * (g_t->nb_tur + 1));
    if (tmp_type == NULL)
        return (NULL);
    for (int i = 0; i < g_t->nb_tur - 1; i++) {
        tmp_type[i] = g_t->turrets->type[i];
    }
    return (tmp_type);
}
