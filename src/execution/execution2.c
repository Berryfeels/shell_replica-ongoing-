/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:31:51 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/23 12:28:54 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clean_exit(t_exec *exec, int **pipes, t_node_list *node, int flag)
{
	if (flag == 1)
	{
		exec->msh->exit_code = 1;
		rl_clear_history();
		close_pipes(pipes, exec->node_amount - 1);
		free_pipes(pipes, exec->node_amount - 1);
		free_msh(node->msh);
		free_node_list(node);
		free_exec(exec);
		exit(-1);
	}
	if (flag == 2)
	{
		rl_clear_history();
		close_pipes(pipes, exec->node_amount - 1);
		free_pipes(pipes, exec->node_amount - 1);
		free_msh(node->msh);
		free_redir_list(node->redir);
		free_node_list(node);
		free_exec(exec);
		exit(0);
	}
}

int	set_and_init(t_node_list *node_list, t_exec **exec, int ***pipes)
{
	*exec = malloc(sizeof(t_exec));
	if (!*exec)
		return (node_list->msh->exit_code = 1);
	(*exec)->msh = node_list->msh;
	(*exec)->exit_code = 0;
	(*exec)->last_pid = 0;
	(*exec)->node_amount = count_nodes(node_list);
	(*exec)->stds_cpy[0] = dup(STDIN_FILENO);
	(*exec)->stds_cpy[1] = dup(STDOUT_FILENO);
	if ((*exec)->stds_cpy[0] == -1 || (*exec)->stds_cpy[1] == -1)
		return (node_list->msh->exit_code = 1);
	if ((*exec)->node_amount > 1)
	{
		*pipes = pipe_init((*exec)->node_amount - 1);
		if (*pipes == NULL)
			return (node_list->msh->exit_code = 1);
	}
	else
		*pipes = NULL;
	return (0);
}

void	clean_exec_node(t_node_list *temp)
{
	free_cmd_struct(temp->cmd);
	free_redir_list(temp->redir);
	free(temp);
}

void	close_execution(t_exec *exec, int **pipes)
{
	reset_in_out(exec->stds_cpy);
	exec->exit_code = close_wait_free(pipes, exec->node_amount, exec->last_pid);
	if (exec->exit_code == 255)
		exec->msh->exit_code = 1;
	else if (exec->exit_code == 13)
		exec->msh->exit_code = 0;
	else if (exec->exit_code == 1 || exec->msh->exit_code == 1
		|| exec->msh->exit_code == -1)
		exec->msh->exit_code = 1;
	else
		exec->msh->exit_code = exec->exit_code;
}
