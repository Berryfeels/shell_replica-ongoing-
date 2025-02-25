/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:48:40 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 12:58:24 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (!dest && !src)
	{
		return (dest);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/* #include <stdio.h>
int main(void)
{
// we have to copy each byte
// from src to dst, does not handle
// overlaps
	char	string1[10] = "aaaaaaaaaa";
	char	string2[10] = "bbbbbbbbbb";
	printf("%s\n", (char*)ft_memcpy(string1, string2, 5));
	// printf("%s\n", (char*)memcpy(string1, string2, 5));

	char	string3[50];
	char	string4[] = "Hello, World!";
	printf("%s\n", (char*)ft_memcpy(string3, string4, ft_strlen(string4)));
	// printf("%s\n", (char*)memcpy(string3, string4, ft_strlen(string4)));
} */
