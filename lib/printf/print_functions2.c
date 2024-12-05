/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:05:30 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/02/09 22:07:35 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int n, int *count)
{
	char	*str;

	str = ft_itoa(n);
	if (!(str))
		return (-1);
	ft_print_string(str, count);
	free(str);
	return (*count);
}

int	ft_print_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
		ft_print_unsigned(n / 10, count);
	ft_print_char(n % 10 + '0', count);
	return (*count);
}

int	ft_print_pointer(void *ptr, int *count)
{
	unsigned long	ptr_address;

	if (!ptr)
		return (ft_print_string("(nil)", count));
	ft_print_string("0x", count);
	ptr_address = (unsigned long)ptr;
	ft_print_hexa(ptr_address, 'x', count);
	return (*count);
}
