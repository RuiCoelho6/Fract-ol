# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 13:44:35 by rpires-c          #+#    #+#              #
#    Updated: 2024/08/05 12:22:19 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SOURCES = fractol.c \
fractol_utils.c \
inc/Printf/ft_printf.c \
inc/Printf/ft_putchar.c \
inc/Printf/ft_print_pointer.c \
inc/Printf/ft_putnbr_base.c \
inc/Printf/ft_putstrlen.c \
inc/libft/ft_strlen.c \
inc/libft/ft_isdigit.c \
inc/libft/ft_tolower.c \

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	cc -Wall -Werror -Wall -Iinc/mlx-linux $(SOURCES) -lXext -lX11 -Linc/minilibx-linux -lmlx

%.o:%.c fractol.h
	cc -c $(FLAGS) -o $@ $<  

clean:
	rm -f  $(OBJECT)

fclean: clean
	rm -f $(NAME) 

re: fclean all

exec:
	cc -Iinc/mlx-linux $(SOURCES) -lXext -lX11 -Linc/minilibx-linux -lmlx -o fractol

.PHONY: all clean fclean re

norm: 
	yes y | python3 -m c_formatter_42 -c $(SOURCES)