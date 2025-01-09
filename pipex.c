/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:51:44 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/09/13 17:33:03 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_close_wait(pid_t p1, pid_t p2, int *pipe_end)
{
	close (pipe_end[1]);
	close (pipe_end[0]);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
}

static int	ft_write_end_process(char **argv, int *pipe_end, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Error");
		return (1);
	}
	dup2 (fd, STDIN_FILENO);
	close (fd);
	dup2(pipe_end[1], STDOUT_FILENO);
	close (pipe_end[1]);
	close(pipe_end[0]);
	execute(argv[2], envp);
	return (0);
}

static int	ft_read_end_process(char **argv, int *pipe_end, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); 
	if (fd == -1)
	{
		perror("Error");
		return (1);
	}
	dup2 (pipe_end[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipe_end[0]);
	close(pipe_end[1]);
	execute(argv[3], envp);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_end[2];
	pid_t	p1;
	pid_t	p2;

	if (argc == 5)
	{
		if (pipe(pipe_end) == -1)
			return (1);
		p1 = fork();
		if (p1 < 0)
			return (2);
		if (p1 == 0)
			ft_write_end_process(argv, pipe_end, envp);
		p2 = fork();
		if (p2 < 0)
			return (3);
		if (p2 == 0)
			ft_read_end_process(argv, pipe_end, envp);
		ft_close_wait(p1, p2, pipe_end);
	}
	else
		ft_printf("Error, no right nr. of args\n");
	return (0);
}
