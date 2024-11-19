/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:23:14 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/04 15:24:45 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_pwd ()
{
	char cwd[PATH_MAX];
	if (getcwd(cwd, PATH_MAX) == NULL)
		perror("getcwd() error");
    else
    	ft_printf("%s\n", cwd);	
}