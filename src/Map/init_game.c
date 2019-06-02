/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/

#include "proto.h"
#include "macro.h"

t_coord *init_coord(void)
{
    t_coord *coord = malloc(sizeof(*coord));
    coord->x = 0;
    coord->y = 0;
    return (coord);
}

sfSprite **init_mobs(g_t *g_t)
{
    sfSprite **mobs = malloc(sizeof(sfSprite *) * g_t->nb_mob);
    for (int i = 0; i < g_t->nb_mob; i++) {
        mobs[i] = sfSprite_create();
        sfSprite_setTexture(mobs[i], g_t->sp_t->mob_text, sfFalse);
    }
    return (mobs);
}

sfVector2f *init_coord_tabf(g_t *g_t)
{
    sfVector2f *coord_tabf = malloc(sizeof(sfVector2f) * g_t->nb_mob);
    for (int i = 0; i < g_t->nb_mob; i++) {
        coord_tabf[i].x = - i * 90.0f;
        coord_tabf[i].y = 90.0f;
    }
    return (coord_tabf);
}

sfRenderWindow *createWindow(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode mode = {width, height, 32};

    window = sfRenderWindow_create(mode, "Game", sfClose | sfFullscreen, NULL);
    return window;
}

arr_t *init_arrays(void)
{
    arr_t *arr_t = malloc(sizeof(*arr_t));

    arr_t->char_list = fill_with_char();
    arr_t->turret_list = fill_with_char();
    arr_t->map = malloc(sizeof(char *) * 36);
    create_map_tab(open("assets/map", O_RDONLY), arr_t->map);
    arr_t->layer = malloc(sizeof(char *) * 36);
    create_map_tab(open("assets/turret_layer", O_RDONLY), arr_t->layer);
    return (arr_t);
}