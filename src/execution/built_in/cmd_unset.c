/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:43:11 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/10 16:40:25 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	find_env_index(char **env, char *var)
{
	int		i;
	char	**split;

	i = 0;
	while (env[i])
	{
		split = ft_split(env[i], '=');
		if (ft_strcmp(split[0], var) == 0)
		{
			ft_free_tab(split);
			return (i);
		}
		ft_free_tab(split);
		i++;
	}
	return (-1);
}

int	ms_remove_line(char ***env, int index)
{
	int		i;
	int		j;
	char	**new_matrix;

	i = 0;
	while ((*env)[i])
		i++;
	new_matrix = malloc(sizeof(char *) * i);
	if (!new_matrix)
		return (1);
	i = 0;
	j = 0;
	while ((*env)[i])
	{
		if (i != index)
		{
			new_matrix[j] = ft_strdup((*env)[i]);
			j++;
		}
		i++;
	}
	new_matrix[j] = NULL;
	ft_free_tab(*env);
	*env = new_matrix;
	return (0);
}

void	remove_env(char *var, t_node_list *node)
{
	int	index_env;
	int	index_exp;

	index_env = find_env_index(node->msh->ms_env, var);
	if (index_env != -1)
		ms_remove_line(&(node->msh->ms_env), index_env);
	index_exp = find_env_index(node->msh->env_exp, var);
	if (index_exp != -1)
		ms_remove_line(&(node->msh->env_exp), index_exp);
}

void	exec_unset(char **av, t_node_list *node)
{
	int	i;

	i = 0;
	if (node->cmd->args)
	{
		while (node->cmd->args[i])
		{
			remove_env(av[i], node);
			i++;
		}
	}
}
