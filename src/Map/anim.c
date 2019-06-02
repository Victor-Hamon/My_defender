/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** anim for defender
*/
#include "proto.h"
#include "macro.h"

void do_animations_1(g_t *g_t, int i)
{
    g_t->sp_t->time_t1 = sfClock_getElapsedTime(g_t->sp_t->clock_t1);
    g_t->sp_t->sec_t1 = g_t->sp_t->time_t1.microseconds / 10000.0;
    if (g_t->sp_t->sec_t1 > 1.0 && g_t->turrets->type[i] == 1) {
        if (g_t->turrets->rect_tur[i].left <= 1924)
            g_t->turrets->rect_tur[i].left =
            g_t->turrets->rect_tur[i].left + 200;
        if (g_t->turrets->rect_tur[i].left >= 1924)
            g_t->turrets->rect_tur[i].left = 70;
        sfClock_restart(g_t->sp_t->clock_t1);
    }
}

void do_animations_2(g_t *g_t, int i)
{
    g_t->sp_t->time_t2 = sfClock_getElapsedTime(g_t->sp_t->clock_t2);
    g_t->sp_t->sec_t2 = g_t->sp_t->time_t2.microseconds / 10000.0;
    if (g_t->sp_t->sec_t2 > 1.0 && g_t->turrets->type[i] == 2) {
        if (g_t->turrets->rect_tur[i].left <= 3321)
            g_t->turrets->rect_tur[i].left =
            g_t->turrets->rect_tur[i].left + 200;
        if (g_t->turrets->rect_tur[i].left >= 3321)
            g_t->turrets->rect_tur[i].left = 80;
        sfClock_restart(g_t->sp_t->clock_t2);
    }
}

void do_animations_3(g_t *g_t, int i)
{
    g_t->sp_t->time_t3 = sfClock_getElapsedTime(g_t->sp_t->clock_t3);
    g_t->sp_t->sec_t3 = g_t->sp_t->time_t3.microseconds / 10000.0;
    if (g_t->sp_t->sec_t3 > 1.0 && g_t->turrets->type[i] == 3) {
        if (g_t->turrets->rect_tur[i].left <= 1538)
            g_t->turrets->rect_tur[i].left =
            g_t->turrets->rect_tur[i].left + 200;
        if (g_t->turrets->rect_tur[i].left >= 1538)
            g_t->turrets->rect_tur[i].left = 64;
        sfClock_restart(g_t->sp_t->clock_t3);
    }
}


void do_all_animations(g_t *g_t, int i)
{
    do_animations_1(g_t, i);
    do_animations_2(g_t, i);
    do_animations_3(g_t, i);
}
