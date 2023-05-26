# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 22:51:24 by amoukhle          #+#    #+#              #
#    Updated: 2023/05/25 22:55:22 by amoukhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = philo.c func_utils.c philo_operations.c the_simulation.c func_tools.c
OBJS = $(SRCS:.c=.o)
NAME = philo_bonus

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c philo.h
	cc $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re