/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:36:50 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/04 09:22:31 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	pipe_error(t_tokens *token, bool check_pipestart,
					t_node_list *head, t_node_list *new_node)
{
	if (token->type == PIPE)
	{
		if (check_pipestart)
		{
			printf("Minishell: ");
			printf("found `%s' at begining of syntax\n", token->value);
			return (true);
		}
		else if (!token->next)
		{
			printf("Minishell: ");
			printf("found `%s' at end of syntax\n", token->value);
			free_node_list(new_node);
			free_node_list(head);
			return (true);
		}
		else if (token->next->type == PIPE)
		{
			printf("syntax error near unexpected token `%s'\n", token->value);
			free_node_list(new_node);
			free_node_list(head);
			return (true);
		}
	}
	return (false);
}

bool	redir_error(t_tokens *token)
{
	if (token->type == REDIR_IN || token->type == REDIR_OUT
		|| token->type == APPEND || token->type == HEREDOC)
	{
		if (token->next == NULL)
		{
			printf("Minishell: ");
			printf("syntax error near unexpected token `newline'\n");
			return (true);
		}
		else if (token->next->type == PIPE || token->next->type == REDIR_IN
			|| token->next->type == REDIR_OUT || token->next->type == APPEND
			|| token->next->type == HEREDOC || token->next->type == INVALID)
		{
			printf("Minishell: syntax error near ");
			printf("unexpected token `%s'\n", token->next->value);
			return (true);
		}
	}
	return (false);
}
