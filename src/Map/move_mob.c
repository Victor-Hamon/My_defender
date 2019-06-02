/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** functions that moves the mobs
*/
#include "proto.h"
#include "macro.h"

int check_the_wave(g_t *g_t) {
    int i = 0;
    while (g_t->mobs[i] == NULL && i < g_t->nb_mob)
        i++;
    if (i == g_t->nb_mob)
        return (1);
    else
        return (0);
}

void create_new_wave(g_t *g_t)
{
    if (check_the_wave(g_t) == 1) {
        g_t->nb_mob += 2;
        free(g_t->mobs);
        g_t->mobs = init_mobs(g_t);
        free(g_t->coord_tabf);
        g_t->coord_tabf = init_coord_tabf(g_t);
        free(g_t->move);
        g_t->move = init_move(g_t);
        free(g_t->hp);
        g_t->hp = init_mobs_hp(g_t);
    }
}

void move(g_t *g_t)
{
    sfVector2f origin;
    int out_of_range = 0;

    origin.x = 0;
    origin.y = 30;
    for (int i = 0; i < g_t->nb_mob; i++) {
        out_of_range = 0;
        while (g_t->mobs[i] == NULL && i < g_t->nb_mob)
            i++;
        sfSprite_setOrigin(g_t->mobs[i], origin);
        sfSprite_setPosition(g_t->mobs[i], g_t->coord_tabf[i]);
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->mobs[i], NULL);
        if (g_t->coord_tabf[i].x <= 0.0f) {
            out_of_range = 1;
            g_t->coord_tabf[i].x += 10.0f;
        }
        manage_wave_1(g_t, i, out_of_range);
        manage_wave_2(g_t, i, out_of_range);
        create_new_wave(g_t);
    }
}
