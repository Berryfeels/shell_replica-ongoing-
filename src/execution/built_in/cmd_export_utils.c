/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:50:52 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/21 18:01:08 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	swap_strings(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(char **env, int j)
{
	char	*var_a;
	char	*var_b;
	int		len_a;
	int		len_b;
	int		min_len;

	var_a = env[j];
	var_b = env[j + 1];
	len_a = 0;
	len_b = 0;
	while (var_a[len_a] != '\0' && var_a[len_a] != '=')
		len_a++;
	while (var_b[len_b] != '\0' && var_b[len_b] != '=')
		len_b++;
	if (len_a < len_b)
		min_len = len_a;
	else
		min_len = len_b;
	if (ft_strncmp(var_a, var_b, min_len) > 0)
		swap_strings(&env[j], &env[j + 1]);
}

void	sort_env_vars(char **env)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (env[count] != NULL)
		count++;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			bubble_sort(env, j);
			j++;
		}
		i++;
	}
}
