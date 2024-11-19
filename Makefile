# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/29 15:56:04 by stdi-pum          #+#    #+#              #
#    Updated: 2024/10/04 15:56:39 by stdi-pum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME  = minishell

# Compiler
CC      = cc
CFLAGS  = -g -Werror -Wextra -Wall

# Libft
LIBFT_PATH  = libft/
LIBFT_NAME  = libft.a
LIBFT       = $(LIBFT_PATH)$(LIBFT_NAME)

# printf
PRINTF_PATH = printf/
PRINTF_NAME = libprintf.a
PRINTF      = $(PRINTF_PATH)$(PRINTF_NAME)

# dprintf
DPRINTF_PATH = dprintf/
DPRINTF_NAME = libdprintf.a
DPRINTF      = $(DPRINTF_PATH)$(DPRINTF_NAME)

# Includes
INC         =   -I ./include/ \
				-I $(LIBFT_PATH) \
				-I $(PRINTF_PATH) \
				-I $(DPRINTF_PATH) \

# Source directories
SRC_PATH    = src/

# search for .c files in subfolders
SRC = $(shell find $(SRC_PATH) -type f -name "*.c")

# Object directories
OBJ_PATH = src/obj

# sets the folders for .o files mimiking the src path
OBJS = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))


# Rule to create object directories
$(OBJ_PATH):
	@echo "Creating object directories..."
	@mkdir -p	$(OBJ_PATH)

# Object files
OBJS = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))


# Rules
all: $(LIBFT) $(PRINTF) $(DPRINTF) $(NAME)

# Create .o files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)


# Build libft
$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH)

# Build printf
$(PRINTF):
	@echo "Building printf..."
	@make -C $(PRINTF_PATH)

# Build dprintf
$(DPRINTF):
	@echo "Building dprintf..."
	@make -C $(DPRINTF_PATH)

# Build executable
$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@echo "What is your order, Master?"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lprintf -L$(DPRINTF_PATH) -ldprintf -lreadline

# Clean object files
clean:
	@echo "Removing .o object files..."
	$(RM)  $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	@make clean -C $(DPRINTF_PATH)
# Clean everything including executables
fclean: clean
	@echo "Removing executables and libraries..."
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(PRINTF)
	$(RM) $(DPRINTF)
	@rm -rf $(OBJ_PATH)

# Rebuild everything
re: fclean all

.PHONY: all re clean fcleanc

