/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:54:49 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/23 19:49:42 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_child(t_node_list *node, int **pipes,
	t_exec *exec, int *heredoc_pipe)
{
	if (pipes)
		set_pipe_ends(pipes, node->node_i, exec->node_amount - 1);
	if (node->redir)
	{
		if (set_redirection(node) == -1)
			clean_exit(exec, pipes, node, 1);
	}
	if (heredoc_pipe[0] != -1)
	{
		close(heredoc_pipe[1]);
		dup2(heredoc_pipe[0], STDIN_FILENO);
		close(heredoc_pipe[0]);
	}
	if (node->cmd != NULL)
		exec_cmd(node, pipes, exec);
	clean_exit(exec, pipes, node, 2);
}

int	fork_child(t_node_list *node, int **pipes, t_exec *exec)
{
	pid_t	pid;
	int		heredoc_pipe[2];

	heredoc_pipe[0] = -1;
	if (node->redir)
		handle_heredoc(node, heredoc_pipe, exec);
	if (g_sig == SIGINT)
		heredoc_pipe[0] = -1;
	pid = fork();
	run_signals(2, node->msh);
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		exec_child(node, pipes, exec, heredoc_pipe);
	}
	return (pid);
}

int	single_node(t_node_list *head, int **pipes, t_exec *exec)
{
	int	heredoc_pipe[2];

	heredoc_pipe[0] = -1;
	if (exec->node_amount == 1 && find_builtin(head) == 0)
	{
		if (head->redir)
		{
			if (exec_node_redir(head, pipes, heredoc_pipe, exec) == -1)
				return (-1);
		}
		if ((exec_builtin(head, exec, pipes)) == 0)
		{
			if (heredoc_pipe[0] != -1)
				close(heredoc_pipe[0]);
			free_pipes(pipes, exec->node_amount - 1);
			reset_in_out(exec->stds_cpy);
		}
		else if (head->cmd && find_builtin(head) == 1)
		{
			return (2);
		}
		return (0);
	}
	return (1);
}

void	exec_node(t_node_list *node, t_exec *exec, int **pipes)
{
	t_node_list	*temp;
	int			exit;

	temp = NULL;
	exit = 0;
	while (node)
	{
		temp = node;
		exit = single_node(node, pipes, exec);
		if (exit == -1 || exit == 0)
		{
			clean_exec_node(temp);
			break ;
		}
		exec->last_pid = fork_child(node, pipes, exec);
		if (exec->last_pid == -1)
		{
			clean_exec_node(temp);
			break ;
		}
		node = node->next;
		clean_exec_node(temp);
	}
}

void	exec_node_list(t_node_list *node)
{
	t_exec		*exec;
	int			**pipes;

	exec = NULL;
	if (set_and_init(node, &exec, &pipes) == 1)
		return ;
	exec_node(node, exec, pipes);
	close_execution(exec, pipes);
	free_exec(exec);
}
