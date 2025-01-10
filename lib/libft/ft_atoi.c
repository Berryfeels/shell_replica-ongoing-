/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:04:34 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/30 23:10:43 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		num;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if ((*str == 43 || *str == 45) && (*(str + 1) == 43 || *(str + 1) == 45))
		return (0);
	if (*str == 45)
	{
		sign *= -1;
		++str;
	}
	if (*str == 43)
		++str;
	num = 0;
	while (*str && *str >= 48 && *str <= 57)
		num = num * 10 + (*str++ - 48);
	return (num * sign);
}
// #include <stdio.h>
// int main (void)
// {
// 	char *number = "54";
// 	printf("The number is: %d", ft_atoi(number));
// 	return (0);
// }
