/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:48:37 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 13:15:38 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/* #include <stdio.h>
int	main(void)
{
	const char *str1 = "hello there";
	const char *str2 = "hello here";
	printf("Standard memcmp: %d\n", memcmp(str1, str2, 7));
	printf("Custom ft_memcmp: %d\n", ft_memcmp(str1, str2, 7));
} */
