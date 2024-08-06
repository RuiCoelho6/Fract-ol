/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:45:44 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/06 11:43:22 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 666
# define HEIGHT 420
#define REF_WIDTH (WIDTH / 2)
#define REF_HEIGHT (HEIGHT / 2)

# include "inc/Printf/ft_printf.h"
#include "inc/minilibx-linux/mlx.h"
#include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
#include <ctype.h>
# include "inc/minilibx-linux/mlx_int.h"
#include <stdlib.h>

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct	s_mlx_data
{
	void		*mlx;
	void		*window;
	double		zoom;
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;
	double		offsetx;
	double		offsety;
	int			p;
	t_img_data	data;
	int			iter_max;
}	t_mlx_data;

typedef struct	s_ref_data
{
	void	*mlx;
	void	*window;
	double	x;
	double	y;
}	t_ref_data;

bool	ft_strcmp(char *av, char *str);
void	my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color);
#endif