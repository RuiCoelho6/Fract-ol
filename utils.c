/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:28 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/16 15:26:52 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void get_nbrs(t_mlx_data *mlx, char **av)
{
	mlx->cmp_nbrs->real = ft_atod(av[2]);
	mlx->cmp_nbrs->imaginary = -ft_atod(av[3]);
}

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_atod(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;
	double	div;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	i = 0;
	div = 10.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			fraction += (str[i] - '0') / div;
			div *= 10.0;
			i++;
		}
	}
	return sign * (result + fraction);
}
