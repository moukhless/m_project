# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 16:00:18 by amoukhle          #+#    #+#              #
#    Updated: 2023/04/09 01:24:46 by amoukhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = pipex.c functions1.c functions2.c check_arg1.c check_arg2.c exe_cmd.c
OBJS = $(SRCS:.c=.o)
NAME = pipex

all : $(NAME)

$(NAME) : $(OBJS) pipex.h
	cc $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.c
	cc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all