# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoukhle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 22:11:17 by amoukhle          #+#    #+#              #
#    Updated: 2022/12/17 19:52:43 by amoukhle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_puthex_adr.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all:$(NAME)

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

%.o:%.c ft_printf.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
