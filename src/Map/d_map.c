/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** A map parser for my_defender
*/
#include "proto.h"
#include "macro.h"

void game_turn(g_t *g_t, sfEvent event)
{
    while (sfRenderWindow_isOpen(g_t->w_t->game) && g_t->game_stat->hp > 0) {
        display_tiles(g_t);
        display_turrets(g_t);
        display_stats(g_t);
        create_mob(g_t);
        dispay_turret_panel(g_t);
        change_turrets_rotations(g_t);
        sfRenderWindow_pollEvent(g_t->w_t->game, &event);
        sfRenderWindow_setFramerateLimit(g_t->w_t->game, 30);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(g_t->w_t->game);
        sfRenderWindow_display(g_t->w_t->game);
        if (check_pause(g_t) == 1) {
            sfRenderWindow_close(g_t->w_t->game);
            return;
        }
        sfRenderWindow_clear(g_t->w_t->game, sfBlack);
    }
}

int play_game(g_t *g_t, int status)
{
    sfEvent event;

    if (status == 1) {
        if (display_menu(g_t) == 2)
            return (1);
    }
    game_turn(g_t, event);
    sfRenderWindow_destroy(g_t->w_t->game);
    return (0);
}

int main(void)
{
    g_t *g_t = init_game();

    play_game(g_t, 1);
    return (0);
}
