/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:11 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 13:15:58 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The memmove() function copies n bytes from memory
area src to memory area dest.
The memory areas may overlap: copying takes place as though the
bytes in src are first copied into a
temporary array that does not overlap src or dest, and the bytes are then
copied from the temporary array to dest. */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (dest_ptr);
}
/* #include <stdio.h>
int main(void)
{
	char	string1[10] = "aaaaaaaaaa";
	char	string2[10] = "bbbbbbbbbb";
	printf("%s\n", (char*)ft_memmove(string1, string2, 5));
	printf("%s\n", (char*)memmove(string1, string2, 5));

	char	string3[13] = "aaaaaaaaaaaaa";
	char	string4[10] = "bbbbbbbbbb";
	printf("%s\n", (char*)ft_memmove(string3, string4, 5));
	printf("%s\n", (char*)memmove(string3, string4, 5));
} */
