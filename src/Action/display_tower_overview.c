/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include <math.h>
#include "proto.h"
#include "macro.h"

void display_range(g_t *g_t, sfVector2f pos_mousef)
{
    sfVector2f origin_circle;
    sfCircleShape *range = sfCircleShape_create();

    origin_circle.x = 200;
    origin_circle.y = 200;
    sfCircleShape_setOrigin(range, origin_circle);
    sfCircleShape_setPosition(range, pos_mousef);
    sfCircleShape_setRadius(range, 200);
    sfCircleShape_setFillColor(range, sfTransparent);
    sfCircleShape_setOutlineThickness(range, 4);
    sfCircleShape_setOutlineColor(range, sfGreen);
    sfRenderWindow_drawCircleShape(g_t->w_t->game, range, NULL);
}

void display_overview(g_t *g_t, sfVector2f pos_mousef)
{
    display_range(g_t, pos_mousef);
    sfSprite_setTextureRect(g_t->tmp_t->tmp_sp, g_t->tmp_t->tmp_r);
    sfSprite_setPosition(g_t->tmp_t->tmp_sp, pos_mousef);
    sfRenderWindow_drawSprite(g_t->w_t->game, g_t->tmp_t->tmp_sp, NULL);
    pos_mousef.x -= 30;
    pos_mousef.y -= 40;
    sfSprite_setTextureRect(g_t->sp_t->highl, g_t->sp_t->h_rect);
    sfSprite_setPosition(g_t->sp_t->highl, pos_mousef);
    sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->highl, NULL);
}

void drag(g_t *g_t, sfVector2f pos_mousef)
{
    int rankx = 0;
    int ranky = 0;

    if (g_t->release == 1) {
        rankx = pos_mousef.x / 30;
        ranky = pos_mousef.y / 30;
        if (check_if_posable(rankx, ranky, g_t) && g_t->game_stat->money
            >= 500)
            g_t->sp_t->h_rect.left = 65;
        else
            g_t->sp_t->h_rect.left = 0;
        sfSprite_setOrigin(g_t->tmp_t->tmp_sp, g_t->tmp_t->origi);
        display_overview(g_t, pos_mousef);
    }
}

void recreate_tabs(g_t *g_t, sfVector2f pos_mousef, int rankx, int ranky)
{
    if (check_if_posable(rankx, ranky, g_t) && g_t->game_stat->money
        >= 500) {
        g_t->game_stat->money -= 500;
        g_t->nb_tur++;
        g_t->turrets->turs = my_realloc_sp_turrets(g_t);
        g_t->turrets->c_t = my_realloc_vect_turrets(g_t);
        g_t->turrets->rect_tur = my_realloc_rect_turrets(g_t);
        g_t->turrets->type = my_realloc_type(g_t);
        g_t->turrets->type[g_t->nb_tur - 1] = g_t->tmp_t->type;
        set_new_turret_sprite(g_t, g_t->tmp_t->origi);
        g_t->turrets->c_t[g_t->nb_tur - 1] = pos_mousef;
        set_new_turret_rec(g_t);
        g_t->arr_t->layer[ranky][rankx] = 0;
    }
}

void drop(g_t *g_t, sfVector2f pos_mousef)
{
    int rankx = 0;
    int ranky = 0;

    if (!is_click_true() && g_t->release == 1) {
        g_t->release = 0;
        rankx = pos_mousef.x / 30.0f;
        ranky = pos_mousef.y / 30.0f;
        recreate_tabs(g_t, pos_mousef, rankx, ranky);
    }
}