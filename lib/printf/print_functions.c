/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:53:43 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/09 22:06:05 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, int *count)
{
	write(1, &c, 1);
	return ((*count)++);
}

int	ft_print_string(char *str, int *count)
{
	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		ft_print_char(*str, count);
		str++;
	}
	return (*count);
}

int	ft_print_hexa(unsigned long n, char specifier, int *count)
{
	char	*symbols;

	if (specifier == 'x')
		symbols = "0123456789abcdef";
	else if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 16)
		ft_print_char(symbols[n], count);
	else
	{
		ft_print_hexa(n / 16, specifier, count);
		ft_print_hexa(n % 16, specifier, count);
	}
	return (*count);
}
