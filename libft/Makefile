CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_isalpha.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c\
ft_strrchr.c ft_tolower.c ft_toupper.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
ft_strjoin.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c\
ft_putchar_fd.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c

OBJSB=ft_lstnew.c ft_lstlast.c ft_lstdelone.c ft_lstadd_front.c ft_lstadd_back.c
OBJS=$(SRCS:.c=.o)
NAME=libft.a
HEADER = libft.h
all:	$(NAME)
%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)
	@echo "Creating library $@"

bonus: ${NAME} ${OBJSB}
	   ${NAME} ${OBJSB}

.PHONY:	clean
clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
