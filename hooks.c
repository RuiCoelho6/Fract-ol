/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:40:14 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 15:43:08 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_scroll(int button, int x, int y, t_mlx_data *mlx)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		mlx->zoom += 20;
		if (mlx->zoom > INT_MAX)
			mlx->zoom = INT_MAX;
	}
	else if (button == Button5)
	{
		mlx->zoom -= 10;
		if (mlx->zoom < 1)
			mlx->zoom = 1;
	}
	else
		return (0);
	mlx_clear_window(mlx->mlx_ptr, mlx->window_ptr);
	if (!ft_strncmp(mlx->name, "mandelbrot", 12))
		draw_man(mlx);
	else if (!ft_strncmp(mlx->name, "julia", 6))
		draw_julia(mlx);
	return (0);
}

int	handle_no_event(void *mlx)
{
	return (0);
}

int	murder_window(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx->img);
	free(mlx->cmp_nbrs);
	exit(1);
	return (0);
}

int	murder_window_key(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Escape)
		murder_window(mlx);
	return (0);
}
