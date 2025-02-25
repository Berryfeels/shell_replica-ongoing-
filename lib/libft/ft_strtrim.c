/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:43:56 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 14:43:48 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chara_is_found(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static unsigned int	find_start(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && chara_is_found(s1[i], set))
		i++;
	return (i);
}

static unsigned int	find_end(char const *s1, char const *set,
unsigned int start)
{
	unsigned int	i;

	i = ft_strlen(s1);
	while (i > start && chara_is_found(s1[i - 1], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*middle;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set, start);
	if (start == end)
	{
		middle = (char *)malloc(sizeof(char));
		if (middle)
			middle[0] = '\0';
	}
	else
	{
		middle = (char *)malloc(sizeof(char) * (end - start) + 1);
		if (!middle)
			return (NULL);
		ft_strlcpy(middle, s1 + start, end - start + 1);
	}
	return (middle);
}
/* #include "libft.h"
#include <stdio.h>

int main(void) {
    char *result;

    // Test 1: Standard trim
    result = ft_strtrim("xxxHello Worldxxx", "x");
    printf("Test 1: '%s'\n", result);
    free(result);  // Clean up heap allocation

    // Test 2: Characters to trim are not at the ends
    result = ft_strtrim("Hello World", "x");
    printf("Test 2: '%s'\n", result);
    free(result);

    // Test 3: Empty string and non-empty set
    result = ft_strtrim("", "xyz");
    printf("Test 3: '%s'\n", result);
    free(result);
	//test4:
	printf("%s\n", ft_strtrim("xxxz  test with
	x and z and x .  zx  xx z", "z x"));
    return 0;
} */
