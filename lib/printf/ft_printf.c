/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:23:42 by stefanodipu       #+#    #+#             */
/*   Updated: 2024/02/09 22:01:22 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(const char specifier, va_list ap, int *count)
{
	if (specifier == 'c')
		ft_print_char(va_arg(ap, int), count);
	else if (specifier == 's')
		ft_print_string(va_arg(ap, char *), count);
	else if (specifier == 'p')
		ft_print_pointer((va_arg(ap, void *)), count);
	else if (specifier == 'd' || specifier == 'i')
		ft_print_number((va_arg(ap, int)), count);
	else if (specifier == 'u')
		ft_print_unsigned((va_arg(ap, unsigned int)), count);
	else if (specifier == 'x' || specifier == 'X')
		ft_print_hexa((va_arg(ap, unsigned int)), specifier, count);
	else if (specifier == '%')
	{
		*count += write(1, "%", 1);
	}
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			ft_print_format(*++format, ap, &count);
		else if (*format == '\0')
			return (-1);
		else
			ft_print_char(*format, &count);
		++format;
	}
	va_end(ap);
	return (count);
}
