/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:43:46 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 14:12:06 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // PASSES

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*together;
	unsigned int	total_size;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	together = (char *)malloc(sizeof(char) * total_size + 1);
	if (!together)
		return (NULL);
	while (s1[i] != '\0')
		together[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		together[j++] = s2[i++];
	together[j] = '\0';
	return (together);
}
/* #include<stdio.h>
int main(void) {
    char *result;

    // Test 1: Join two normal strings
    result = ft_strjoin("Hello", " world!");
    printf("Test 1: %s\n", result);
    free(result);  // Remember to free after usage to avoid memory leaks

    // Test 2: Join first string empty
    result = ft_strjoin("", " world!");
    printf("Test 2: %s\n", result);
    free(result);

    // Test 3: Join second string empty
    result = ft_strjoin("Hello", "");
    printf("Test 3: %s\n", result);
    free(result);

    return 0;
} */
