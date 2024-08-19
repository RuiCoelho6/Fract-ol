/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:18 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/16 16:02:40 by rpires-c         ###   ########.fr       */
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

int	main (int ac, char **av)
{
	t_mlx_data	mlx;
	int		i;

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
