/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include "proto.h"
#include "macro.h"

void display_tiles(g_t *g_t)
{
    for (int y2 = 0; y2 < 36; ++y2) {
        for (int x2 = 0; x2 < 64; ++x2) {
            g_t->vec_t->pos_tile.x = x2 * 30;
            g_t->vec_t->pos_tile.y = y2 * 30;
            g_t->sp_t->rect.left = find_rank(g_t->arr_t->map[y2][x2],
                g_t->arr_t->char_list) * 30;
            while (g_t->sp_t->rect.left >= 300) {
                g_t->sp_t->rect.top += 30;
                g_t->sp_t->rect.left -= 300;
            }
            sfSprite_setTextureRect(g_t->sp_t->sp_s, g_t->sp_t->rect);
            sfSprite_setPosition(g_t->sp_t->sp_s, g_t->vec_t->pos_tile);
            sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->sp_s, NULL);
            g_t->sp_t->rect.top = 0;
        }
    }
}

void display_turrets(g_t *g_t)
{
    for (int i = 0; i < g_t->nb_tur; ++i) {
        sfSprite_setTextureRect(g_t->turrets->turs[i],
            g_t->turrets->rect_tur[i]);
        sfSprite_setPosition(g_t->turrets->turs[i],g_t->turrets->c_t[i]);
        sfRenderWindow_drawSprite(g_t->w_t->game, g_t->turrets->turs[i], NULL);
    }
}

void display_stats(g_t *g_t)
{
    sfVector2f pos;
    sfVector2f scale;

    pos.x = 480;
    pos.y = 20;
    scale.x = 1.5f;
    scale.y = 1.5f;
    sfSprite_setTextureRect(g_t->sp_t->hp, g_t->sp_t->hp_rect);
    sfSprite_setScale(g_t->sp_t->hp, scale);
    sfSprite_setScale(g_t->sp_t->bar, scale);
    sfSprite_setPosition(g_t->sp_t->hp, pos);
    sfSprite_setPosition(g_t->sp_t->bar, pos);
    sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->bar, NULL);
    sfRenderWindow_drawSprite(g_t->w_t->game, g_t->sp_t->hp, NULL);
    g_t->sp_t->hp_rect.width = g_t->game_stat->hp * 659/20;
}

void create_mob(g_t *g_t)
{
    move(g_t);
}