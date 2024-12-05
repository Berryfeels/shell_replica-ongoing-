/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:31:19 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/05 18:37:07 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Parameters
// s: The string to output.
// fd: The file descriptor on which to write.
// Return value
// None
// External functs.
// write
// Description
// Outputs the string ’s’ to the given file
// descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
