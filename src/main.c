/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:01:45 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/04 15:33:26 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_openErrorScan(void)
{
	int fd;
	
	fd = open ("ErrorScan.txt", O_RDWR, O_CREAT, 0777);
	if (fd == -1)
		close (fd);
	exit (EXIT_ERROR);
}



int	main()
{	
	int	fd;
	bld_in	*builtins;
	int fd_error;

    fd_error = open("Error_log.txt", O_RDWR | O_CREAT | O_APPEND, 0777);
    if (fd_error < 0)
    {
        perror("Failed to open error log file");
        return 1;
    }
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}
	ft_dprintf(fd_error, "-----ERROR LOG-----\n");
	builtins = create_builtin_list();
	shell_loop (builtins);
	free_builtin_list(builtins);
	close(fd);
	close(fd_error);
	return 0;
}
