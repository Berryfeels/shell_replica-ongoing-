/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:24:59 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 15:14:58 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*return_enum(int token_type)
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
		return ("REDIR_IN (<)");
	else
		return ("UNRECOGNISED ENUM");
}

void	print_tokens(t_tokens *tokens)
{
	t_tokens	*current;
	int			i;

	current = tokens;
	i = 0;
	printf(COLOR_GREEN"TOKEN LIST\n"COLOR_RESET);
	while (current != NULL)
	{
		printf(COLOR_BLUE"Token %d:"COLOR_RESET, i);
		printf("%s", current->value);
		printf(COLOR_YELLOW"<--- %s\n"COLOR_RESET, return_enum(current->type));
		current = current->next;
		i++;
	}
}
