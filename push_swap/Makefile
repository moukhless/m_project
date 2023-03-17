# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 15:56:19 by amoukhle          #+#    #+#              #
#    Updated: 2023/03/16 19:48:59 by amoukhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = func_stack.c funct_support.c operations.c push_swap.c check_arguments.c funct_support1.c algorithme.c funct_support2.c algorithme_next.c do_rotate.c calcul_moves.c same_moves.c sort_3_5.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS) push_swap.h
	cc $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
	
.PHONY : all clean fclean re