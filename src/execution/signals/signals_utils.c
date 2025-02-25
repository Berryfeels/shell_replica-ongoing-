/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:37:19 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/23 19:13:27 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	handle_eof(t_msh *msh)
{
	printf("exit\n");
	free_msh(msh);
	rl_clear_history();
	exit(0);
}

void	exit_heredoc(int sig)
{
	(void)sig;
	g_sig = SIGINT;
	write(1, "\n", 1);
	close(STDIN_FILENO);
}

void	restore_prompt(int sig)
{
	g_sig = SIGINT;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

void	ctrl_c(int sig)
{
	g_sig = SIGINT;
	write(1, "\n", 1);
	(void)sig;
}

void	back_slash(int sig)
{
	g_sig = SIGQUIT;
	printf("Quit (core dumped)\n");
	(void)sig;
}
