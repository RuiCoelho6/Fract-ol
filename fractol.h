/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:45:44 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/16 15:43:09 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
# define WIDTH 666
# define HEIGHT 420
#define REF_WIDTH (WIDTH / 2)
#define REF_HEIGHT (HEIGHT / 2)

# include "inc/Printf/ft_printf.h"
# include "inc/minilibx-linux/mlx.h"
# include "colors.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
#include <ctype.h>
# include "inc/minilibx-linux/mlx_int.h"
#include <stdlib.h>

typedef struct s_img_data
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img_data;

typedef struct s_cmp
{
	double	real;
	double	imaginary;
}			t_cmp;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*window_ptr;
	char		*name;
	double		zoom;
	t_img_data	*img;
	t_cmp		*cmp_nbrs;
	int			iter_max;
}			t_mlx_data;

void get_nbrs(t_mlx_data *mlx, char **av);
double	ft_atod(const char *str);
t_cmp convert(int x, int y, t_mlx_data *mlx);
void	my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color);
void	draw_man(t_mlx_data *mlx);
void	draw_julia(t_mlx_data *mlx);
#endif
