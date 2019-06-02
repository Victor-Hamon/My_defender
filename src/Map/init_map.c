/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** initialization functions for defender
*/
#include "proto.h"
#include "macro.h"

t_turret *init_turrets(g_t *g_t)
{
    t_turret *turrets = malloc(sizeof(*g_t->turrets));

    turrets->c_t = malloc(sizeof(sfVector2f *));
    turrets->turs = malloc(sizeof(sfSprite *));
    turrets->rect_tur = malloc(sizeof(sfIntRect *));
    return (turrets);
}

sp_t *init_sprites(void)
{
    sp_t *sp_t = malloc(sizeof(*sp_t));

    init_sprites_1(sp_t);
    init_sprites_2(sp_t);
    sp_t->clock_t1 = sfClock_create();
    sp_t->clock_t2 = sfClock_create();
    sp_t->clock_t3 = sfClock_create();
    init_rect(sp_t);
    return (sp_t);
}

audio_t *init_audio(void) {
    audio_t *audio_t = malloc(sizeof(*audio_t));

    audio_t->ambiance = sfMusic_createFromFile("assets/Audio/ambiance.ogg");
    audio_t->init = sfMusic_createFromFile("assets/Audio/init.ogg");
    return (audio_t);
}

g_t *init_game(void)
{
    g_t *g_t = malloc(sizeof(*g_t));

    g_t->nb_mob = 4;
    g_t->nb_tur = 0;
    g_t->audio_t = init_audio();
    g_t->arr_t = init_arrays();
    g_t->vec_t = init_vector();
    g_t->game_stat = init_stats();
    g_t->sp_t = init_sprites();
    g_t->release = 0;
    g_t->coord_tabf = init_coord_tabf(g_t);
    g_t->move = init_move(g_t);
    g_t->mobs = init_mobs(g_t);
    g_t->hp = init_mobs_hp(g_t);
    g_t->tmp_t = malloc(sizeof(*g_t->tmp_t));
    g_t->tmp_t->tmp_sp = sfSprite_create();
    g_t->turrets = init_turrets(g_t);
    g_t->w_t = malloc(sizeof(*g_t->w_t));
    g_t->w_t->game = createWindow(1920, 1080);
    return (g_t);
}

int *init_mobs_hp(g_t *g_t)
{
    int *hp = malloc(sizeof(int) * g_t->nb_mob);
    for (int i = 0; i < g_t->nb_mob; i++) {
        hp[i] = 20;
    }
    return (hp);
}