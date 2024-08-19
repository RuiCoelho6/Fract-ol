/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:48:06 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/16 15:27:09 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	count_iter_jul(t_cmp c, t_cmp *cmp_nbrs, t_mlx_data *mlx)
{
	t_cmp	z;
	double	temp;
	int		iter;

	iter = 0;
	z = c;
	while (iter < mlx->iter_max)
	{
		if((z.real * z.real + z.imaginary * z.imaginary) > 4)
			return (iter);
		temp = z.real;
		z.real = z.real * z.real - z.imaginary * z.imaginary + cmp_nbrs->real;
		z.imaginary = 2 * z.imaginary * temp + cmp_nbrs->imaginary;
		iter++;
	}
	return (mlx->iter_max);
}

void	draw_julia(t_mlx_data *mlx)
{
	t_cmp	z;
	double	i;
	double	j;
	int		iter;
	int		color;
	int colors[] = {RED, BLUE, GREEN, ORANGE, PURPLE, YELLOW, CYAN, MAGENTA, WHITE};

	i = 0;
	iter = 0;
	while (i++ < WIDTH)
	{
		j = 0;
		while (j++ < HEIGHT)
		{
			z = convert(i, j, mlx);
			if (iter == mlx->iter_max)
			    color = BLACK;
            else
                color = colors[iter % NUM_COLORS];
			iter = count_iter_jul(z, mlx->cmp_nbrs, mlx);
			my_mlx_pixel_put(mlx->img, i, j, color);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, mlx->img->ptr, 0, 0);
}
