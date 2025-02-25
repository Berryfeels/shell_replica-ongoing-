/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:48:12 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/10 16:26:07 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

int	env_compare(char **env, char **av, int i)
{
	char	**split;

	while (env[i])
	{
		split = ft_split(env[i], '=');
		if (ft_strcmp(split[0], av[0]) == 0)
		{
			ft_free_tab(split);
			break ;
		}
		ft_free_tab(split);
		i++;
	}
	return (i);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ms_get_varenv(char **env, char *av)
{
	int		i;
	char	**split;
	char	*var_env;

	i = 0;
	var_env = NULL;
	while (env[i] && !var_env)
	{
		split = ft_split(env[i], '=');
		if (ft_strcmp(split[0], av) == 0)
			var_env = ft_strdup(split[1]);
		else
			i++;
		ft_free_tab(split);
	}
	if (env[i] == NULL)
		return (NULL);
	return (var_env);
}

char	**ms_matrix_add_line(char **matrix, char *new_line)
{
	int		i;
	char	**new_matrix;

	i = 0;
	while (matrix[i])
		i++;
	new_matrix = malloc(sizeof(char *) * (i + 2));
	if (!new_matrix)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i] = ft_strdup(new_line);
	i++;
	new_matrix[i] = NULL;
	ft_free_tab(matrix);
	return (new_matrix);
}

char	*ms_get_env(char **env, char *av)
{
	int		i;
	char	**split;

	i = 0;
	while (env[i])
	{
		split = ft_split(env[i], '=');
		if (ft_strcmp(split[0], av) == 0)
		{
			ft_free_tab(split);
			break ;
		}
		i++;
		ft_free_tab(split);
	}
	if (env[i] == NULL)
		return (NULL);
	return (env[i]);
}
