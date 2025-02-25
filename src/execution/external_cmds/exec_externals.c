/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_externals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:52:18 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/21 18:00:35 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	checkandexec(char **path, char ***cmds, t_msh *msh, t_cmd *cmd)
{
	int			exit_code_access;
	struct stat	sb;

	if (!*path)
	{
		print_error(cmd->cmd, "command not found\n", 0);
		free_results(*cmds);
		return (127);
	}
	if (stat(*path, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		print_error(cmd->cmd, "Is a directory\n", 0);
		free(*path);
		return (126);
	}
	exit_code_access = check_access(path, cmd);
	if (exit_code_access != 0)
		return (exit_code_access);
	if (execve(*path, *cmds, msh->ms_env) == -1)
	{
		print_error(cmd->cmd, NULL, 1);
		return (127);
	}
	return (1);
}

char	*find_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr (envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	envp_paths = ft_split (envp[i] + 5, ':');
	if (!envp_paths)
		return (NULL);
	path = ft_eiterate(&path, envp_paths, cmd);
	free_results(envp_paths);
	if (path != NULL)
		return (path);
	return (NULL);
}

char	**get_cmds(t_cmd *cmd)
{
	char	**cmds;

	cmds = NULL;
	if (cmd->args)
		cmds = cmd_str(cmd);
	else
	{
		cmds = malloc(sizeof(char *) * 2);
		if (cmds == NULL)
			return (NULL);
		cmds[0] = ft_strdup(cmd->cmd);
		cmds[1] = NULL;
	}
	return (cmds);
}

int	exec_external(t_cmd *cmd, t_msh *msh)
{
	char	**cmds;
	char	*path;
	int		exit_code;

	cmds = get_cmds(cmd);
	if (!cmds)
	{
		return (1);
	}
	if (ft_strchr(cmds[0], '/') != NULL)
		path = cmds[0];
	else
		path = find_path (cmds[0], msh->ms_env);
	exit_code = checkandexec(&path, &cmds, msh, cmd);
	return (exit_code);
}
