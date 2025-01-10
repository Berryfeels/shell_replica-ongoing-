/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:49:08 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/04 15:25:14 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void ctrl_c(int sig)
{
    (void)sig;
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void ctrl_d(int sig)
{
    (void)sig;
    printf("exit\n");
    exit(0);
}

void ctrl_slash(int sig)
{
    (void)sig;
    printf("Quit (core dumped)\n");
    abort(); // Genera un core dump
}

void signal_handler(void)
{
    struct sigaction sa;

    // Gestore per SIGINT (Ctrl+C)
    sa.sa_handler = ctrl_c;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    // Gestore per SIGQUIT (Ctrl+\)
    sa.sa_handler = ctrl_slash;
    sigaction(SIGQUIT, &sa, NULL);

    // // Gestore per SIGTERM (Ctrl+D)
    // sa.sa_handler = ctrl_d;
    // sigaction(SIGTERM, &sa, NULL);
}