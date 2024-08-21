/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:10:53 by rpires-c          #+#    #+#             */
/*   Updated: 2024/06/17 15:14:57 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	identifier(char id, va_list args)
{
	if (id == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (id == 's')
		return (ft_putstrlen(va_arg(args, char *)));
	else if (id == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long)));
	else if (id == 'd')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 0));
	else if (id == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 0));
	else if (id == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 1));
	else if (id == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned), "0123456789abcdef", 0));
	else if (id == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned), "0123456789ABCDEF", 0));
	else if (id == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			num_percentagens;
	int			cont;
	va_list		args;

	num_percentagens = 0;
	i = 0;
	cont = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			num_percentagens += identifier(str[i + 1], args);
			i += 2;
			cont += 2;
		}
		else
			ft_putchar(str[i++]);
	}
	va_end(args);
	return (i + num_percentagens - cont);
}

/*int    main()
{
    char c = 'k'; // %c
    char *str = "String test"; // %s
    char *var; var = &c;// %p
    int    nbr = -5;// %d // %i
    unsigned int nbrr = 20;// %u
    int b= 0xffffffff;// %x // %X
    // %%

    int i;
    printf("Printf replica:\n");
    i = ft_printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
    printf("\nReturn Value: %d", i);
    ///////////////////////////////
    printf("\nPrintf original:\n");
    i = printf("| TEST TEXT |\n| Single Char: %c |\n| String: %s |\n| Pointer Adress: %p |\n| Decimal: %d |\n| Integer %i |\n| Unsign deci: %u |\n| HexLower: %x |\n| HexUpper: %X |\n| Percentage sign: %% |\n", c, str, var, nbr, nbr, nbrr, b, b);
    printf("\nReturn Value: %d", i);
    return (0);
}*/
