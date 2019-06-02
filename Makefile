##
## EPITECH PROJECT, 2018
## Project Name
## File description:
## Makefile for bsq
##

CC	=	gcc -lm -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

RM	=	rm -rf

CFLAGS +=	-W -Wall -Wextra
CFLAGS +=       -I ./include/ -W

NAME	=	my_defender

SRCS	=	src/Map/d_map.c 		\
		src/Map/get_next_line.c 	\
		src/Map/init_map.c 		\
		src/Map/index.c 		\
		src/Map/move_mob.c 		\
		src/Map/move_coord.c 		\
		src/Map/moves.c 		\
		src/Map/anim.c 			\
		src/Map/display_game.c 			\
		src/Map/init_sprites.c 			\
		src/Map/init_game.c 			\
		src/Action/mouse_actions.c 		\
		src/Action/choose_tower.c 		\
		src/Action/which_tower.c 		\
		src/Action/display_tower_overview.c 	\
		src/Action/realloc_tabs.c 		\
		src/Action/realloc_tab2.c 		\
		src/Action/calc_functions.c 	\
		src/Action/menu.c 		\
		src/Action/pause.c 		\
		src/lib/my_strlen.c 		\
		src/lib/my_strcat.c 		\
		src/lib/my_revstr.c 		\

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:

	$(RM) $(OBJS)

fclean: clean

	$(RM) $(NAME)

re: all clean

.PHONY: all clean fclean re
