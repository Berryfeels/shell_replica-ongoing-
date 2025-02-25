/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:02:05 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 12:04:49 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	check_if_option(t_tokens **token)
{
	int			i;
	t_tokens	*temp;

	if ((*token)->value[0] != '-'
		|| ((*token)->value[0] == '-'
			&& (*token)->value[1] == '\0'))
		return (false);
	temp = *token;
	i = 1;
	while (temp->value[i] == 'n')
		i++;
	if (temp->value[i] == '\0')
		return (true);
	else
		return (false);
}

void	add_option_n(t_tokens **token, t_node_list *new_node)
{
	if (check_if_option(token))
	{
		new_node->cmd->option_n = true;
		while (check_if_option(token) && (*token)->next)
		{
			if (check_if_option(&(*token)->next))
				*token = (*token)->next;
			else
				break ;
		}
	}
	else
		add_argument(&(new_node->cmd->args), (*token)->value);
}
