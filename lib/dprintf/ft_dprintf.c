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

int	ft_dprintf(const char *format, ...)
{
    va_list	ap;
    int		count;
    int        fd;

    count = 0;
    va_start(ap, format);
    if (!format)
        return (-1);
    fd = open ("ErrorScan.txt", O_RDWR | O_CREAT, 0777);
	if (fd == -1)
    {
        perror("Error opening fd in ft_dprintf");
        return (-1);
    }
    while (*format)
    {
        if (*format == '%')
            ft_dprint_format(*++format, ap, fd, &count);
        else if (*format == '\0')
            return (-1);
        else
            ft_dprint_char(*format, fd, &count);
        ++format;
    }
    va_end(ap);
    close(fd);
    return (count);
}
