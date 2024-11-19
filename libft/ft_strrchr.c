/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:00:37 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/30 21:00:43 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		ls;
	char	*getsize;

	getsize = (char *)s;
	ls = ft_strlen(getsize);
	if (c == '\0')
		return ((char *) &s[ls + 1]);
	while (ls >= 0)
	{
		if (s[ls] == (char) c)
			return ((char *) &s[ls]);
		ls --;
	}
	return (NULL);
}
