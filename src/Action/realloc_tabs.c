/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include <math.h>
#include "proto.h"
#include "macro.h"

void set_new_turret_sprite(g_t *g_t, sfVector2f origin)
{
    g_t->turrets->turs[g_t->nb_tur - 1] = sfSprite_create();
    sfSprite_setTexture(g_t->turrets->turs[g_t->nb_tur - 1], g_t->tmp_t->tmp_txt, sfFalse);
    sfSprite_setOrigin(g_t->turrets->turs[g_t->nb_tur - 1], origin);
}

void set_new_turret_vect(g_t *g_t, sfVector2f pos_mousef)
{
    g_t->turrets->c_t[g_t->nb_tur - 1].x = pos_mousef.x;
    g_t->turrets->c_t[g_t->nb_tur - 1].y = pos_mousef.y;
}

sfSprite **my_realloc_sp_turrets(g_t *g_t)
{
    sfSprite **tmp_tur;

    tmp_tur = malloc(sizeof(sfSprite *) * (g_t->nb_tur + 1));
    if (tmp_tur == NULL)
        return (NULL);
    for (int i = 0; i < g_t->nb_tur - 1; i++) {
        tmp_tur[i] = g_t->turrets->turs[i];
    }
    return (tmp_tur);
}

sfVector2f *my_realloc_vect_turrets(g_t *g_t)
{
    sfVector2f *tmp_tur;

    tmp_tur = malloc(sizeof(sfVector2f) * (g_t->nb_tur + 1));
    if (tmp_tur == NULL)
        return (NULL);
    for (int i = 0; i < g_t->nb_tur - 1; i++)
        tmp_tur[i] = g_t->turrets->c_t[i];
    return (tmp_tur);
}

sfIntRect *my_realloc_rect_turrets(g_t *g_t)
{
    sfIntRect *tmp_tur;

    tmp_tur = malloc(sizeof(sfIntRect) * (g_t->nb_tur + 1));
    if (tmp_tur == NULL)
        return (NULL);
    for (int i = 0; i < g_t->nb_tur - 1; i++) {
        tmp_tur[i] = g_t->turrets->rect_tur[i];
    }
    return (tmp_tur);
}