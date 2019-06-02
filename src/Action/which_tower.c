/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include <math.h>
#include "proto.h"
#include "macro.h"

void choose_tower_2(g_t *g_t, sfVector2f pos_mousef)
{
    if (pos_mousef.y >= 100 && pos_mousef.y <= 410 && g_t->game_stat->money >= 250) {
        sfMusic_play(g_t->audio_t->init);
        g_t->tmp_t->tmp_txt = sfTexture_createFromFile(PIC2, NULL);
        sfSprite_setTexture(g_t->tmp_t->tmp_sp, g_t->tmp_t->tmp_txt, sfFalse);
        g_t->tmp_t->tmp_r.top = 0;
        g_t->tmp_t->tmp_r.left = 80;
        g_t->tmp_t->tmp_r.height = 300;
        g_t->tmp_t->tmp_r.width = 43;
        g_t->tmp_t->origi.x = 21;
        g_t->tmp_t->origi.y = 75;
        g_t->tmp_t->type = 2;
    }
}
void choose_tower_1(g_t *g_t, sfVector2f pos_mousef)
{
    if (pos_mousef.y >= 420 && pos_mousef.y <= 708 && g_t->game_stat->money >= 500) {
        sfMusic_play(g_t->audio_t->init);
        g_t->tmp_t->tmp_txt = sfTexture_createFromFile(PIC16, NULL);
        sfSprite_setTexture(g_t->tmp_t->tmp_sp, g_t->tmp_t->tmp_txt, sfFalse);
        g_t->tmp_t->tmp_r.top = 0;
        g_t->tmp_t->tmp_r.left = 70;
        g_t->tmp_t->tmp_r.height = 150;
        g_t->tmp_t->tmp_r.width = 57;
        g_t->tmp_t->origi.x = 28;
        g_t->tmp_t->origi.y = 75;
        g_t->tmp_t->type = 1;
    }
}


void choose_tower(g_t *g_t, sfVector2f pos_mousef)
{
    if (is_click_true() && pos_mousef.x >= 1775) {
        g_t->release = 1;
        choose_tower_1(g_t, pos_mousef);
        choose_tower_2(g_t, pos_mousef);
        if (pos_mousef.y >= 725 && pos_mousef.y <= 950  && g_t->game_stat->money >= 750) {
            sfMusic_play(g_t->audio_t->init);
            g_t->tmp_t->tmp_txt = sfTexture_createFromFile(PIC17, NULL);
            sfSprite_setTexture(g_t->tmp_t->tmp_sp, g_t->tmp_t->tmp_txt, sfFalse);
            g_t->tmp_t->tmp_r.top = 0;
            g_t->tmp_t->tmp_r.left = 64;
            g_t->tmp_t->tmp_r.height = 150;
            g_t->tmp_t->tmp_r.width = 75;
            g_t->tmp_t->origi.x = 37;
            g_t->tmp_t->origi.y = 35;
            g_t->tmp_t->type = 3;
        }
    }
}