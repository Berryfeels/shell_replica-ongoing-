/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:23:42 by stefanodipu       #+#    #+#             */
/*   Updated: 2024/10/01 18:47:35 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprint_format(const char specifier, va_list ap, int *count)
{
	if (specifier == 'c')
		ft_dprint_char(va_arg(ap, int), count);
	else if (specifier == 's')
		ft_dprint_string(va_arg(ap, char *), count);
	else if (specifier == 'p')
		ft_dprint_pointer((va_arg(ap, void *)), count);
	else if (specifier == 'd' || specifier == 'i')
		ft_dprint_number((va_arg(ap, int)), count);
	else if (specifier == 'u')
		ft_dprint_unsigned((va_arg(ap, unsigned int)), count);
	else if (specifier == 'x' || specifier == 'X')
		ft_dprint_hexa((va_arg(ap, unsigned int)), specifier, count);
	else if (specifier == '%')
	{
		*count += write(1, "%", 1);
	}
	return (*count);
}

int	ft_dprintf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int fd;

	count = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	fd = open("Errors.txt", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		return (-1);
	dup2 (1, fd);
	while (*format)
	{
		if (*format == '%')
			ft_dprint_format(*++format, ap, &count);
		else if (*format == '\0')
			return (-1);
		else
			ft_dprint_char(*format, &count);
		++format;
	}
	va_end(ap);
	return (count);
}
