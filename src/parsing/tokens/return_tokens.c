/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:43:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/07 17:14:00 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	skip_spaces(char *input, int *i)
{
	if (input[*i] == ' ')
	{
		while (input[*i] == ' ' && input[*i] != '\0')
		{
			if (input[*i + 1] != ' ')
				break ;
			(*i)++;
		}
	}
}

t_tokens	*tokenize(char *input, int *i, t_msh *msh, t_tokens *tokens)
{
	char	buff[1024];
	char	start;

	start = input[*i];
	ft_memset(buff, 0, sizeof(buff));
	skip_spaces(input, i);
	if (!ft_strchr(BOUNDS, input[*i]))
	{
		parse_string(input, i, msh, buff);
		if (ft_strlen(buff) == 0 && start == '$')
			return (tokens);
		append_token(&tokens, create_token(buff, ARG));
	}
	else if (!valid_bound(input, i, &tokens))
	{
		msh->exit_code = 2;
		return (tokens);
	}
	return (tokens);
}

t_tokens	*return_tokens(char *input, t_msh *msh)
{
	int			i;
	t_tokens	*tokens;

	i = 0;
	tokens = NULL;
	msh->exit_code = 0;
	while (input[i] != '\0')
	{
		if (msh->exit_code != 0)
			break ;
		tokens = tokenize(input, &i, msh, tokens);
		if (input[i] != '\0')
			i++;
	}
	if (msh->exit_code != 0)
	{
		free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}
