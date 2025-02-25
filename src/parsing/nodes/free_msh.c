/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:32:30 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/18 17:08:55 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../include/minishell.h"

// void	free_env(char **env)
// {
// 	int	i;

// 	i = 0;
// 	if (env)
// 	{
// 		while (env[i])
// 		{
// 			free (env[i]);
// 			i++;
// 		}
// 		free(env);
// 	}
// }

// void	free_msh(t_msh *msh)
// {
// 	if (!msh)
// 		return ;
// 	free_env(msh->ms_env);
// 	free_env(msh->env_exp);
// 	if (msh->home_path)
// 		free(msh->home_path);
// 	free(msh);
// }
