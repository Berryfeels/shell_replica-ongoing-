/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:25:47 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/19 18:17:45 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	exec_builtin_two(t_node_list *node_list, int *exit)
{
	if (ft_strcmp(node_list->cmd->cmd, "unset") == 0)
	{
		*exit = 0;
		exec_unset(node_list->cmd->args, node_list);
	}
	else if (ft_strcmp(node_list->cmd->cmd, "env") == 0)
	{
		*exit = 0;
		handle_env(node_list);
	}
	else if (ft_strcmp(node_list->cmd->cmd, "export") == 0)
	{
		*exit = 0;
		exec_export(node_list->cmd->args, node_list);
	}
}

int	exec_builtin(t_node_list	*node_list, t_exec *exec, int **pipes)
{
	int	exit;

	exit = 1;
	if (!node_list->cmd)
		return (exit);
	else if (ft_strcmp(node_list->cmd->cmd, "echo") == 0)
		exit = handle_echo(node_list);
	else if ((ft_strcmp(node_list->cmd->cmd, "cd")) == 0)
	{
		exit = 0;
		exec_cd(node_list);
	}
	else if (ft_strcmp(node_list->cmd->cmd, "exit") == 0)
	{
		exit = 0;
		exec_exit(node_list, exec, pipes);
	}
	else if (ft_strcmp(node_list->cmd->cmd, "pwd") == 0)
	{
		exit = 0;
		handle_pwd(node_list);
	}
	exec_builtin_two(node_list, &exit);
	return (exit);
}
