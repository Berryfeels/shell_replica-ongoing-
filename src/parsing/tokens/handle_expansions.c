/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:40:17 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/03 17:15:58 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	handle_variable_expansion(char *input, int *i, char *buff, t_msh *msh)
{
	int		end;
	char	*var_name;
	char	*expansion;
	int		len;

	len = ft_strlen(buff);
	end = *i;
	while (input[end] && !ft_strchr(EXP_LIMIT, input[end]))
		end++;
	var_name = ft_substr(input, *i, end - (*i));
	if (!var_name)
	{
		printf("Error: Failed to allocate memory for variable name\n");
		msh->exit_code = 2;
		return ;
	}
	expansion = find_envar(var_name, msh->ms_env);
	free(var_name);
	expand_to_buff(expansion, buff, &len, msh);
	*i = end;
}

void	handle_invalid_expansion(char *buff, int *len)
{
	buff[*len] = '$';
	(*len)++;
}

void	handle_exit_expansion(int *i, char *buff, int *len, t_msh *msh)
{
	int		exp_len;
	char	*exp_exit;
	int		j;

	exp_exit = ft_itoa(msh->prev_exit);
	exp_len = ft_strlen(exp_exit);
	(*i)++;
	j = 0;
	if (*len + exp_len >= 1023)
	{
		printf("Error: Buffer overflow during $? expansion\n");
		msh->exit_code = 2;
		free(exp_exit);
		return ;
	}
	while (j < exp_len)
	{
		buff[*len] = exp_exit[j];
		(*len)++;
		j++;
	}
	free(exp_exit);
}

void	collect_expansion(char *input, int *i, char *buff, t_msh *msh)
{
	int	len;

	len = ft_strlen(buff);
	(*i)++;
	if (ft_strchr(EXP_LIMIT, input[*i]))
		handle_invalid_expansion(buff, &len);
	else if (input[*i] == '?')
		handle_exit_expansion(i, buff, &len, msh);
	else
		handle_variable_expansion(input, i, buff, msh);
	(*i)--;
}
