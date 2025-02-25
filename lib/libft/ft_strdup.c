/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:59:20 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 14:05:34 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;

	duplicate = (char *)malloc(ft_strlen(s) + 1);
	if (!duplicate)
		return (0);
	ft_memcpy(duplicate, s, ft_strlen(s) + 1);
	return (duplicate);
}
/* #include <stdio.h>
int main(void)
{
// we have to copy each byte
// from src to dst, does not handle
// overlaps
	char	string1[12] = "Hello world";
	printf("%s\n", (char*)ft_strdup(string1));
	// printf("%s\n", (char*)strdup(string1, string2, 5));

	char	string2[0];
	printf("%s\n", (char*)ft_strdup(string2));
	// printf("%s\n", (char*)strdup(string3, string4, ft_strlen(string4)));
} */
