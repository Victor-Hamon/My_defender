/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include <math.h>
#include "proto.h"
#include "macro.h"

float get_angle(sfVector2f pos1, sfVector2f pos2)
{
    int xa = pos1.x;
    int xb = pos2.x;
    int ya = pos1.y;
    int yb = pos2.y;
    float angle;

    if (yb <= ya)
        angle = 270 + 180 + (180 - (57.2958f * acos((xb - xa) /
            (sqrt(pow((xb - xa), 2) + pow((yb - ya), 2))))));
    else
        angle = 270 + 57.2958f * acos((xb - xa) /
            (sqrt(pow((xb - xa), 2) + pow((yb - ya), 2))));
    return (angle);
}

int is_in_range(sfVector2f p_mob, sfVector2f pos_turr)
{
    if (sqrt(pow((p_mob.x - pos_turr.x), 2) + (pos_turr.y - p_mob.y)) < 200)
        return (1);
    return (0);
}

void change_turrets_rotations(g_t *g_t)
{
    for (int i = 0; i < g_t->nb_tur; i++) {
        for (int j = 0; j < g_t->nb_mob; j++) {
            while (g_t->mobs[j] == NULL && j < g_t->nb_mob)
                j++;
            if (is_in_range(g_t->coord_tabf[j], g_t->turrets->c_t[i]) && g_t->hp[j] > 0) {
                do_all_animations(g_t, i);
                sfSprite_setRotation(g_t->turrets->turs[i],
                get_angle(g_t->turrets->c_t[i], g_t->coord_tabf[j]));
                g_t->hp[j] -=  g_t->turrets->type[i];
                (g_t->hp[j] <= 0) ? g_t->mobs[j] = NULL : 0;
                g_t->game_stat->money += 50;
            }
            create_new_wave(g_t);
        }
    }
}
