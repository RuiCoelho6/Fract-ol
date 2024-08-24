/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:48:06 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 16:51:43 by rpires-c         ###   ########.fr       */
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
		if ((z.real * z.real + z.imaginary * z.imaginary) > 4)
			return (iter);
		temp = z.real;
		z.real = z.real * z.real - z.imaginary * z.imaginary + cmp_nbrs->real;
		z.imaginary = 2 * z.imaginary * temp + cmp_nbrs->imaginary;
		iter++;
	}
	return (mlx->iter_max);
}

int	*init_colors(void)
{
	int	*colors;

	colors = NULL;
	colors = (int *)malloc(9 * sizeof(int));
	if (!colors)
		return (0);
	colors[0] = RED;
	colors[1] = BLUE;
	colors[2] = GREEN;
	colors[3] = ORANGE;
	colors[4] = PURPLE;
	colors[5] = YELLOW;
	colors[6] = CYAN;
	colors[7] = MAGENTA;
	colors[8] = WHITE;
	return (colors);
}

void	draw_julia(t_mlx_data *mlx)
{
	int		x;
	int		y;
	t_cmp	z;
	int		iter;
	int		*colors;

	colors = init_colors();
	x = 0;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			z = convert(x, y, mlx);
			iter = count_iter_jul(z, mlx->cmp_nbrs, mlx);
			if (iter == mlx->iter_max)
				my_mlx_pixel_put(mlx->img, x, y, BLACK);
			else
				my_mlx_pixel_put(mlx->img, x, y, colors[iter % NUM_COLORS]);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, mlx->img->ptr, 0, 0);
	free(colors);
}
