/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:52:25 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 10:57:19 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%c\n", ft_tolower('A')); //a
	printf("%c\n", ft_tolower('B')); //b
	printf("%c\n", ft_tolower('Y')); //y
	printf("%c\n", ft_tolower('D')); //x
	printf("%c\n", ft_tolower('X')); //z
} //ok */
