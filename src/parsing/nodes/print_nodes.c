/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:00:11 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/04 11:08:58 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*return_token_enum(int token_type)
{
	if (token_type == REDIR_IN)
		return ("REDIR_IN (<)");
	else if (token_type == REDIR_OUT)
		return ("REDIR_OUT (>)");
	else if (token_type == APPEND)
		return ("APPEND (>>)");
	else if (token_type == HEREDOC)
		return ("HEREDOC (<<)");
	else if (token_type == PIPE)
		return ("PIPE");
	else if (token_type == ARG)
		return ("ARG");
	else if (token_type == INVALID)
		return ("INVALID");
	else
		return ("UNRECOGNISED_ENUM");
}

char	*return_target_enum(int redir_type)
{
	if (redir_type == 7)
		return ("DELIMITER");
	return ("FILE");
}

void	print_nodes(t_node_list *head)
{
	t_node_list	*curr;
	int			n;

	n = 0;
	curr = head;
	printf(COLOR_GREEN"\nNODE LIST TO ITERATE AND EXECUTE...\n"COLOR_RESET);
	while (curr != NULL)
	{
		n++;
		printf(COLOR_YELLOW"	- NODE %d\n"COLOR_RESET, n);
		printf(COLOR_BLUE"		- int node_i:"COLOR_RESET);
		printf(" %d\n", curr->node_i);
		if (curr->msh)
			print_exit_codes(curr->msh);
		if (!curr->cmd)
			print_null_cmd();
		else
			print_cmd_struct(curr->cmd);
		print_redir(curr->redir);
		curr = curr->next;
	}
	printf("\n	Total number of pipes: %d\n", n - 1);
	printf("	Total number of nodes: %d\n", n);
}

void	print_nodes_file(t_node_list *head)
{
	t_node_list	*curr;
	int			n;

	n = 0;
	curr = head;
	ft_dprintf(COLOR_GREEN"\nNODE LIST TO ITERATE AND EXECUTE...\n"COLOR_RESET);
	while (curr != NULL)
	{
		n++;
		ft_dprintf(COLOR_YELLOW"	- NODE %d\n"COLOR_RESET, n);
		ft_dprintf(COLOR_BLUE"		- int node_i:"COLOR_RESET);
		ft_dprintf(" %d\n", curr->node_i);
		if (curr->msh)
			print_exit_codes_file(curr->msh);
		if (!curr->cmd)
			print_null_cmd_file();
		else
			print_cmd_struct_file(curr->cmd);
		print_redir_file(curr->redir);
		curr = curr->next;
	}
	ft_dprintf("\n	Total number of pipes: %d\n", n - 1);
	ft_dprintf("	Total number of nodes: %d\n", n);
}
