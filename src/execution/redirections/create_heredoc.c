/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:45:13 by stdi-pum          #+#    #+#             */
/*   Updated: 2025/02/21 18:08:34 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	feed_heredoc_to_pipe(char *doc)
{
	int	fd[2];

	(void)doc;
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}

void	process_expansion_or_copy(char *line, int *i, char *buff, t_msh *msh)
{
	int	j;

	j = ft_strlen(buff);
	if (line[*i] == '$')
	{
		collect_expansion(line, i, buff, msh);
		(*i)++;
	}
	else
	{
		buff[j] = line[*i];
		(*i)++;
		buff[j + 1] = '\0';
	}
}

char	*expanded_line(char *line, t_msh *msh)
{
	int		i;
	int		size;
	char	*buff;

	i = 0;
	size = ft_strlen(line) + 1024;
	buff = malloc(size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, size);
	while (line[i] != '\0')
		process_expansion_or_copy(line, &i, buff, msh);
	return (buff);
}

bool	add_line_to_doc(char *line, t_redir *redir, t_exec *exec, char **doc)
{
	char	*temp;

	if (!line)
		return (false);
	line = expanded_line(line, exec->msh);
	if (ft_strcmp(line, redir->target) == 0)
	{
		free(line);
		return (false);
	}
	if (*doc == NULL)
		*doc = ft_strdup(line);
	else
	{
		temp = ft_strjoin(*doc, line);
		free(*doc);
		*doc = temp;
	}
	temp = ft_strjoin(*doc, "\n");
	free(*doc);
	*doc = temp;
	free(line);
	return (true);
}
