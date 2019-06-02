/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** [file description here]
*/
#include "proto.h"
#include "macro.h"

vec_t *init_vector(void)
{
    vec_t *vec_t = malloc(sizeof(*vec_t));

    vec_t->pos_tile.x = 0;
    vec_t->pos_tile.y = 0;
    vec_t->pos_turret.x = 0;
    vec_t->pos_turret.y = 0;
    vec_t->pos_t_panel.x = 1890;
    vec_t->pos_t_panel.y = 0;
    vec_t->pos_quit.x = 861;
    vec_t->pos_quit.y = 640;
    vec_t->pos_play.x = 1491;
    vec_t->pos_play.y = 586;
    vec_t->pos_opt.x = 1648;
    vec_t->pos_opt.y = 0;
    return (vec_t);
}

game_stat_t *init_stats(void)
{
    game_stat_t *game_stat = malloc(sizeof(game_stat_t *));

    game_stat->hp = 20;
    game_stat->money = 1000;
    return (game_stat);
}

void init_rect(sp_t *sp_t)
{
    sp_t->rect.top = 0;
    sp_t->rect.left = 0;
    sp_t->rect.width = 30;
    sp_t->rect.height = 30;
    sp_t->t_rect.top = 0;
    sp_t->t_rect.left = 80;
    sp_t->t_rect.width = 43;
    sp_t->t_rect.height = 300;
    sp_t->h_rect.top = 0;
    sp_t->h_rect.left = 0;
    sp_t->h_rect.width = 65;
    sp_t->h_rect.height = 65;
    sp_t->hp_rect.top = 0;
    sp_t->hp_rect.left = 0;
    sp_t->hp_rect.width = 659;
    sp_t->hp_rect.height = 45;
    sp_t->vol_rect.top = 0;
    sp_t->vol_rect.left = 0;
    sp_t->vol_rect.width = 137;
    sp_t->vol_rect.height = 423;
}

void init_sprites_1(sp_t *sp_t)
{
    sp_t->sheet_text = sfTexture_createFromFile(PIC1, NULL);
    sp_t->sp_s = sfSprite_create();
    sfSprite_setTexture(sp_t->sp_s, sp_t->sheet_text, sfFalse);
    sp_t->turr1_txt = sfTexture_createFromFile(PIC2, NULL);
    sp_t->turret_sheet = sfSprite_create();
    sfSprite_setTexture(sp_t->turret_sheet, sp_t->turr1_txt, sfFalse);
    sp_t->turr_pan = sfTexture_createFromFile(PIC3, NULL);
    sp_t->turret_panel = sfSprite_create();
    sfSprite_setTexture(sp_t->turret_panel, sp_t->turr_pan, sfFalse);
    sp_t->start_m_text = sfTexture_createFromFile(PIC4, NULL);
    sp_t->start_m = sfSprite_create();
    sfSprite_setTexture(sp_t->start_m, sp_t->start_m_text, sfFalse);
    sp_t->o_menu_text = sfTexture_createFromFile(PIC5, NULL);
    sp_t->o_menu = sfSprite_create();
    sfSprite_setTexture(sp_t->o_menu, sp_t->o_menu_text, sfFalse);
    sp_t->highl_text = sfTexture_createFromFile(PIC6, NULL);
    sp_t->highl = sfSprite_create();
    sfSprite_setTexture(sp_t->highl, sp_t->highl_text, sfFalse);
    sp_t->volume_text = sfTexture_createFromFile(PIC7, NULL);
    sp_t->volume = sfSprite_create();
}

void init_sprites_2(sp_t *sp_t)
{
    sfSprite_setTexture(sp_t->volume, sp_t->volume_text, sfFalse);
    sp_t->quit_text = sfTexture_createFromFile(PIC8, NULL);
    sp_t->quit = sfSprite_create();
    sfSprite_setTexture(sp_t->quit, sp_t->quit_text, sfFalse);
    sp_t->play_text = sfTexture_createFromFile(PIC9, NULL);
    sp_t->play = sfSprite_create();
    sfSprite_setTexture(sp_t->play, sp_t->play_text, sfFalse);
    sp_t->opt_text = sfTexture_createFromFile(PIC10, NULL);
    sp_t->opt = sfSprite_create();
    sfSprite_setTexture(sp_t->opt, sp_t->opt_text, sfFalse);
    sp_t->mob_text = sfTexture_createFromFile(PIC11, NULL);
    sp_t->pause_text = sfTexture_createFromFile(PIC12, NULL);
    sp_t->pause = sfSprite_create();
    sfSprite_setTexture(sp_t->pause, sp_t->pause_text, sfFalse);
    sp_t->bar_text = sfTexture_createFromFile(PIC13, NULL);
    sp_t->bar = sfSprite_create();
    sfSprite_setTexture(sp_t->bar, sp_t->bar_text, sfFalse);
    sp_t->hp_text = sfTexture_createFromFile(PIC14, NULL);
    sp_t->hp = sfSprite_create();
    sfSprite_setTexture(sp_t->hp, sp_t->hp_text, sfFalse);
}