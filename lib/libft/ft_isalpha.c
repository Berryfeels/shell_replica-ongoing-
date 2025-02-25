/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:25:48 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 10:22:29 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
/* #include <stdio.h>
int	main(void)
{
	printf("y %i\n", ft_isalpha('a'));
	printf("n %i\n", ft_isalpha('/'));
	printf("n %i\n", ft_isalpha('{'));
	printf("n %i\n", ft_isalpha('1'));
	printf("y %i\n", ft_isalpha('W'));
	printf("y %i\n", ft_isalpha('x'));
} //ok */
