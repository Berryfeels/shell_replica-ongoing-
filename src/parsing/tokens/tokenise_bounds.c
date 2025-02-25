/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_bounds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:11:09 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 15:46:12 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	handle_right(char *input, int *i, t_tokens **tokens)
{
	int	k;

	k = *i + 1;
	if (input[k] != '\0' && input[k] == '>')
	{
		append_token(tokens, create_token(">>", APPEND));
		(*i)++;
	}
	else
		append_token(tokens, create_token(">", REDIR_OUT));
}

void	handle_left(char *input, int *i, t_tokens **tokens)
{
	int	k;

	k = *i + 1;
	if (input[k] != '\0' && input[k] == '<')
	{
		append_token(tokens, create_token("<<", HEREDOC));
		(*i)++;
	}
	else
		append_token(tokens, create_token("<", REDIR_IN));
}

bool	valid_bound(char *input, int *i, t_tokens **tokens)
{
	int	k;

	k = *i +1;
	if (input[*i] == '|')
	{
		if (input[k] == '|')
		{
			printf("Minishell: error || operator are just for bonus\n");
			return (false);
		}
		else
			append_token(tokens, create_token("|", PIPE));
	}
	else if (input[*i] == '>')
		handle_right(input, i, tokens);
	else if (input[*i] == '<')
		handle_left(input, i, tokens);
	return (true);
}
