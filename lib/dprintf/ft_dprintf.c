/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:23:42 by stefanodipu       #+#    #+#             */
/*   Updated: 2025/02/11 14:51:13 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprint_format(const char specifier, va_list ap, int fd, int *count)
{
	if (specifier == 'c')
		ft_dprint_char(va_arg(ap, int), fd, count);
	else if (specifier == 's')
		ft_dprint_string(va_arg(ap, char *), fd, count);
	else if (specifier == 'p')
		ft_dprint_pointer((va_arg(ap, void *)), fd, count);
	else if (specifier == 'd' || specifier == 'i')
		ft_dprint_number((va_arg(ap, int)), fd, count);
	else if (specifier == 'u')
		ft_dprint_unsigned((va_arg(ap, unsigned int)), fd, count);
	else if (specifier == 'x' || specifier == 'X')
		ft_dprint_hexa((va_arg(ap, unsigned int)), specifier, fd, count);
	else if (specifier == '%')
	{
		*count += write(fd, "%", 1);
	}
	return (*count);
}

int	open_fd(int *fd)
{
	*fd = open ("Log_file.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (*fd == -1)
		return (-1);
	return (0);
}

int	ft_dprintf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		fd;

	count = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	if (open_fd(&fd) == -1)
		return (-1);
	while (*format)
	{
		if (*format++ == '%')
		{
			if (*format == '\0')
				break ;
			ft_dprint_format(*format, ap, fd, &count);
		}
		else
			ft_dprint_char(*format, fd, &count);
		format++;
	}
	va_end(ap);
	close(fd);
	return (count);
}
