/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:08:44 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/11 12:29:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	append_new_redir(t_redir **head_redir, t_redir *curr_redir)
{
	t_redir	*last_redir;

	if (!(*head_redir))
	{
		*head_redir = curr_redir;
		curr_redir->prev = NULL;
	}
	else
	{
		last_redir = *head_redir;
		while (last_redir->next)
			last_redir = last_redir->next;
		last_redir->next = curr_redir;
		curr_redir->prev = last_redir;
	}
}

bool	add_target(t_tokens *token, t_redir *redir)
{
	redir->target = ft_strdup(token->next->value);
	if (!redir->target)
	{
		printf("Minishell: Failed to add target to redir data\n");
		redir = (NULL);
		return (false);
	}
	return (true);
}

t_redir	*init_new_redir(t_tokens **token, int *exit_code)
{
	t_redir	*redir;

	redir = ft_calloc(1, sizeof(t_redir));
	if (!redir)
	{
		printf("Minishell: Failed to allocate redirection struct\n");
		*exit_code = 2;
		return (NULL);
	}
	redir->type = (*token)->type;
	if ((*token)->next != NULL && !add_target(*token, redir))
	{
		*exit_code = 1;
		return (NULL);
	}
	*token = (*token)->next;
	return (redir);
}

bool	parse_redir(t_tokens **token, t_node_list *new_node,
int *redir_i, int *exit_code)
{
	t_redir	*new_redir;

	if (redir_error(*token))
	{
		*exit_code = 2;
		return (false);
	}
	new_redir = init_new_redir(token, exit_code);
	if (!new_redir)
		return (false);
	new_redir->redir_i = *redir_i;
	append_new_redir(&(new_node->redir), new_redir);
	(*redir_i)++;
	return (true);
}
