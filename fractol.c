/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:22:35 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/05 12:25:50 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *mlx_data)
{
	return (0);
}

int	murder_window(t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->window);
	return (0);
}

int	murder_window_key(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(mlx_data->mlx, mlx_data->window);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_mlx_data *mlx_data, t_img_data *img_data)
{
	double	mouse_y;
	double	mouse_x;

	mlx_clear_window(mlx_data->mlx, mlx_data->window);
	mouse_x = mlx_data->xmin
		+ (x * (mlx_data->xmax - mlx_data->xmin)) / WIDTH;
	mouse_y = mlx_data->ymin
		+ (y * (mlx_data->ymax - mlx_data->ymin)) / HEIGHT;
	if (button == 4)
	{
		mlx_data->xmin = mouse_x + (mlx_data->xmin - mouse_x) / mlx_data->zoom;
		mlx_data->ymin = mouse_y + (mlx_data->ymin - mouse_y) / mlx_data->zoom;
		mlx_data->xmax = mouse_x + (mlx_data->xmax - mouse_x) / mlx_data->zoom;
		mlx_data->ymax = mouse_y + (mlx_data->ymax - mouse_y) / mlx_data->zoom;
	}
	if (button == 5)
	{
		mlx_data->xmin = mouse_x + (mlx_data->xmin - mouse_x) * mlx_data->zoom;
		mlx_data->ymin = mouse_y + (mlx_data->ymin - mouse_y) * mlx_data->zoom;
		mlx_data->xmax = mouse_x + (mlx_data->xmax - mouse_x) * mlx_data->zoom;
		mlx_data->ymax = mouse_y + (mlx_data->ymax - mouse_y) * mlx_data->zoom;
	}
	my_mlx_pixel_put(img_data, REF_HEIGHT, REF_WIDTH, 0x00FF0000);
	return (mlx_data->zoom);
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
    if (nptr[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (nptr[i] == '+')
        i++;
    while (nptr[i] && ft_isdigit(nptr[i]))
    {
        sum = sum * 10 + (nptr[i] - '0');
        i++;
    }
    if (nptr[i] == '.' || nptr[i] == ',')
    {
        i++;
        while (nptr[i] && ft_isdigit(nptr[i]))
        {
            frac = frac * 10 + (nptr[i] - '0');
            frac_div *= 10;
            i++;
        }
    }
    sum = sum + (frac / frac_div);
    return (sign * sum);
}

int	main(int ac, char **av)
{
	t_mlx_data	mlx_data;
	t_img_data  img_data;
	double		nbr_r;
	double		nbr_i;
	int			i;

	i = -1;
	mlx_data.mlx = mlx_init();
	if (mlx_data.mlx == NULL)
		return (0);
	mlx_data.window = mlx_new_window(mlx_data.mlx, WIDTH, HEIGHT, "Fract-ol");
	if (mlx_data.window == NULL)
		return (0);
	img_data.img = mlx_new_image(mlx_data.mlx, WIDTH, HEIGHT);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel, &img_data.line_length,
								&img_data.endian);
	my_mlx_pixel_put(&img_data, REF_WIDTH, REF_HEIGHT, 0x00FF0000);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.window, img_data.img, 0, 0);
	while (av[1][++i] != 0)
		av[1][i] = ft_tolower(av[1][i]);
	if(ac == 2)
	{
		if(ft_strcmp(av[1], "mandelbrot"))
		{
			printf("Mandelbrot");
		}
	}
	else if(ac == 4)
	{
		if(ft_strcmp(av[1], "julia"))
		{
			nbr_r = ft_atod(av[2]);
			nbr_i = ft_atod(av[3]);
		}
	}

	mlx_loop_hook(mlx_data.mlx, &handle_no_event, &mlx_data);
	mlx_hook(mlx_data.window, 4, 0, &mouse_scroll, &mlx_data);
	mlx_hook(mlx_data.window, KeyPress, KeyPressMask, &murder_window_key, &mlx_data);
	mlx_hook(mlx_data.window, ClientMessage, NoEventMask, &murder_window, &mlx_data);
	mlx_loop(mlx_data.mlx);
	mlx_destroy_image(mlx_data.mlx, img_data.img);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
}