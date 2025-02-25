/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:12:33 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/23 19:49:53 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	advance_redir(t_redir **current_redir, t_redir **prev_redir)
{
	*prev_redir = *current_redir;
	*current_redir = (*current_redir)->next;
}

void	erase_heredoc_update_redir_list(t_node_list *node,
	t_redir **current_redir, t_redir **prev_redir)
{
	t_redir	*temp_redir;

	if (*prev_redir)
		(*prev_redir)->next = (*current_redir)->next;
	else
		node->redir = (*current_redir)->next;
	temp_redir = *current_redir;
	*current_redir = (*current_redir)->next;
	free(temp_redir->target);
	free(temp_redir);
}

char	*exec_heredoc(t_redir *redir, t_exec *exec)
{
	char	*line;
	char	*doc;

	doc = NULL;
	run_signals(3, NULL);
	while (1)
	{
		line = readline("> ");
		if (!add_line_to_doc(line, redir, exec, &doc))
			break ;
	}
	if (g_sig == SIGINT)
	{
		if (doc != NULL)
		{
			free(doc);
			doc = NULL;
		}
	}
	if (doc == NULL)
		doc = ft_strdup("");
	return (doc);
}

void	piping_heredoc(int *heredoc_pipe, char *doc)
{
	if (pipe(heredoc_pipe) == -1)
	{
		perror("pipe");
		return ;
	}
	write(heredoc_pipe[1], doc, ft_strlen(doc));
	close(heredoc_pipe[1]);
}

void	handle_heredoc(t_node_list *node, int *heredoc_pipe, t_exec *exec)
{
	t_redir	*current_redir;
	t_redir	*prev_redir;
	char	*doc;

	current_redir = node->redir;
	prev_redir = NULL;
	doc = NULL;
	while (current_redir)
	{
		if (current_redir->type == HEREDOC)
		{
			if (doc != NULL)
				free(doc);
			doc = exec_heredoc(current_redir, exec);
			piping_heredoc(heredoc_pipe, doc);
			erase_heredoc_update_redir_list(node, &current_redir, &prev_redir);
		}
		else
			advance_redir(&current_redir, &prev_redir);
	}
	if (doc != NULL)
		free(doc);
}
