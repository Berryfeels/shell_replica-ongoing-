/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:42:26 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 15:49:33 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	empty_quoted(int *i, char *input)
{
	int	prev_i;
	int	next_i;

	prev_i = *i - 2;
	next_i = *i + 1;
	if ((prev_i < 0 || ft_strchr(BOUNDS, input[prev_i]))
		&& (input[next_i] == '\0' || ft_strchr(BOUNDS, input[next_i])))
		return (true);
	return (false);
}

bool	stop_buffer(char *input, int *i, char *buff, t_msh *msh)
{
	if (msh->exit_code != 0)
		return (true);
	if (input[*i + 1] == ' ' || input[*i + 1] == '\0'
		|| ft_strchr(BOUNDS, input[*i + 1]))
	{
		if (ft_strlen(buff) > 0)
			return (true);
		else if (empty_quoted(i, input))
			return (true);
		return (true);
	}
	(*i)++;
	return (false);
}

void	parse_string(char *input, int *i, t_msh *msh, char *buff)
{
	int	len;

	while (!ft_strchr(BOUNDS, input[*i]) && input[*i] != '\0')
	{
		if (ft_strchr(QUOTES, input[*i]))
		{
			quoted_buff(input, i, msh, buff);
			if (stop_buffer(input, i, buff, msh))
				break ;
			len = ft_strlen(buff);
		}
		else
		{
			unquoted_buff(input, i, msh, buff);
			len = ft_strlen(buff);
			if (input[*i] == '\0' || ft_strchr(BOUNDS, input[*i]))
			{
				buff[len] = '\0';
				(*i)--;
				break ;
			}
		}
	}
}
