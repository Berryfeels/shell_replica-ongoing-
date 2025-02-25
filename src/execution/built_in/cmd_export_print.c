/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:13:01 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/21 18:01:31 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_exp_error(const char *identifier)
{
	write(2, "export: `", 9);
	if (identifier)
		write(2, identifier, ft_strlen(identifier));
	write(2, "': not a valid identifier", 25);
	write(2, "\n", 1);
}

void	write_sides(char c)
{
	ft_putchar_fd(c, 1);
	ft_putchar_fd('"', 1);
}

void	write_exported_var(char *env)
{
	bool	inside_value;
	int		i;

	i = 0;
	write(1, "export ", 7);
	inside_value = false;
	while (env[i] != '\0')
	{
		if (env[i] == '=' && !inside_value)
		{
			write_sides(env[i]);
			inside_value = true;
			if (env[i + 1] == '\0')
				ft_putchar_fd('"', 1);
		}
		else if (env[i + 1] == '\0' && inside_value)
			write_sides(env[i]);
		else
			ft_putchar_fd(env[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	print_exported(char **env)
{
	int		i;
	int		count;
	char	**sorted_env;

	i = 0;
	count = 0;
	while (env[count] != NULL)
		count++;
	sorted_env = malloc(sizeof(char *) * (count + 1));
	if (!sorted_env)
		return ;
	while (i < count)
	{
		sorted_env[i] = env[i];
		i++;
	}
	sorted_env[count] = NULL;
	sort_env_vars(sorted_env);
	i = 0;
	while (sorted_env[i] != NULL)
	{
		write_exported_var(sorted_env[i]);
		i++;
	}
	free(sorted_env);
}
