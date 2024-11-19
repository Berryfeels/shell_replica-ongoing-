/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:19:27 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/07 23:34:41 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// The strdup() function allocates sufficient memory for a copy
// of the string s1,does the copy, and returns a pointer to it.
// The pointer may subsequently be used as an argument to the
// function free(3).If insufficient memory is available, NULL is
// returned and errno is set to ENOMEM.
char	*ft_strdup(const char *s1)
{
	int		ls;
	char	*ptr;
	char	*getlen;
	int		i;

	getlen = (char *) s1;
	ls = ft_strlen (getlen);
	ptr = (char *) malloc ((ls + 1) * sizeof(const char));
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < ls)
	{
		ptr[i] = s1[i];
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}
