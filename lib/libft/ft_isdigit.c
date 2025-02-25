/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:25:45 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 10:23:22 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
/* #include <stdio.h>
int	main(void)
{
	printf("n %i\n", ft_isdigit('a'));
	printf("n %i\n", ft_isdigit(128));
	printf("n %i\n", ft_isdigit(190));
	printf("y %i\n", ft_isdigit('1'));
	printf("y %i\n", ft_isdigit('9'));
	printf("y %i\n", ft_isdigit('5'));
	printf("n %i\n", ft_isdigit(-10));
} */
