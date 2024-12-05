/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:19:15 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/07 23:30:47 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	char	*tbig;
	char	*tlittle ;

	tbig = (char *) big;
	tlittle = (char *)little;
	i = 0;
	j = 0;
	while (big[i] != '\0' && i < len)
	{
		if (tbig[i] == tlittle[j])
		{
			while (tlittle[j] == tbig[i] && tlittle[j] != '\0')
			{
				j++;
				i++;
				if (tlittle[j] == '\0' )
					return ((char *) little);
			}
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	big[] = "ciao nonna cara";
// 	char	little[] = "nonna";
// 	size_t	n = 9;
// 	printf ("Il risultato e': %s", ft_strnstr(big, little, n));
// 	return (0);
// }
