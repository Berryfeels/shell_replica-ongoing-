/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:26:26 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/10 21:43:18 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	set_pwd(char *av, char *c, t_node_list *node)
{
	char	*string;

	string = ft_strjoin(av, c);
	ms_set_env (&(node->msh->ms_env), string);
	free (string);
}

bool	move_to_dir(char *avs, t_node_list *node)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	if (chdir(avs) == -1)
	{
		if (avs[0] == '\0')
			return (1);
		ft_putstr_fd ("cd: ", 2);
		ft_putstr_fd (avs, 2);
		ft_putendl_fd (": No such file or directory", 2);
		node->msh->exit_code = 1;
		return (false);
	}
	set_pwd ("OLDPWD=", cwd, node);
	getcwd(cwd, sizeof(cwd));
	set_pwd("PWD=", cwd, node);
	return (true);
}

bool	cd_has_more_args(t_node_list *node)
{
	int	i;

	i = 0;
	while (node->cmd->args[i] != NULL)
		i++;
	if (i > 1)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		node->msh->exit_code = 1;
		return (true);
	}
	return (false);
}

int	exec_cd(t_node_list *node)
{
	char	*avs;

	avs = NULL;
	if (!node->cmd->args)
	{
		avs = ms_get_env (node->msh->ms_env, "HOME") + 5;
		if ((avs - 5) == NULL)
		{
			printf ("cd: HOME not set\n");
			return (1);
		}
	}
	else
	{
		if (cd_has_more_args(node))
			return (1);
		avs = node->cmd->args[0];
	}
	if (ft_strlen(avs) == 1 && avs[0] == '~')
		avs = node->msh->home_path;
	if (!move_to_dir(avs, node))
		return (1);
	return (0);
}
