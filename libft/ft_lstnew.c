/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:25:31 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/11 17:46:09 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Parameters
// content:  The content to create the node with.
// Return Value
// The new node
// Description
// Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’.  The variable
// ’next’ is initialized to NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!(newnode))
		return (NULL);
	newnode ->content = content;
	newnode ->next = NULL;
	return (newnode);
}
