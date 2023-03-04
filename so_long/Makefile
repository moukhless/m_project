# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 21:15:35 by amoukhle          #+#    #+#              #
#    Updated: 2023/03/04 00:33:49 by amoukhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c so_long.c caracters.c map.c player_movement.c key_press.c functions.c functions1.c check_map_is_playable.c
SRCS_BONUS = get_next_line.c get_next_line_utils.c bonuss/so_long_bonus.c bonuss/caracters_bonus.c bonuss/map_bonus.c bonuss/player_movement_bonus.c bonuss/key_press_bonus.c bonuss/functions_bonus.c bonuss/check_map_is_playable_bonus.c bonuss/functions1_bonus.c bonuss/animations.c bonuss/enemy_movement.c
OBJS_BONUS =$(SRCS_BONUS:.c=.o)
OBJS = $(SRCS:.c=.o)
NAME = so_long
NAME_BONUS = so_long_bonus

all : $(NAME)

$(NAME) : $(OBJS) so_long.h get_next_line.h
	cc $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
bonus : $(OBJS_BONUS) bonuss/so_long_bonus.h get_next_line.h
	cc $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	
%.o: %.c
	cc $(FLAGS) -Imlx -c $< -o $@

clean : 
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus