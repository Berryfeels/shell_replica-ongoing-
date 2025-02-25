/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:55:51 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/18 18:11:46 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_pipes(int **pipes, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	close_pipes(int **pipes, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	wait_pids(pid_t *pids, int n_pids)
{
	int	i;

	i = 0;
	while (i < n_pids)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}

int	**pipe_init(int n_pipes)
{
	int	**pipes;
	int	i;

	if (n_pipes == 0)
		return (NULL);
	i = 0;
	pipes = malloc(sizeof(int *) * (n_pipes));
	if (pipes == NULL)
		return (NULL);
	i = 0;
	while (i < n_pipes)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipes[i] == NULL || pipe(pipes[i]) == -1)
		{
			perror("pipe failed");
			while (--i >= 0)
				free(pipes[i]);
			free(pipes);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	set_pipe_ends(int **pipes, int position, int n_pipe)
{
	int	i;

	if (pipes)
	{
		if (position == 0)
			dup2(pipes[position][1], STDOUT_FILENO);
		else if (position == n_pipe)
			dup2(pipes[position - 1][0], STDIN_FILENO);
		else
		{
			dup2(pipes[position - 1][0], STDIN_FILENO);
			dup2(pipes[position][1], STDOUT_FILENO);
		}
		i = 0;
		while (i < n_pipe)
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
			i ++;
		}
	}
}
