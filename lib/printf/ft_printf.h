/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:41:56 by jadyar            #+#    #+#             */
/*   Updated: 2024/02/09 22:02:36 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
int		ft_print_format(const char specifier, va_list ap, int *count);
int		ft_print_unsigned(unsigned int n, int *count);
int		ft_print_number(int n, int *count);
int		ft_print_hexa(unsigned long n, char specifier, int *count);
int		ft_print_string(char *str, int *count);
int		ft_print_char(char c, int *count);
int		ft_print_pointer(void *ptr, int *count);

#endif
