/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:54:44 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/11/30 22:08:58 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc((count * size) * sizeof(size_t));
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}

//errno: integer variable set in the event of error,indicating what went wrong)
//will give ENOMEM: Not enough space/cannot allocate memory (POSIX.1-2001)
//calloc allocates memory for number of objects + their size.
// set bytes to 0 for the size of the buffer ( how many byteboxes to allocate)
//return pointer to allocated memory
