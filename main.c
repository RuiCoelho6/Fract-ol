/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:18 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 15:40:06 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_all_vars(t_mlx_data *mlx)
{
	mlx->zoom = 150;
	mlx->iter_max = 100;
	mlx->img = (t_img_data *)ft_calloc(1, sizeof(t_img_data));
	mlx->img->bits_per_pixel = 0;
	mlx->img->line_length = 0;
	mlx->img->endian = 0;
	mlx->cmp_nbrs = (t_cmp *)ft_calloc(1, sizeof(t_cmp));
	mlx->cmp_nbrs->real = 0.0;
	mlx->cmp_nbrs->imaginary = 0.0;
}

void	init(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return ;
	mlx->window_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!mlx->window_ptr)
		return ;
	mlx->img->ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img->ptr)
		return ;
	mlx->img->addr = mlx_get_data_addr(mlx->img->ptr, &mlx->img->bits_per_pixel,
			&mlx->img->line_length, &mlx->img->endian);
}

int	main(int ac, char **av)
{
	t_mlx_data	mlx;
	int			i;

	i = -1;
	init_all_vars(&mlx);
	init(&mlx);
	while (av[1][++i] != 0)
		av[1][i] = ft_tolower(av[1][i]);
	mlx.name = av[1];
	if (!ft_strncmp(mlx.name, "mandelbrot", 12))
		draw_man(&mlx);
	else if (!ft_strncmp(mlx.name, "julia", 6))
	{
		get_nbrs(&mlx, av);
		draw_julia(&mlx);
	}
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_mouse_hook(mlx.window_ptr, &mouse_scroll, &mlx);
	mlx_hook(mlx.window_ptr, KeyPress, KeyPressMask, &murder_window_key, &mlx);
	mlx_hook(mlx.window_ptr, ClientMessage, NoEventMask, &murder_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
