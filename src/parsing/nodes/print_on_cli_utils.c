/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_on_cli_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:06:38 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/11 12:29:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_redir(t_redir *head)
{
	t_redir	*current;

	if (!head)
	{
		printf(COLOR_BLUE"		- t_redir redir:"COLOR_RESET);
		printf(" null\n");
		return ;
	}
	current = head;
	printf(COLOR_BLUE"		- t_redir redir:\n"COLOR_RESET);
	while (current)
	{
		printf(COLOR_CYAN"			");
		printf("- REDIR N %d:\n"COLOR_RESET, current->redir_i + 1);
		printf("			  ");
		printf("- int type: %s\n", return_token_enum(current->type));
		printf("			  ");
		printf("- char *target: %s (%s)\n", current->target,
			return_token_enum(current->type));
		printf("			  ");
		printf("- int target_type: %s\n", return_target_enum(current->type));
		current = current->next;
	}
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	if (!args || !args[0])
	{
		printf("			- char **args:");
		printf(" null\n");
		return ;
	}
	printf("			- char **args:\n");
	while (args[i])
	{
		printf("				*arg[%d]: %s\n", i, args[i]);
		i++;
	}
}

void	print_null_cmd(void)
{
	printf(COLOR_BLUE"		- t_cmd cmd: "COLOR_RESET);
	printf("null\n");
	printf("			- char **args:");
	printf(" null\n");
	printf(COLOR_YELLOW"			- bool option -n:"COLOR_RESET);
	printf(" null\n");
}

void	print_cmd_struct(t_cmd *cmd)
{
	printf(COLOR_BLUE"		- t_cmd cmd:\n"COLOR_RESET);
	printf("			- char *cmd: %s\n", cmd->cmd);
	print_args(cmd->args);
	if (cmd->option_n)
	{
		printf(COLOR_YELLOW"			- bool option -n:"COLOR_RESET);
		printf(" true\n");
	}
	if (!cmd->option_n)
	{
		printf(COLOR_YELLOW"			- bool option -n:"COLOR_RESET);
		printf(" false\n");
	}
}

void	print_exit_codes(t_msh	*msh)
{
	printf(COLOR_BLUE"		- node->msh: \n"COLOR_RESET);
	printf("			- exit_code: ");
	printf("%d\n", msh->exit_code);
	printf("			- prev_exit: ");
	printf("%d\n", msh->prev_exit);
}
