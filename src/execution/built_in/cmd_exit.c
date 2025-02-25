/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:22:54 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/25 13:40:55 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	is_non_numeric(char *av)
{
	bool		spaces;
	int			i;

	i = 0;
	spaces = true;
	while (av[i] == ' ')
		i++;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		else if (ft_isdigit(av[i]))
			spaces = false;
		else if (!ft_isdigit(av[i]))
			return (true);
		i++;
	}
	if (spaces)
		return (true);
	return (false);
}

bool	invalid_exit(char **av, t_msh *msh)
{
	long long	exit_code;

	if (av[0][0] == '\0')
	{
		write(2, "exit: numeric argument required\n", 32);
		msh->exit_code = 2;
		return (true);
	}
	if (is_non_numeric(av[0]))
	{
		write(2, "exit: numeric argument required\n", 32);
		msh->exit_code = 2;
		return (true);
	}
	exit_code = ft_atoll(av[0]);
	if (ft_isllong(av[0]) != 0
		|| exit_code < LLONG_MIN || exit_code > LLONG_MAX)
	{
		write(2, "exit: numeric argument required\n", 32);
		msh->exit_code = 255;
		return (true);
	}
	msh->exit_code = exit_code % 256;
	return (false);
}

int	check_exit(t_msh *msh, char **av)
{
	int	i;

	i = 0;
	if (av[1])
	{
		while (av[0][i] != '\0')
		{
			if (ft_isdigit(av[0][i]))
			{
				write(2, "exit: too many arguments\n", 25);
				msh->exit_code = 1;
				return (-1);
			}
			i++;
		}
	}
	if (invalid_exit(av, msh))
		return (1);
	if (msh->exit_code < 0)
		msh->exit_code += 256;
	return (0);
}

int	exec_exit(t_node_list *node, t_exec *exec, int **pipes)
{
	int	exit_code;

	exit_code = 0;
	if (node->cmd->args)
		exit_code = check_exit(node->msh, node->cmd->args);
	if (exit_code == -1)
		return (1);
	exit_code = node->msh->prev_exit;
	rl_clear_history();
	close_pipes(pipes, exec->node_amount - 1);
	free_pipes(pipes, exec->node_amount - 1);
	free_msh(node->msh);
	free_exec(exec);
	free_node_list(node);
	exit(exit_code);
}
