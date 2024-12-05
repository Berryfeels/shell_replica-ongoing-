/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:51:23 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/05 19:34:07 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Parameters
// s: The string on which to iterate.
// f: The function to apply to each character.
// Return value
// The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.
// External functs. malloc
// Description
// Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

static int	getlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!(s))
		return (NULL);
	str = (char *)malloc(((getlen(s)) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f (i, s[i]);
		i ++;
	}
	str[i + 1] = '\0';
	return (str);
}
