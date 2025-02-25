/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:27:08 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/06 17:36:14 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	handle_echo(t_node_list	*node)
{
	int	i;

	i = 0;
	if (node->cmd->args)
	{
		while (node->cmd->args[i])
		{
			if ((write(node->fd_out, node->cmd->args[i],
						ft_strlen(node->cmd->args[i])) == -1))
			{
				node->msh->exit_code = 1;
				perror("echo");
			}
			i++;
			if (node->cmd->args[i])
				write(1, " ", 1);
		}
	}
	if (!node->cmd->option_n)
		write(1, "\n", 1);
	return (0);
}
