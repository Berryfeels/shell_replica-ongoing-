/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:09:53 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/28 19:43:54 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	i = 0;
	while ((ss1[i] != '\0' || ss2[i] != '\0') && i < n)
	{
		if (ss1[i] > ss2[i])
		{
			return (1);
		}
		else if (ss1[i] < ss2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, Aniverse!";
    size_t length = 15;

    int result = ft_memcmp(str1, str2, length);

    if (result == 0)
    {
        printf("Both strings are equal.\n");
    }
    else if (result < 0)
    {
        printf("String 1 is less than String 2.\n");
    }
    else
    {
        printf("String 1 is greater than String 2.\n");
    }

    return 0;
}*/
