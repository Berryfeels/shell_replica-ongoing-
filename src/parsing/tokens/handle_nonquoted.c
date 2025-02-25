/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nonquoted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:55:56 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 17:01:20 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	unquoted_buff(char *input, int *i, t_msh *msh, char *buff)
{
	int		len;
	int		y;

	y = *i + 1;
	len = ft_strlen(buff);
	if (input[*i] == '$')
	{
		if (ft_strchr(QUOTES, input[y]) && input[y] != '\0')
		{
			(*i)++;
			return ;
		}
		collect_expansion (input, i, buff, msh);
		len = ft_strlen(buff);
		(*i)++;
	}
	else
	{
		buff[len++] = input[*i];
		(*i)++;
	}
	if (input[*i] == '\0' || ft_strchr(BOUNDS, input[*i]))
		buff[len] = '\0';
}
