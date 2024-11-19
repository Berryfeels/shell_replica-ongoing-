/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:39:54 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/08 00:43:10 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parameters
// s: The string from which to create the substring.
// start: The start index of the substring in the string ’s’.
// len: The maximum length of the substring.

// Return value
// The substring.
// NULL if the allocation fails.

// External functs. malloc

// Description
// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (*s == '\0')
		return (NULL);
	subs = ft_strdup(s);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		subs[i] = s[start + i];
		i ++;
	}
	subs[i] = '\0';
	return (subs);
}

// #include <stdio.h>

// int main(void)
// {
//     // Test Case 1
//     char *str1 = "Hello, World!";
//     char *result1 = ft_substr(str1, 7, 5);
//     printf("Test Case 1: %s\n", result1);
//     free(result1);

//     // Test Case 2
//     char *str2 = "This is a substring!";
//     char *result2 = ft_substr(str2, 5, 10);
//     printf("Test Case 2: %s\n", result2);
//     free(result2);

//     // Test Case 3
//     char *str3 = "Testing";
//     char *result3 = ft_substr(str3, 2, 8);
//     printf("Test Case 3: %s\n", result3);
//     free(result3);

//     // Test Case 4
//     char *str4 = "12345";
//     char *result4 = ft_substr(str4, 0, 3);
//     printf("Test Case 4: %s\n", result4);
//     free(result4);

//     return 0;
// }
