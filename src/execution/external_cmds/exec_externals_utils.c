/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_externals_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 22:28:41 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/10 23:12:26 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_results(char **results)
{
	int	i;

	i = 0;
	while (results[i])
	{
		free(results[i++]);
	}
	free(results);
}

void	print_error(char *str, char *message, int err)
{
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	if (message)
		write(2, message, ft_strlen(message));
	if (err == 1)
		perror("");
}

int	check_access(char **path, t_cmd *cmd)
{
	if (access(*path, F_OK) == -1)
	{
		print_error(cmd->cmd, NULL, 1);
		return (127);
	}
	if (access(*path, X_OK) == -1)
	{
		print_error(cmd->cmd, NULL, 1);
		return (126);
	}
	return (0);
}

char	**cmd_str(t_cmd *cmd)
{
	char	**cmds;
	int		i;

	i = 0;
	while (cmd->args[i])
		i++;
	cmds = malloc (sizeof(char *) * (i + 2));
	if (cmds == NULL)
		return (NULL);
	cmds[0] = ft_strdup(cmd->cmd);
	i = 1;
	while (cmd->args[i - 1])
	{
		cmds[i] = ft_strdup(cmd->args[i - 1]);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

char	*ft_eiterate(char **path, char **envp_paths, char *cmd)
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
