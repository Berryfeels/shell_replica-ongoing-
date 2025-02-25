/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:04:26 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/23 12:27:01 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	redir_out_append(t_node_list *node, t_redir *redir)
{
	ft_dprintf("set redir OUT\n");
	if (redir->type == REDIR_OUT)
		redir->fd = open(redir->target, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (node->redir->type == APPEND)
		redir->fd = open(redir->target, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (redir->fd == -1)
	{
		perror("open");
		node->msh->exit_code = 1;
		return (-1);
	}
	if (dup2(redir->fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		node->msh->exit_code = 1;
		close(redir->fd);
		return (-1);
	}
	close(redir->fd);
	return (0);
}

int	redir_in(t_node_list *node)
{
	ft_dprintf("set redir IN\n");
	node->redir->fd = open(node->redir->target, O_RDONLY, 0777);
	if (node->redir->fd == -1)
	{
		perror("open");
		node->msh->exit_code = 1;
		return (-1);
	}
	if (dup2(node->redir->fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		node->msh->exit_code = 1;
		close(node->redir->fd);
		return (-1);
	}
	close(node->redir->fd);
	return (0);
}

int	exec_redir(t_node_list *node)
{
	if (node->redir->type == REDIR_IN)
	{
		if (redir_in(node) == -1)
			return (-1);
	}
	if (node->redir->type == REDIR_OUT || node->redir->type == APPEND)
	{
		if (redir_out_append(node, node->redir) == -1)
			return (-1);
	}
	return (0);
}

int	set_redirection(t_node_list *node)
{
	t_redir	*temp;

	temp = node->redir;
	while (node->redir)
	{
		if (exec_redir(node) == -1)
			return (-1);
		temp = node->redir;
		node->redir = node->redir->next;
		free(temp->target);
		free(temp);
	}
	return (0);
}

int	exec_node_redir(t_node_list *head, int **pipes,
	int *heredoc_pipe, t_exec *exec)
{
	handle_heredoc(head, heredoc_pipe, exec);
	if (set_redirection(head) == -1)
	{
		if (heredoc_pipe[0] != -1)
			close(heredoc_pipe[0]);
		free_pipes(pipes, exec->node_amount - 1);
		reset_in_out(exec->stds_cpy);
		return (-1);
	}
	return (0);
}
