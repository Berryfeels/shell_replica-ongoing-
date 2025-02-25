/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:11:26 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 10:24:26 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizecount(int n)
{
	int		size;
	long	num;

	size = 1;
	num = n;
	if (n < 0)
	{
		num = -num;
		size++;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	num;
	int		size;
	char	*str;

	num = n;
	if (n < 0)
		num = -num;
	size = ft_sizecount(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[size--] = '\0';
	while (num > 0)
	{
		str[size--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	printf("%s\n", ft_itoa(1300));
// 	printf("%s\n", ft_itoa(100));
// 	printf("%s\n", ft_itoa(-300)); //1316
// 	printf("%s\n", ft_itoa(INT_MIN)); //-2147483648
// 	printf("%s\n", ft_itoa(INT_MAX)); //2147483647
// }
