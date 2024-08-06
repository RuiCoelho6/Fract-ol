/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:13:54 by rpires-c          #+#    #+#             */
/*   Updated: 2024/08/05 12:14:43 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img_data *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x * (img_data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

bool	ft_strcmp(char *av, char *str)
{
	int	i;
	
	i = 0;
	while (av[i] != 0)
	{
		if(av[i] != str[i])
			return (false);
		i++;
	}
	return (true);
}
