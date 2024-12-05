/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:41:50 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/09/12 21:09:19 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Parameters
// s1: The prefix string.
// s2: The suffix string.
// Return value
// The new string.
// NULL if the allocation fails.
// External functs. malloc (+ 1 for the NULL terminator)
// Description Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.
int	getlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	char	*sj;
	int		i;
	int		y;

	if (*s1 == '\0' && *s2 == '\0')
		return (NULL);
	ls1 = getlen(s1);
	ls2 = getlen(s2);
	sj = (char *)malloc((ls1 + ls2 + 1) * sizeof(char const));
	if (sj == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[y])
		sj[i++] = s1[y++];
	y = 0;
	while (s2[y])
		sj[i++] = s2[y++];
	return (sj);
}

// #include <stdio.h>

// int main(void)
// {
//     // Test Case 1
//     char *s1 = "Hello, ";
//     char *s2 = "world!";
//     char *result1 = ft_strjoin(s1, s2);
//     printf("Test Case 1: %s\n", result1);
//     free(result1);

//     // Test Case 2
//     char *s3 = "";
//     char *s4 = "Concatenate me!";
//     char *result2 = ft_strjoin(s3, s4);
//     printf("Test Case 2: %s\n", result2);
//     free(result2);

//     // Test Case 3
//     char *s5 = "No";
//     char *s6 = "Space";
//     char *result3 = ft_strjoin(s5, s6);
//     printf("Test Case 3: %s\n", result3);
//     free(result3);

//     // Test Case 4
//     char *s7 = "Empty";
//     char *s8 = "";
//     char *result4 = ft_strjoin(s7, s8);
//     printf("Test Case 4: %s\n", result4);
//     free(result4);

//     // Test Case 5
//     char *s9 = "";
//     char *s10 = "";
//     char *result5 = ft_strjoin(s9, s10);
//     printf("Test Case 5: %s\n", result5);
//     free(result5);

//     return 0;
// }
