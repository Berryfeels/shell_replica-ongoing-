/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:01:45 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/04 15:33:26 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_openErrorScan(void)
{
	int fd;
	
	fd = open ("ErrorScan.txt", O_RDWR, O_CREAT, 0777);
	if (fd == -1)
		close (fd);
	exit (EXIT_ERROR);
}



int	main()
{	
	int	fd;
	char *prompt;
	char *buff;

	buff = NULL;
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}
	while (1)
	{	
		prompt = readline("Mestepum> ");
		if (prompt)
		{
			if(*prompt)
			{
				add_history(prompt);
				if (prompt[0] == 'c' && prompt[1] == 'd' && prompt[2] == ' ')
					ft_cd(buff, prompt);
				if (prompt[0] == 'p' && prompt[1] == 'w' && prompt[2] == 'd')
					ft_pwd();
				if (strncmp(prompt, "exit", 4) == 0)//place holder
					return 0;
				free (prompt);
			}
		}
		else 
			break;
		
	}
	close (fd);
	return 0;
}