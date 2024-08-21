/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:24:13 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/27 14:42:34 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	return (i);
}
/* int	main(int ac , char **av)
{
	char *teste = "d";
    ft_putstrlen(teste);
} */