# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 20:11:18 by stdi-pum          #+#    #+#              #
#    Updated: 2024/09/30 20:43:04 by stdi-pum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_itoa.c\
			ft_dprintf.c\
			dprint_functions.c\
			dprint_functions2.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libdprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
