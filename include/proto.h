/*
** EPITECH PROJECT, 2018
** my
** File description:
** my
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <errno.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <stddef.h>
#include <time.h>

typedef struct
{
    char *char_list;
    char *turret_list;
    char **map;
    char **layer;
}arr_t;

typedef struct window_s
{
    sfRenderWindow *game;
}w_t;

typedef struct vec_s
{
    sfVector2f pos_tile;
    sfVector2f pos_turret;
    sfVector2f pos_t_panel;
    sfVector2i pos_mouse;
    sfVector2f pos_quit;
    sfVector2f pos_play;
    sfVector2f pos_opt;
}vec_t;

typedef struct sprite_s
{
    sfTexture *sheet_text;
    sfSprite *sp_s;
    sfTexture *turr1_txt;
    sfSprite *turret_sheet;
    sfTexture *turr_pan;
    sfSprite *turret_panel;
    sfTexture *start_m_text;
    sfSprite *start_m;
    sfTexture *o_menu_text;
    sfSprite *o_menu;
    sfTexture *highl_text;
    sfSprite *highl;
    sfTexture *volume_text;
    sfSprite *volume;
    sfTexture *mob_text;
    sfSprite *quit;
    sfTexture *quit_text;
    sfSprite *play;
    sfTexture *play_text;
    sfSprite *opt;
    sfTexture *opt_text;
    sfTexture *pause_text;
    sfSprite *pause;
    sfSprite *hp;
    sfTexture *hp_text;
    sfTexture *bar_text;
    sfSprite *bar;
    sfIntRect rect;
    sfIntRect t_rect;
    sfIntRect h_rect;
    sfIntRect hp_rect;
    sfIntRect vol_rect;
    sfClock *clock_t1;
    float sec_t1;
    sfTime time_t1;
    sfClock *clock_t2;
    float sec_t2;
    sfTime time_t2;
    sfClock *clock_t3;
    float sec_t3;
    sfTime time_t3;
}sp_t;

typedef struct audio_s
{
    sfMusic *ambiance;
    sfMusic *init;
}audio_t;

typedef struct game_stat_s
{
    int money;
    int hp;
    int SP;
    int killed_foe;
}game_stat_t;

typedef struct s_coord
{
    int x;
    int y;
}t_coord;

typedef struct s_move
{
    int up;
    int down;
    int right;
    int left;
}t_move;


typedef struct s_turret
{
    sfIntRect *rect_tur;
    sfVector2f *c_t;
    sfSprite **turs;
    int *type;
}t_turret;

typedef struct temp_values_s
{
    sfIntRect tmp_r;
    sfVector2f tmp_p;
    sfTexture *tmp_txt;
    sfSprite *tmp_sp;
    sfVector2f origi;
    int type;
}tmp_t;

typedef struct game_s
{
    char turret;
    int nb_mob;
    int nb_tur;
    int release;
    arr_t *arr_t;
    t_move **move;
    vec_t *vec_t;
    tmp_t *tmp_t;
    int *hp;
    audio_t *audio_t;
    sp_t *sp_t;
    w_t *w_t;
    sfSprite **mobs;
    sfVector2i *coord_tab;
    sfVector2f *coord_tabf;
    game_stat_t *game_stat;
    t_turret *turrets;
}g_t;

t_move **init_move(g_t *g_t);
void down_move(t_move *);
int *init_mobs_hp(g_t *g_t);
vec_t *init_vector(void);
t_move **init_move(g_t *g_t);
void move_down_and_up(g_t *g_t, int i, int out_of_range);
void manage_wave_1(g_t *g_t, int i, int out_of_range);
void down_and_up(g_t *g_t, int i, int out_of_range);
void right_and_left(g_t *g_t, int i, int out_of_range);
void manage_wave_2(g_t *g_t, int i, int out_of_range);
void choose_tower_2(g_t *g_t, sfVector2f pos_mousef);
void choose_tower_1(g_t *g_t, sfVector2f pos_mousef);
void choose_tower(g_t *g_t, sfVector2f pos_mousef);
void up_move(t_move *move);
void down_move(t_move *move);
void right_move(t_move *move);
void left_move(t_move *move);
void set_new_turret_rec(g_t *g_t);
game_stat_t *init_stats(void);
void init_rect(sp_t *sp_t);
void init_sprites_1(sp_t *sp_t);
void init_sprites_2(sp_t *sp_t);
void up_move(t_move *);
void set_new_turret_sprite(g_t *g_t, sfVector2f origi);
void dispay_turret_panel(g_t *g_t);
void choose_tower(g_t *g_t, sfVector2f pos_mousef);
void display_tiles(g_t *g_t);
int *my_realloc_type(g_t *g_t);
t_coord *init_coord(void);
sfSprite **init_mobs(g_t *g_t);
sfRenderWindow *createWindow(int width, int height);
arr_t *init_arrays(void);
void display_turrets(g_t *g_t);
void display_stats(g_t *g_t);
void create_mob(g_t *g_t);
void select_turret(g_t *g_t, sfVector2f pos_mousef);
bool check_if_posable(int rankx, int ranky, g_t *g_t);
float get_angle(sfVector2f pos1, sfVector2f pos2);
int is_in_range(sfVector2f p_mob, sfVector2f pos_turr);
void change_turrets_rotations(g_t *g_t);
void set_new_turret_vect(g_t *g_t, sfVector2f pos_mousef);
sfSprite **my_realloc_sp_turrets(g_t *g_t);
sfVector2f *my_realloc_vect_turrets(g_t *g_t);
sfIntRect *my_realloc_rect_turrets(g_t *g_t);
void right_move(t_move *);
void display_overview(g_t *g_t, sfVector2f pos_mousef);
void drag(g_t *g_t, sfVector2f pos_mousef);
void drop(g_t *g_t, sfVector2f pos_mousef);
void left_move(t_move *);
void move(g_t *g_t);
void create_new_wave(g_t *g_t);
void change_turrets_rotations(g_t *g_t);
bool check_if_posable(int rankx, int ranky, g_t *g_t);
void select_turret(g_t *g_t, sfVector2f pos_mousef);
char *my_strcat(char *dest, char const *src);
void dispay_turret_panel(g_t *g_t);
void choose_options(g_t *g_t, int status);
int create_map_tab(int fd, char **map);
int create_map_tab(int fd, char **map);
void do_all_animations(g_t *g_t, int i);
void get_coo_of_click(g_t *g_t);
sfSprite **init_mobs(g_t *g_t);
int find_rank(char c, char *index);
char *get_next_line(const int fd);
int check_pause(g_t *g_t);
int display_menu(g_t *g_t);
sfVector2f *init_coord_tabf(g_t *g_t);
int play_game(g_t *g_t, int status);
char **fill_with_names(void);
g_t *init_game();
char *fill_with_char(void);
char *my_revstr(char *str);
bool is_click_true(void);
int my_strlen(char *str);
bool click(void);

#endif /* PROTO_H_ */
