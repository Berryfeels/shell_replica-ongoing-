/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:22:03 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/04 15:24:40 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
 
void ft_cd(char *buff, char *prompt)
{
	buff = ft_substr(prompt, 3, strlen(prompt)); 
	chdir(buff);
	free(buff);
}