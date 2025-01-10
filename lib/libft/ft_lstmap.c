/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:14:17 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/11 20:13:05 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	// iterate through s_list
	// apply f_function
	// copy result in new s_list
	// del and free from old one

	// function newlist, function del and free,

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		newnode = ft_lstnew(f(lst -> content));
		ft_lstadd_back(newlist, newnode);
		lst = lst -> next;
	}
	return (newlist);
}
