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

#include "../../include/minishell.h"


//token_redirection is the variable the user wants to redirect to

int	redir_out(char *token_redirection)
{
	int	fd;

	fd = open(token_redirection, O_WRONLY | O_CREAT | O_TRUNC, 0777); 
	if (fd == -1)
	{
		perror("Error");
		return (EXIT_ERROR);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	redir_doubleout(char *token_redirection)
{
	int	fd;

	fd = open(token_redirection, O_WRONLY | O_CREAT | O_APPEND, 0644); 
	if (fd == -1)
	{
		perror("Error");
		return (EXIT_ERROR);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int redir_in(char *token_redirection)
{
	int	fd;

	fd = open(token_redirection, O_RDONLY | O_CREAT | O_TRUNC, 0644); 
	if (fd == -1)
	{
		perror("Error");
		return (EXIT_ERROR);
	}
	dup2 (fd, STDIN_FILENO);
	close(fd);

	return (EXIT_SUCCESS);
}

// int here_doc()
// {

// }
