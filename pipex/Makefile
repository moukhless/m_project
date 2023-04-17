# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 16:00:18 by amoukhle          #+#    #+#              #
#    Updated: 2023/04/12 19:56:53 by amoukhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = pipex_man.c functions1_man.c functions2_man.c check_arg1_man.c check_arg2_man.c exe_cmd_man.c
SRCS_BONUS = bonus/pipex_bonus.c bonus/exe_cmd_bonus.c bonus/functions1_bonus.c bonus/functions2_bonus.c bonus/check_arg1_bonus.c bonus/check_arg2_bonus.c
OBJS = $(SRCS:_man.c=_man.o)
OBJS_BONUS = $(SRCS_BONUS:_bonus.c=_bonus.o)
NAME = pipex
NAME_BONUS = pipex_bonus

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)
	
bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	cc $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%_man.o: %_man.c pipex.h
	cc $(FLAGS) -c $< -o $@
	
%_bonus.o: %_bonus.c bonus/pipex_bonus.h
	cc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus