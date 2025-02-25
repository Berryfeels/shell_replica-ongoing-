/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:44:46 by jslusark          #+#    #+#             */
/*   Updated: 2024/05/07 10:44:17 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/* #include <stdio.h>
void	ft_toupper_adapter(unsigned int i __attribute__((unused)), char *c)
{
	*c = ft_toupper((unsigned char)*c);
}
void	ft_tolower_adapter(unsigned int i __attribute__((unused)), char *c)
{
	*c = ft_tolower((unsigned char)*c);
}
int	main(void)
{
	char	s1[100] = "Converts all to uppercase";
	char	s2[100] = "CONVERTS ALL TO LOWERCASE";
	ft_striteri(s1, ft_toupper_adapter);
	ft_striteri(s2, ft_tolower_adapter);
	printf("%s\n", s1);
	printf("%s\n", s2);
} */
