/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:37 by jslusark          #+#    #+#             */
/*   Updated: 2025/02/07 17:30:42 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

bool	parse_rest(t_tokens **token, t_node_list *new_node, t_msh **msh)
{
	if ((*msh)->find_cmd)
	{
		if (!alloc_cmd(new_node, *token, msh))
			return (false);
		(*msh)->find_cmd = false;
	}
	else
	{
		if ((*msh)->found_echo && !new_node->cmd->args
			&& new_node->cmd->option_n == false)
			add_option_n(token, new_node);
		else
		{
			if (!add_argument(&(new_node->cmd->args), (*token)->value))
				return (false);
		}
	}
	return (true);
}

bool	parse_token(t_msh *msh, t_tokens **token,
					t_node_list **head, t_node_list **new_node)
{
	if ((*token)->type == PIPE)
		end_new_node(&(msh->start_node), head, *new_node);
	else
	{
		msh->pipestart = false;
		if ((*token)->type == REDIR_IN || (*token)->type == REDIR_OUT
			|| (*token)->type == APPEND || (*token)->type == HEREDOC)
		{
			if (!parse_redir(token, *new_node, &(msh->redir_i),
					&(msh->exit_code)))
				return (false);
			msh->token_n++;
		}
		else
			if (!parse_rest(token, *new_node, &msh))
				return (false);
	}
	*token = (*token)->next;
	return (true);
}

void	start_flags(t_msh *msh)
{
	msh->node_n = 1;
	msh->redir_i = 0;
	msh->token_n = 1;
	msh->start_node = true;
	msh->find_cmd = true;
	msh->pipestart = true;
	msh->found_echo = false;
}

bool	parse_nodes(t_msh *msh, t_tokens **token,
				t_node_list **head, t_node_list **new_node)
{
	if (msh->start_node == true)
	{
		*new_node = init_new_node(msh->node_n, &msh->start_node, msh);
		if (!(*new_node))
			return (false);
		msh->find_cmd = true;
		msh->found_echo = false;
		msh->redir_i = 0;
		msh->node_n++;
	}
	if (!parse_token(msh, token, head, new_node))
	{
		free_node_list(*head);
		free_node_list(*new_node);
		return (false);
	}
	return (true);
}

t_node_list	*return_nodes(t_tokens *token, t_msh *msh)
{
	t_node_list		*head;
	t_node_list		*new_node;

	start_flags(msh);
	head = NULL;
	new_node = NULL;
	while (token != NULL)
	{
		if (pipe_error(token, msh->pipestart, head, new_node))
		{
			msh->exit_code = 2;
			return (NULL);
		}
		if (!parse_nodes(msh, &token, &head, &new_node))
			return (NULL);
		msh->token_n++;
	}
	if (new_node)
		append_node(&head, new_node);
	return (head);
}
