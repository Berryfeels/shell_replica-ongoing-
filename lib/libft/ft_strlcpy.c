/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:24 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 13:50:54 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}
/* #include <stdio.h>
int main(void) {
   char dest1[20];
    char dest2[10];
    char dest3[5];
    char dest4[1];
    size_t ret; // Variable to store return value

    // Test 1
    ret = ft_strlcpy(dest1, "Hello, World!", sizeof(dest1));
    printf("Test 1: %s (Source Length: %zu)\n", dest1, ret);

    // Test 2
    ret = ft_strlcpy(dest2, "123456789", sizeof(dest2));
    printf("Test 2: %s (Source Length: %zu)\n", dest2, ret);

    // Test 3
    ret = ft_strlcpy(dest3, "Hello, World!", sizeof(dest3));
    printf("Test 3: %s (Source Length: %zu)\n", dest3, ret);

    // Test 4
    ret = ft_strlcpy(dest4, "Hello, World!", sizeof(dest4));
    printf("Test 4: %s (Source Length: %zu)\n", dest4, ret);

    // Test 5
    ret = ft_strlcpy(dest1, "", sizeof(dest1));
    printf("Test 5: %s (Source Length: %zu)\n", dest1, ret);

    // Test 6
    char unchanged[] = "Unchanged!";
    ret = ft_strlcpy(unchanged, "Hello, World!", 0);
    printf("Test 6: %s (Source Length: %zu)\n", unchanged, ret);

    return 0;
}
 */
