/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:08:41 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 11:47:24 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	add_argument(char ***args, char *new_arg)
{
	int		count;
	char	**new_array;
	int		i;

	count = 0;
	if (*args)
		while ((*args)[count])
			count++;
	new_array = (char **)malloc(sizeof(char *) * (count + 2));
	if (!new_array)
		return (false);
	i = -1;
	while (++i < count)
		new_array[i] = (*args)[i];
	new_array[count] = ft_strdup(new_arg);
	if (!new_array[count])
	{
		free(new_array);
		return (false);
	}
	new_array[count + 1] = NULL;
	free(*args);
	*args = new_array;
	return (true);
}
/*
	If leaks check if these changes are the reason:
	line 25 = used malloc instead of realloc
	line 28,29,30
	line 34 = free(new_array)
	line 38 = free(*args)
 */
