/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:31:54 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/15 15:38:18 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iter_man(t_cmp c, t_mlx_data *mlx)
{
    t_cmp z;
    double temp;
    int iter;

    iter = 0;
    z.real = 0;
    z.imaginary = 0;
    while (iter < mlx->iter_max)
    {
        temp = z.real;
        z.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
        z.imaginary = 2 * z.imaginary * temp + c.imaginary;
        iter++;
		if((z.real * z.real + z.imaginary * z.imaginary) > 4)
            return iter;
    }
    return iter;
}

t_cmp convert(int x, int y, t_mlx_data *mlx)
{
    t_cmp cmp;
	
    cmp.real = ((double)x - (double)REF_WIDTH) / mlx->zoom;
    cmp.imaginary = ((double)y - (double)REF_HEIGHT) / mlx->zoom;
    return cmp;
}

void draw_man(t_mlx_data *mlx)
{
    t_cmp z;
    int x;
    int y;
    int iter;
    int color;
    int colors[] = {RED, BLUE, GREEN, ORANGE, PURPLE, YELLOW, CYAN, MAGENTA, WHITE};
   
    x = 0;
    while (x++ < WIDTH)
    {
        y = 0;
        while (y++ < HEIGHT)
        {
            z = convert(x, y, mlx);
            iter = iter_man(z, mlx);
            if (iter == mlx->iter_max)
                color = BLACK;
            else
                color = colors[iter % NUM_COLORS];
            my_mlx_pixel_put(mlx->img, x, y, color);
        }
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, mlx->img->ptr, 0, 0);
}
