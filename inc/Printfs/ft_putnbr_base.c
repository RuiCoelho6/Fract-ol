/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:25:13 by rpires-c          #+#    #+#             */
/*   Updated: 2024/06/12 13:25:14 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	logic(unsigned long nbr, int base, char *b, int len)
{
	long int	temp;

	temp = nbr % base;
	nbr = nbr / base;
	if (nbr >= (unsigned long)base)
	{
		len = logic(nbr, base, b, len);
	}
	else if (nbr > 0)
	{
		ft_putchar(b[nbr]);
		len++;
	}
	ft_putchar(b[temp]);
	len++;
	return (len);
}

int	ft_putnbr_base(long int nbr, char *base, int lock_neg)
{
	int	len_base;
	int	len;

	len = 0;
	if (nbr < 0 && lock_neg != 1)
	{
		nbr = -(nbr);
		len++;
		ft_putchar('-');
	}
	len_base = ft_strlen(base);
	len = logic(nbr, len_base, base, len);
	return (len);
}

//  int main(int ac,char** av)
// {
// 	char *base = "0123456789ABCDEF";
// 	char *base_10 = "0123456789";
// 	//int a = ft_putnbr_base(atoi( av[1]),base);
// 	int a = ft_putnbr_base(LONG_MIN,base);
// 	printf("\n %p  ", LONG_MIN, LONG_MAX);
// 	//ft_putnbr_base(a,base_10);
// }