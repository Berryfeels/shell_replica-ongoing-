/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:27:49 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/07 19:41:27 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parameters
// n: The integer to output.
// fd: The file descriptor on which to write.
// Return value
// None
// External functs.
// write
// Description
// Outputs the integer ’n’ to the given file
// descriptor. Basically n id the file that will be labeled to fd.
// when you call write(fd, &c, sizeof(char)), you are saying:
// "Write the content of the memory location pointed to by &c
// (which is the address of the char variable c) to the file or
// resource identified by the file descriptor fd."

void	ft_putnbr_fd(int n, int fd)
{
	long int	lnb;

	lnb = n;
	if (lnb < 0)
	{
		write (1, "-", 1);
		lnb *= -1;
	}
	if (lnb > 9)
	{
		ft_putnbr_fd(lnb / 10, fd);
		ft_putnbr_fd(lnb % 10, fd);
	}
	else if (lnb < 10)
	{
		lnb += 48;
		write (fd, &lnb, 1);
	}
}
