/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:48:19 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 13:19:52 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*stored_s;

	i = 0;
	stored_s = (const unsigned char *)s;
	while (i < n)
	{
		if (stored_s[i] == (unsigned char )c)
			return ((void *)&stored_s[i]);
		i++;
	}
	return (0);
}
/* #include <stdio.h>
int main() {
	char str[] = "Hello, World!";  // Test string

	// Test 1: Search for a character that exists
	char *result1 = ft_memchr(str, 'W', sizeof(str));
	printf("Test 1: %s\n", result1 ? result1 : "Character not found");

	// Test 2: Search for a character that does not exist
	char *result2 = ft_memchr(str, 'x', sizeof(str));
	printf("Test 2: %s\n", result2 ? result2 : "Character not found");

	// Test 3: Search with zero length
	char *result3 = ft_memchr(str, 'H', 0);
	printf("Test 3: %s\n", result3 ? result3 : "Character not found");

	// Test 4: Search for a character at the edge of the range
	char *result4 = ft_memchr(str, '!', sizeof(str));
	printf("Test 4: %s\n", result4 ? result4 : "Character not found");

	// Test 5: Search for the null terminator
	char *result5 = ft_memchr(str, '\0', sizeof(str));
	printf("Test 5: %s\n", result5 ? result5 : "Character not found");

	return 0;
} */
