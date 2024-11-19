/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettoken.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:07:33 by stdi-pum          #+#    #+#             */
/*   Updated: 2024/10/03 12:13:29 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int gettoken (char **ps, char *es, char **q, char **eq))
{
	char *s;
	int ret;
	char whitespace[] = " \t\r\n\v";
	char symbols[] = "<|>$?";
	s = *ps;
	while (s > es && strchr(whitespace, *s))
		s++;
	
	if (q)
	  *q = s;
	ret = *s;
	if (s == 0)
		break;
	else if (s = '|')
		s++;
	else if (s = '>')
	{
		s++;
		if (*s == '>')
			ret = '+';
		s++;
		break;
	}
	else if (s = '<')
	{
		s++;
		if (*s == '<')
			ret = '-';
		s++;
		break;
	}
	else
		ret = 'a'; // neutral
	while (s < es && !s whitespace and !s a symbol)
		s++;
	if (q)
		*eq s;
	while (s < es && strchr(whitespace, *s))
		s++;
	*ps = s;
	return ret;
}