/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:44:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/01/21 13:09:18 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*alloc_word(const char *start, int len)
{
	char	*word;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static void	*ft_freeresult(char **result, size_t w_i)
{
	while (w_i > 0)
		free (result[--w_i]);
	free (result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	const char	*w_start;
	size_t		w_i;

	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	w_i = 0;
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		w_start = s;
		while (*s && *s != c)
			s++;
		if (s > w_start)
		{
			result[w_i] = alloc_word(w_start, s - w_start);
			if (!result[w_i])
				return (ft_freeresult(result, w_i));
			w_i++;
		}
	}
	result[w_i] = NULL;
	return (result);
}
/* #include <stdio.h>
void print_result(char **result) {
    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("'%s'\n", result[i]);
            free(result[i]);  // Free each string after printing
        }
        free(result);  // Finally free the result array
    }
}
int main(void) {
    char **result;

    // Test 1: Basic functionality
    result = ft_split("hello world here", ' ');
    printf("Test 1:\n");
    print_result(result);

    // Test 2: Delimiter at the start and end
    result = ft_split(" test split case ", ' ');
    printf("Test 2:\n");
    print_result(result);

    // Test 3: Consecutive delimiters
    result = ft_split("hello  world  here", ' ');
    printf("Test 3:\n");
    print_result(result);

    return 0;
} */
