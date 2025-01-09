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

int	main(int ac, char **argv, char **envp)
{	
	(void)ac;
	(void)argv;
	int	fd;
	bld_in	*builtins;

	init_env(envp);
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}
	ft_dprintf("-------NEW LOG-------\n");
	builtins = create_builtin_list();
	shell_loop (builtins);
	free_builtin_list(builtins);
	close (fd);
	return 0;
}