/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nodes_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:35:49 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/04 11:03:08 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_redir_file(t_redir *head)
{
	t_redir	*current;

	if (!head)
	{
		ft_dprintf(COLOR_BLUE"		- t_redir redir:"COLOR_RESET);
		ft_dprintf(" null\n");
		return ;
	}
	current = head;
	ft_dprintf(COLOR_BLUE"		- t_redir redir:\n"COLOR_RESET);
	while (current)
	{
		ft_dprintf(COLOR_CYAN"			");
		ft_dprintf("- REDIR N %d:\n"COLOR_RESET, current->redir_i + 1);
		ft_dprintf("			  ");
		ft_dprintf("- int type: %s\n", return_token_enum(current->type));
		ft_dprintf("			  ");
		ft_dprintf("- char *target: %s (%s)\n", current->target,
			return_token_enum(current->type));
		ft_dprintf("			  ");
		ft_dprintf("- int target_type: %s\n",
			return_target_enum(current->type));
		current = current->next;
	}
}

void	print_args_file(char **args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
	{
		ft_dprintf("			- char **args:");
		ft_dprintf(" null\n");
		return ;
	}
	ft_dprintf("			- char **args:\n");
	while (args[i])
	{
		ft_dprintf("				*arg[%d]: %s\n", i, args[i]);
		i++;
	}
}

void	print_null_cmd_file(void)
{
	ft_dprintf(COLOR_BLUE"		- t_cmd cmd: "COLOR_RESET);
	ft_dprintf("null\n");
	ft_dprintf("			- char **args:");
	ft_dprintf(" null\n");
	ft_dprintf(COLOR_YELLOW"			- bool option -n:"COLOR_RESET);
	ft_dprintf(" null\n");
}

void	print_cmd_struct_file(t_cmd *cmd)
{
	ft_dprintf(COLOR_BLUE"		- t_cmd cmd:\n"COLOR_RESET);
	ft_dprintf("			- char *cmd: %s\n", cmd->cmd);
	print_args_file(cmd->args);
	if (cmd->option_n)
	{
		ft_dprintf(COLOR_YELLOW"			- bool option -n:"COLOR_RESET);
		ft_dprintf(" true\n");
	}
	if (!cmd->option_n)
	{
		ft_dprintf(COLOR_YELLOW"			- bool option -n:"COLOR_RESET);
		ft_dprintf(" false\n");
	}
}

void	print_exit_codes_file(t_msh	*msh)
{
	ft_dprintf(COLOR_BLUE"		- node->msh: \n"COLOR_RESET);
	ft_dprintf("			- exit_code: ");
	ft_dprintf("%d\n", msh->exit_code);
	ft_dprintf("			- prev_exit: ");
	ft_dprintf("%d\n", msh->prev_exit);
}
