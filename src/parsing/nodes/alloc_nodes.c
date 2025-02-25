/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:57:22 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/04 09:34:09 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	end_new_node(bool *start_node, t_node_list **head,
						t_node_list *new_node)
{
	append_node(head, new_node);
	*start_node = true;
}

void	append_node(t_node_list **head, t_node_list *new_node)
{
	t_node_list	*last_node;

	if (!(*head))
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		last_node = *head;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_node_list	*init_new_node(int node_n, bool *start_node, t_msh *msh)
{
	t_node_list	*new_node;

	new_node = ft_calloc(1, sizeof(t_node_list));
	if (!new_node)
	{
		printf("Minishell: Failed to allocate node number %d\n", node_n);
		return (NULL);
	}
	new_node->node_i = node_n - 1;
	new_node->msh = msh;
	new_node->fd_in = 0;
	new_node->fd_out = 1;
	*start_node = false;
	return (new_node);
}
