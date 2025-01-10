/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:11:05 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/07 21:08:13 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parameters
// n: the integer to convert.
// Return value
// The string representing the integer.
// NULL if the allocation fails.
// External functs.
// malloc
// Description
// Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.

// take a number and tranform it in a string char.

char	*ft_writestring(char *str, long int n, int count, int sign)
{
	str[count--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[count] = (n % 10) + 48;
		n /= 10;
		count --;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

int	ft_count(long int number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		number *= -1;
		count++;
	}
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	number;
	char		*str;
	int			sign;
	int			count;
	long int	tmp;

	number = n;
	if (number < 0)
		tmp = number * -1;
	else
		tmp = number;
	sign = 0;
	if (number < 0)
		sign = 1;
	count = ft_count(number);
	number = tmp;
	str = (char *)malloc((count + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_writestring(str, number, count, sign);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	n = 0;
// 	char	*num;

// 	num = ft_itoa (n);
// 	printf("the number is:%s", num);
// 	return (0);
// }
