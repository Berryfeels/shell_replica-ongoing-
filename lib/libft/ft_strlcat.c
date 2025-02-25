/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:20 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 14:39:35 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_i;
	size_t	s_i;

	d_i = 0;
	s_i = 0;
	while (dst[d_i] && d_i < size)
		d_i++;
	while ((src[s_i] != '\0') && ((d_i + s_i + 1) < size))
	{
		dst[d_i + s_i] = src[s_i];
		s_i++;
	}
	if (d_i != size)
		dst[d_i + s_i] = '\0';
	return (d_i + ft_strlen(src));
}
/* #include <stdio.h>
#include <string.h>
int	main(void)
{
   char buffer1[20] = "Hello";
    char buffer2[20] = "Hello";
    char buffer3[20] = "Hello";

    // Test 1: Concatenate with ample space
    ft_strlcat(buffer1, " world!", sizeof(buffer1));
    printf("Test 1: %s\n", buffer1);  // Expected output: "Hello world!"

    // Test 2: Concatenate with exactly fitting space
    ft_strlcat(buffer2, " world!", 12);
    printf("Test 2: %s\n", buffer2);  // Expected output: "Hello world!"

    // Test 3: Concatenate with not enough space for the full string
    ft_strlcat(buffer3, " world!", 10);
    printf("Test 3: %s\n", buffer3);  // Expected output: "Hello wor"

    return 0;
} */
