/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:19:56 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/21 18:11:38 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	reset_in_out(int *stds_cpy)
{
	if (dup2(stds_cpy[0], STDIN_FILENO) == -1)
		return ;
	close(stds_cpy[0]);
	if (dup2(stds_cpy[1], STDOUT_FILENO) == -1)
		return ;
	close(stds_cpy[1]);
}

void	exec_cmd(t_node_list *node, int **pipes, t_exec *exec)
{
	int	exit_code;

	if (exec_builtin(node, exec, pipes) == 0)
	{
		rl_clear_history();
		close_pipes(pipes, exec->node_amount - 1);
		free_pipes(pipes, exec->node_amount - 1);
		free_msh(node->msh);
		free_node_list(node);
		free_exec(exec);
		exit(0);
	}
	exit_code = exec_external(node->cmd, node->msh);
	if (exit_code != 0)
	{
		rl_clear_history();
		close_pipes(pipes, exec->node_amount - 1);
		free_pipes(pipes, exec->node_amount - 1);
		free_msh(node->msh);
		free_node_list(node);
		free_exec(exec);
		exit(exit_code);
	}
}

int	handle_error_signal(int *exit_code, int *signal, int last_pid)
{
	pid_t	pid;
	int		wstatus;

	wstatus = 0;
	pid = waitpid(-1, &wstatus, 0);
	if (pid == last_pid)
	{
		if (WIFEXITED(wstatus))
			*exit_code = WEXITSTATUS(wstatus);
		else if (WIFSIGNALED(wstatus))
		{
			*signal = WTERMSIG(wstatus);
			return (*signal);
		}
	}
	return (0);
}

int	close_wait_free(int **pipes, int node_amount, int last_pid)
{
	int		exit_code;
	int		signal;
	int		j;
	int		main_pid;

	main_pid = getpid();
	exit_code = 0;
	signal = 0;
	if (pipes)
		close_pipes(pipes, node_amount - 1);
	if (last_pid != main_pid)
	{
		j = 0;
		while (j < node_amount)
		{
			signal = handle_error_signal(&exit_code, &signal, last_pid);
			if (signal > 0)
				return (signal);
			j++;
		}
	}
	if (pipes)
		free_pipes(pipes, node_amount - 1);
	return (exit_code);
}

int	count_nodes(t_node_list	*node_list)
{
	int	n;

	n = 0;
	while (node_list)
	{
		n++;
		node_list = node_list->next;
	}
	return (n);
}
