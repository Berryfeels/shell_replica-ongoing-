/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quoted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:41:21 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 15:51:51 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	buffer_overflow(int len, t_msh *msh)
{
	if (len >= 1024)
	{
		printf("Minishell: buffer overflow\n");
		msh->exit_code = 2;
		return (true);
	}
	return (false);
}

bool	unclosed_quote(char *input, int *i, t_msh *msh, bool *closure)
{
	if (input[*i] == '\0' && !(*closure))
	{
		msh->exit_code = 2;
		printf("Minishell: quote at input[%d] had no closure\n", *i);
		return (true);
	}
	return (false);
}

bool	closed_quote(char *input, int *i, char quote, bool *closure)
{
	if (input[*i] == quote)
	{
		*closure = true;
		return (true);
	}
	return (false);
}

void	quoted_buff(char *input, int *i, t_msh *msh, char *buff)
{
	int		len;
	bool	closure;
	char	quote;

	quote = input[*i];
	closure = false;
	(*i)++;
	while (input[*i] != '\0')
	{
		len = ft_strlen(buff);
		if (closed_quote(input, i, quote, &closure))
			break ;
		else if (input[*i] == '$' && quote == '"')
			collect_expansion(input, i, buff, msh);
		else
			buff[len++] = input[*i];
		if (buffer_overflow(len, msh))
			return ;
		(*i)++;
	}
	if (unclosed_quote(input, i, msh, &closure))
		return ;
	buff[len] = '\0';
}
