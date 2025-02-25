/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:26:33 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/06 18:40:26 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	handle_env(t_node_list *node)
{
	int	i;

	i = 0;
	while (node->msh->ms_env[i])
	{
		ft_putstr_fd(node->msh->ms_env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}
