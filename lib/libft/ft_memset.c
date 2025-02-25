/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:15 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 12:13:49 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_s;

	new_s = s;
	i = 0;
	while (i < n)
	{
		new_s[i] = (unsigned char)c;
		i++;
	}
	return (new_s);
}

// fills the  first n bytes of the memory area
// pointed to by s with byte c.
// returns a pointer to the memory area s.
/* #include <stdio.h>
int main(void)
{
	char	string[10] = "aaaaaaaaaa";
	printf("%s\n", (char*)ft_memset(string, 38, 7));
	printf("%s\n", (char*)memset(string, 38, 7));

	printf("%s\n", (char*)ft_memset(string, -38, 7));;
	printf("%s\n", (char*)memset(string, -38, 7));

//decided to use unsigned* instead of *char
// to handle memory operations safely
// with values for the than 255 or -n
// and not be misinterpreted and overflow
	int c = 511; // Example value
    printf("Original: %d, Cast to unsigned char: %u\n", c, (unsigned char)c);
    printf("Original: %d, Cast to char: %u\n", c, (char)c);
    printf("Original: %d, Cast without: %u\n", c, c);

	c = -38; // Example value
    printf("Original: %d, Cast to unsigned char: %u\n", c, (unsigned char)c);
    printf("Original: %d, Cast to char: %u\n", c, (char)c);
    printf("Original: %d, Cast without: %u\n", c, c);
} */
