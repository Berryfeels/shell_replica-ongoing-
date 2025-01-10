/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:46:16 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/30 21:43:51 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i ++;
	}
	return (0);
}
// #include "libft.h"
// #include <stdio.h>

// int main(void)
// {
//     // Test Case 1
//     printf("Test Case 1: %d\n", ft_strncmp("abc", "abc", 3));

//     // Test Case 2
//     printf("Test Case 2: %d\n", ft_strncmp("abc", "abc", 5));

//     // Test Case 3
//     printf("Test Case 3: %d\n", ft_strncmp("abc", "abd", 3));

//     // Test Case 4
//     printf("Test Case 4: %d\n", ft_strncmp("abc", "abd", 5));

//     // Test Case 5
//     printf("Test Case 5: %d\n", ft_strncmp("Abc", "abc", 3));

//     // Test Case 6
//     printf("Test Case 6: %d\n", ft_strncmp("Sbc", "abc", 5));

//     // Test Case 7
//     printf("Test Case 7: %d\n", ft_strncmp("abc\0def", "abc\0ghi", 7));

//     // Test Case 8
//     printf("Test Case 8: %d\n", ft_strncmp("abzzdef", "abdghi", 7));

//     // Test Case 9
//     printf("Test Case 9: %d\n", ft_strncmp("abc\0def", "abc\0ghi", 10));

//     // Test Case 10
//     printf("Test Case 10: %d\n", ft_strncmp("abc\0def", "abd\0ghi", 10));

//     return 0;
// }
