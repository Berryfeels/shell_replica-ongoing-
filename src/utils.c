/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:52:18 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/09/30 20:49:43 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	free_results(char **results)
{
	int	i;

	i = 0;
	while (results[i]) 
	{
		free(results[i++]);
	}
	free(results);
}

static char	*ft_eiterate(char **path, char **envp_paths, char *cmd)
{
	char	*add_slash;
	int		i;

	i = 0;
	while (envp_paths[i])
	{
		add_slash = ft_strjoin (envp_paths[i], "/");
		if (add_slash == NULL)
			return (NULL);
		(*path) = ft_strjoin (add_slash, cmd);
		if (*path == NULL)
			return (NULL);
		free(add_slash);
		if (access (*path, X_OK) == 0)
			return (*path);
		free(*path);
		i++;
	}
	return (NULL);
}

static char	*find_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*path;
	int		i;


	i = 0;
	while (envp[i] && ft_strnstr (envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i]) 
	{
		perror("PATH not found in environment variables");
		return (NULL);
	}
	envp_paths = ft_split (envp[i] + 5, ':');
	if (!envp_paths) 
	{
		perror ("Error: ft_split failed\n");
		return (NULL);
	}
	path = ft_eiterate(&path, envp_paths, cmd);
	free_results(envp_paths);
	if (path != NULL)
		return (path);
	return (0);
}

int	execute(char *cmd, char **envp)
{
	char	*path;

	if (!cmd) 
	{
		perror ("Error: ft_split failed\n");
		return (1);
	}
	path = find_path (cmd, envp);
	if (!path)
	{
		perror("Error, no path found");
		//free_results(cmd);
		return (1);
	}
	if (execve(path, &cmd, envp) == -1)
	{
		perror("Error at execve");
		return (1);
	}
	return (0);
}
