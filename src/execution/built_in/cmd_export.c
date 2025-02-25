/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:02:57 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/10 17:53:56 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	is_only_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool	valid_var_name(char *av)
{
	int	i;

	i = 0;
	if (av == NULL || av[0] == '\0' || av[0] == '=')
		return (false);
	while (av[i] != '\0')
	{
		if (av[i] == '=')
			break ;
		if (!ft_isalpha(av[i]) && av[i] != '_' && !ft_isdigit(av[i]))
			return (false);
		i++;
	}
	return (true);
}

void	add_var(t_node_list *node, char *av)
{
	int		i;
	bool	was_assigned;

	i = 0;
	was_assigned = false;
	while (av[i] != '\0')
	{
		if (av[i] == '=')
		{
			was_assigned = true;
			break ;
		}
		i++;
	}
	if (was_assigned)
	{
		ms_set_env(&(node->msh->ms_env), av);
		ms_set_env(&(node->msh->env_exp), av);
	}
	else
		ms_set_env(&(node->msh->env_exp), av);
}

void	verify_var(t_node_list *node, char *av)
{
	if (ft_strlen(av) <= 0)
	{
		print_exp_error(NULL);
		node->msh->exit_code = 1;
	}
	else if (is_only_spaces(av))
	{
		print_exp_error(av);
		node->msh->exit_code = 1;
	}
	else
	{
		if (!valid_var_name(av))
		{
			print_exp_error(av);
			node->msh->exit_code = 1;
		}
		else
			add_var(node, av);
	}
}

void	exec_export(char **av, t_node_list *node)
{
	int	i;

	if (av == NULL)
	{
		print_exported(node->msh->env_exp);
		node->msh->exit_code = 0;
	}
	else
	{
		i = 0;
		while (av[i])
		{
			if (av[i][0] == '=' ||
				(!ft_isalpha(av[i][0]) && ft_strlen(av[i]) > 1))
			{
				print_exp_error(av[i]);
				node->msh->exit_code = 1;
			}
			else
				verify_var(node, av[i]);
			i++;
		}
	}
}
