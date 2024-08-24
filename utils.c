/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:28 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/24 16:28:56 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_nbrs(t_mlx_data *mlx, char **av)
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
	char	*end_ptr;
	double	result;

	result = strtod(str, &end_ptr);
	if (*end_ptr != '\0')
		printf("Warning: The entire string was not converted to a double.\n");
	return (result);
}
