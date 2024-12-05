/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:54:54 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/28 19:43:58 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*strcpy;

	strcpy = (unsigned char *)str;
	while (n > 0)
	{
		*strcpy++ = (unsigned char)c;
		n --;
	}
	return (str);
}
