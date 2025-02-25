/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:26:41 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/06 18:42:49 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	handle_pwd(t_node_list *node)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		write(node->fd_out, cwd, ft_strlen(cwd));
		write(node->fd_out, "\n", 1);
		free(cwd);
		return (0);
	}
	else
	{
		printf(COLOR_GREEN"Minishell> "COLOR_RESET);
		perror("pwd");
		node->msh->exit_code = 1;
		return (1);
	}
}
