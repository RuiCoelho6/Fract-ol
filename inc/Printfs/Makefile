# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 11:38:40 by rpires-c          #+#    #+#              #
#    Updated: 2024/06/21 14:45:06 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = ft_printf.c ft_print_pointer.c ft_putnbr_base.c \
ft_putstrlen.c ft_putchar.c libft/ft_strlen.c\

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

%.o:%.c ft_printf.h
	cc -c $(FLAGS) -o $@ $<  

clean:
	rm -f  $(OBJECT)

fclean: clean
	rm -f $(NAME) 

re: fclean all

exec:
	cc -g $(SOURCES)

norm: 
	yes y | python3 -m c_formatter_42 -c $(SOURCES)