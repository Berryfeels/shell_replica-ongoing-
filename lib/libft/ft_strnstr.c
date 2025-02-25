/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:32 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 14:23:52 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	int			s_len;
	char		*b;
	char		*l;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	b = (char *)big;
	l = (char *)little;
	s_len = ft_strlen(l);
	while (b[i] != '\0' && (i + s_len) <= len)
	{
		if (ft_strncmp((b + i), l, s_len) == 0)
		{
			return (b + i);
		}
		i++;
	}
	return (NULL);
}
/* #include <stdio.h>
int main(void) {
    const char *largestring;
    const char *smallstring;
    char *ptr;

    // Test 1: Finding a substring in the middle of the string within limits
    largestring = "Foo Bar Baz";
    smallstring = "Bar";
    ptr = ft_strnstr(largestring, smallstring, 8);
    printf("Test 1: %s\n", ptr ? ptr : "Not found");

    // Test 2: Substring beyond the search limit
    largestring = "Foo Bar Baz";
    smallstring = "Baz";
    ptr = ft_strnstr(largestring, smallstring, 8);
    printf("Test 2: %s\n", ptr ? ptr : "Not found");

    // Test 3: Empty 'little' string should return 'big'
    largestring = "Foo Bar Baz";
    smallstring = "";
    ptr = ft_strnstr(largestring, smallstring, 8);
    printf("Test 3: %s\n", ptr ? ptr : "Not found");

    return 0;
}
 */
