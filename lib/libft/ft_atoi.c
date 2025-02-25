/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:49 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 11:31:43 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		num;
	int		sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+' )
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%i <- mine\n", ft_atoi("123"));
	printf("%i\n", atoi("123"));
	printf("%i <- mine \n ", ft_atoi("-123abc"));
	printf("%i\n", atoi("-123abc"));
	printf("%i <- mine \n ", ft_atoi("-123"));
	printf("%i\n", atoi("-123"));
	printf("%i <- mine \n ", ft_atoi("   123abc456"));
	printf("%i\n", atoi("   123abc456"));
	printf("%i <- mine \n ", ft_atoi("-2147483648"));
	printf("%i\n", atoi("-2147483648"));
	printf("%i <- mine \n ", ft_atoi("000598ak00g"));
	printf("%i\n", atoi("000598ak00g"));
} */
