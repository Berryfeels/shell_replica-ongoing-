/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansion_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:16:32 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 17:17:05 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*find_envar(char *var, char **env)
{
	int		i;
	char	*var_content;

	i = 0;
	var_content = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var))
			== 0 && env[i][ft_strlen(var)] == '=')
		{
			var_content = env[i] + ft_strlen(var) + 1;
			break ;
		}
		i++;
	}
	if (!env[i])
		return (NULL);
	return (ft_strdup(var_content));
}

void	expand_to_buff(char *expansion, char *buff, int *len, t_msh *msh)
{
	int		exp_len;
	int		i;

	if (expansion)
	{
		exp_len = ft_strlen(expansion);
		if (*len + exp_len >= 1023)
		{
			printf("Error: Buffer overflow during variable expansion\n");
			msh->exit_code = 2;
			free(expansion);
			return ;
		}
		i = 0;
		while (i < exp_len)
		{
			buff[*len] = expansion[i];
			(*len)++;
			i++;
		}
		free(expansion);
	}
}
