/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:46:57 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/10 16:23:09 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/minishell.h"

void	ms_set_env(char ***env, char *value)
{
	int		i;
	char	**av;

	i = 0;
	av = ft_split(value, '=');
	if (!av)
		return ;
	i = env_compare(*env, av, i);
	if ((*env)[i] == NULL)
		*env = ms_matrix_add_line(*env, value);
	else
	{
		free((*env)[i]);
		(*env)[i] = ft_strdup(value);
	}
	ft_free_tab(av);
}

bool	found_shlvl_value(char ***env, char **value)
{
	char	*var;

	var = ms_get_env(*env, "SHLVL");
	if (!var)
	{
		*env = ms_matrix_add_line(*env, "SHLVL=1");
		return (false);
	}
	*value = ms_get_varenv(*env, "SHLVL");
	if (!*value || ft_isdigit((*value)[0]) == 0)
	{
		printf("Warning: invalid SHLVL value. Resetting to 1\n");
		free(*value);
		*env = ms_matrix_add_line(*env, "SHLVL=1");
		return (false);
	}
	return (true);
}

void	check_shlvl(char ***env)
{
	char	*value;
	char	*new_var;
	int		shlvl;

	value = NULL;
	if (!found_shlvl_value(env, &value))
		return ;
	shlvl = ft_atoi(value);
	free(value);
	if (shlvl < 0)
		shlvl = 1;
	else
		shlvl++;
	value = ft_itoa(shlvl);
	new_var = ft_strjoin("SHLVL=", value);
	free(value);
	ms_set_env(env, new_var);
	free(new_var);
}

void	init_env_vars(char ***env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	*env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!*env)
	{
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (envp[i])
	{
		(*env)[i] = ft_strdup(envp[i]);
		i++;
	}
	(*env)[i] = NULL;
	check_shlvl(env);
}

void	ms_env_init(t_msh **msh, char **envp)
{
	if (!envp)
	{
		fprintf(stderr, "Error: env is NULL\n");
		exit(EXIT_FAILURE);
	}
	*msh = malloc(sizeof(t_msh));
	if (!*msh)
	{
		fprintf(stderr, "msh malloc failed\n");
		exit(EXIT_FAILURE);
	}
	(*msh)->exit_code = 0;
	(*msh)->prev_exit = 0;
	init_env_vars(&(*msh)->ms_env, envp);
	init_env_vars(&(*msh)->env_exp, envp);
}
