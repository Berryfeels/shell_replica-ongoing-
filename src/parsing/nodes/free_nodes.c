/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:57:51 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/21 11:08:23 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	free_msh(t_msh *msh)
{
	if (msh)
	{
		free_env(msh->ms_env);
		free_env(msh->env_exp);
		if (msh->home_path)
			free(msh->home_path);
		free(msh);
	}
}

void	free_redir_list(t_redir *head)
{
	t_redir	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		if (temp->target)
			free(temp->target);
		free(temp);
	}
	free(head);
}

void	free_cmd_struct(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		if (cmd->cmd)
			free(cmd->cmd);
		if (cmd->args)
		{
			while (cmd->args[i])
			{
				free(cmd->args[i]);
				i++;
			}
			free(cmd->args);
		}
		free(cmd);
	}
}

void	free_node_list(t_node_list *node_list)
{
	t_node_list	*temp;

	while (node_list)
	{
		temp = node_list;
		node_list = node_list->next;
		if (temp->cmd)
			free_cmd_struct(temp->cmd);
		if (temp->redir)
			free_redir_list(temp->redir);
		free(temp);
	}
}
