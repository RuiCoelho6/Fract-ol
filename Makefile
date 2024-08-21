# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 16:43:10 by rpires-c          #+#    #+#              #
#    Updated: 2024/08/21 16:43:51 by rpires-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SOURCES = main.c utils.c mandelbrot.c julia.c \
inc/Printf/ft_printf.c \
inc/Printf/ft_putchar.c \
inc/Printf/ft_print_pointer.c \
inc/Printf/ft_putnbr_base.c \
inc/Printf/ft_putstrlen.c \
inc/libft/ft_strlen.c \
inc/libft/ft_calloc.c \
inc/libft/ft_bzero.c \
inc/libft/ft_strncmp.c \
inc/libft/ft_isdigit.c \
inc/libft/ft_tolower.c \

OBJECT = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wall

all: start_minilibx  $(NAME)

$(NAME): $(OBJECT)
	cc -g $(FLAGS) -lm -Iinc/mlx-linux $(SOURCES) -lXext -lX11 -Linc/minilibx-linux -lmlx -o fractol

%.o:%.c fractol.h
	cc -c $(FLAGS) -o $@ $<  

clean:
	rm -f  $(OBJECT)
	@make clean -C ./inc/minilibx-linux/

fclean: clean
	rm -f $(NAME)
	@make clean -C ./inc/minilibx-linux/

re: fclean all

start_minilibx:
	@make -C ./inc/minilibx-linux/

exec:
	cc -g $(FLAGS) -lm -Iinc/mlx-linux $(SOURCES) -lXext -lX11 -Linc/minilibx-linux -lmlx -o fractol

.PHONY: all clean fclean re

norm: 
	yes y | python3 -m c_formatter_42 -c $(SOURCES)
