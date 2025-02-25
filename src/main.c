/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:26:03 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/21 18:11:38 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_sig;

t_node_list	*parse(char *input, t_node_list *nodes, t_msh *msh)
{
	t_tokens	*tokens;

	tokens = return_tokens(input, msh);
	free(input);
	if (!tokens)
	{
		msh->prev_exit = msh->exit_code;
		nodes = NULL;
	}
	else
	{
		nodes = return_nodes(tokens, msh);
		if (!nodes)
			msh->prev_exit = msh->exit_code;
	}
	if (tokens)
		free_tokens(tokens);
	return (nodes);
}

void	handle_input(char *input, t_node_list *nodes, t_msh *msh)
{
	if (g_sig == SIGINT)
	{
		msh->prev_exit = 130;
		g_sig = 0;
	}
	if (g_sig == SIGQUIT)
	{
		msh->prev_exit = 131;
		g_sig = 0;
	}
	if (input && *input)
		add_history(input);
	nodes = parse(input, nodes, msh);
	if (nodes)
	{
		exec_node_list(nodes);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_node_list		*nodes;
	t_msh			*msh;

	(void)argc;
	(void)argv;
	ms_env_init(&msh, envp);
	store_home(msh->ms_env, msh);
	nodes = NULL;
	while (1)
	{
		run_signals(1, msh);
		input = readline(COLOR_GREEN "Minishell> " COLOR_RESET);
		if (!input)
			handle_eof(msh);
		else
			handle_input(input, nodes, msh);
		msh->prev_exit = msh->exit_code;
	}
	free_msh(msh);
	rl_clear_history();
	return (0);
}
