/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:24:09 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/05 18:30:44 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
// Parameters
// s: The string to output.
// fd: The file descriptor on which to write.
// Return value
// None
// External functs.
// write
// Description
// Outputs the string ’s’ to the given file descriptor
// followed by a newline.

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}
