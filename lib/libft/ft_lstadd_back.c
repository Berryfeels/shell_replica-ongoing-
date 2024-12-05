/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:59:14 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/11 18:39:08 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lsttemp;

	lsttemp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (lsttemp != NULL)
			lsttemp = lsttemp -> next;
		lsttemp -> next = new;
		new -> next = NULL;
	}
}
