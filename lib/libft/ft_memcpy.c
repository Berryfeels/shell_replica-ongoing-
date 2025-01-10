/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:05:22 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/30 20:43:05 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstcpy;
	const unsigned char	*srccpy;
	size_t				i;

	if (dst == NULL || src == NULL)
		return (NULL);
	dstcpy = (unsigned char *)dst;
	srccpy = (const unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		dstcpy[i] = srccpy[i];
		i ++;
		n --;
	}
	return (dst);
}
/*
#include <stdio.h>
int main() {
	char src[] = "Hello, World!";
	char dest[20];

	// Using ft_memcpy to copy from src to dest
	ft_memcpy(dest, src, 5);

	// Printing the content of dest
	printf("Destination after ft_memcpy: %s\n", dest);

	return 0;
}*/
