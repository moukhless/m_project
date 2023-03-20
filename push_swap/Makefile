# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 15:56:19 by amoukhle          #+#    #+#              #
#    Updated: 2023/03/20 17:19:33 by amoukhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
SRCS = func_stack.c funct_support.c operations.c push_swap.c check_arguments.c funct_support1.c algorithme.c funct_support2.c algorithme_next.c do_rotate.c calcul_moves.c same_moves.c sort_3_5.c reset_mov.c
SRCS_BONUS = checker.c get_next_line.c get_next_line_utils.c func_stack.c funct_support.c operations.c check_arguments.c funct_support1.c algorithme.c funct_support2.c algorithme_next.c do_rotate.c calcul_moves.c same_moves.c sort_3_5.c checker1.c reset_mov.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = push_swap
NAME_BONUS = checker

all : $(NAME)

$(NAME) : $(OBJS) push_swap.h
	cc $(FLAGS) $(OBJS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) push_swap.h get_next_line.h
	cc $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
	
.PHONY : all clean fclean re bonus