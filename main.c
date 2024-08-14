/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:18 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/14 16:11:27 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	exit(1);
	return (0);
}

int	murder_window_key(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Escape)
		murder_window(mlx);
	return (0);
}

static double ft_atod(const char *nptr)
{
	double sum;
	double frac;
	int sign;
	int i;
	int frac_div;

	i = 0;
	sum = 0.0;
	frac = 0.0;
	sign = 1;
	frac_div = 1;
	if (nptr[i++] == '-')
		sign = -1;
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
		sum = sum * 10 + (nptr[i++] - '0');
	if (nptr[i] == '.' || nptr[i] == ',')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		frac = frac * 10 + (nptr[i++] - '0');
		frac_div *= 10;
	}
	sum = sum + (frac / frac_div);
	return (sign * sum);
}

static void	init_all_vars(t_mlx_data *mlx, t_cmp *cmp)
{
	mlx->zoom = 1.0;
	mlx->iter_max = 100;
	mlx->img = (t_img_data *)ft_calloc(1, sizeof(t_img_data));
	mlx->img->bits_per_pixel = 0;
	mlx->img->line_length = 0;
	mlx->img->endian = 0;
	cmp->real = 0.0;
	cmp->imaginary = 0.0;
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
	t_cmp 		z;
	int		i;

	i = -1;
	init_all_vars(&mlx, &z);
	init(&mlx);
	while (av[1][++i] != 0)
		av[1][i] = ft_tolower(av[1][i]);
	if (!ft_strncmp(av[1], "mandelbrot", 12))
		draw_man(&mlx, mlx.img);
	else if (!ft_strncmp(av[1], "julia", 6))
		{
			z.real = ft_atod(av[2]);
			z.imaginary = ft_atod(av[3]);
			// draw_julia();
		}
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_hook(mlx.window_ptr, KeyPress, KeyPressMask, &murder_window_key, &mlx);
	mlx_hook(mlx.window_ptr, ClientMessage, NoEventMask, &murder_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
