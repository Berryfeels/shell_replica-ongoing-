/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:35:26 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 15:02:26 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	free_tokens(t_tokens *head)
{
	t_tokens	*current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current->value);
		free(current);
	}
}

t_tokens	*create_token(const char *value, int type)
{
	t_tokens	*new_token;

	new_token = malloc(sizeof(t_tokens));
	if (!new_token)
		return (NULL);
	new_token->value = ft_strdup(value);
	if (!new_token->value)
	{
		free(new_token);
		return (NULL);
	}
	new_token->type = type;
	new_token->next = NULL;
	return (new_token);
}

void	append_token(t_tokens **head, t_tokens *new_token)
{
	t_tokens	*current;

	if (!*head)
	{
		*head = new_token;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_token;
}
