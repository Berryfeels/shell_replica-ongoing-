/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:57:17 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/21 18:02:12 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_builtin(t_node_list	*node)
{
	if (!node->cmd)
		return (1);
	if (ft_strcmp(node->cmd->cmd, "cd") == 0)
		return (0);
	else if (ft_strcmp(node->cmd->cmd, "env") == 0)
		return (0);
	else if (ft_strcmp(node->cmd->cmd, "echo") == 0)
		return (0);
	else if (ft_strcmp(node->cmd->cmd, "exit") == 0)
		return (0);
	else if (ft_strcmp(node->cmd->cmd, "export") == 0)
		return (0);
	else if (ft_strcmp(node->cmd->cmd, "pwd") == 0)
		return (0);
	else if (ft_strcmp(node->cmd->cmd, "unset") == 0)
		return (0);
	return (1);
}

int	check_cmds(t_node_list *node_list)
{
	t_node_list	*node;

	node = node_list;
	while (node)
	{
		if (node->cmd)
		{
			if (find_builtin(node) == 1 && find_ext_cmd(node) == 1)
			{
				printf("%s: command not found\n", node->cmd->cmd);
				node_list->msh->exit_code = 1;
				return (1);
			}
		}
		node = node->next;
	}
	return (0);
}

int	find_ext_cmd(t_node_list *node)
{
	char	*path;

	path = find_path(node->cmd->cmd, node->msh->ms_env);
	if (path == NULL)
		return (1);
	free(path);
	return (0);
}

void	free_exec(t_exec *exec)
{
	if (exec)
	{
		close(exec->stds_cpy[0]);
		close(exec->stds_cpy[1]);
		free(exec->stds_cpy);
	}
}
