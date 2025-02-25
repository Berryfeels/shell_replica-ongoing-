# Makefile for the shell project

# Compiler and flags
CC := cc

# Original: Used for AddressSanitizer to detect memory corruption issues like buffer overflows.
# CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
# # Updated: Added -fsanitize=leak for better memory leak detection since AddressSanitizer alone focuses more on buffer overflows.
# CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=leak
# # Used when running "make valgrind" as Valgrind cannot be used on binaries compiled with -fsanitize=address. Use MAKE VALGRIND to run (uncomment it at the bottomo of the page)
CFLAGS := -Wall -Wextra -Werror -g

# Include directories
CPPFLAGS := -Iinclude -Ilib/libft -Ilib/dprintf \
			-I/usr/local/opt/readline/include
# Readline library linking
LDFLAGS := -L/usr/local/opt/readline/lib -lreadline -lhistory

# Directories
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft
DPRINTF_DIR := $(LIB_DIR)/dprintf

LIBFT_OBJ_DIR := $(LIBFT_DIR)/obj
DPRINTF_OBJ_DIR := $(LIB_DIR)/dprintf

# Libraries
LIBFT := $(LIBFT_DIR)/libft.a
DPRINTF := $(DPRINTF_DIR)/libdprintf.a

# Executable name
NAME := minishell

# Source files and object files
SRC := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/execution/execution.c \
	$(SRC_DIR)/execution/execution2.c \
	$(SRC_DIR)/execution/execution_utils.c \
	$(SRC_DIR)/execution/execution_utils_2.c \
	$(SRC_DIR)/execution/pipes/pipes.c \
	$(SRC_DIR)/execution/redirections/create_heredoc.c \
	$(SRC_DIR)/execution/redirections/set_heredoc.c \
	$(SRC_DIR)/execution/redirections/set_redirection.c \
	$(SRC_DIR)/execution/signals/signals.c \
	$(SRC_DIR)/execution/signals/signals_utils.c \
	$(SRC_DIR)/execution/external_cmds/exec_externals.c \
	$(SRC_DIR)/execution/external_cmds/exec_externals_utils.c \
	$(SRC_DIR)/execution/built_in/cmd_cd.c \
	$(SRC_DIR)/execution/built_in/cmd_echo.c \
	$(SRC_DIR)/execution/built_in/cmd_env.c \
	$(SRC_DIR)/execution/built_in/cmd_exit.c \
	$(SRC_DIR)/execution/built_in/cmd_export.c \
	$(SRC_DIR)/execution/built_in/cmd_export_print.c \
	$(SRC_DIR)/execution/built_in/cmd_export_utils.c \
	$(SRC_DIR)/execution/built_in/cmd_pwd.c \
	$(SRC_DIR)/execution/built_in/cmd_unset.c \
	$(SRC_DIR)/execution/built_in/env/env_init.c \
	$(SRC_DIR)/execution/built_in/env/get_env.c \
	$(SRC_DIR)/execution/built_in/env/store_home.c \
	$(SRC_DIR)/execution/built_in/exec_builtin.c \
	$(SRC_DIR)/parsing/nodes/alloc_args.c \
	$(SRC_DIR)/parsing/nodes/alloc_cmd.c \
	$(SRC_DIR)/parsing/nodes/alloc_nodes.c \
	$(SRC_DIR)/parsing/nodes/alloc_option.c \
	$(SRC_DIR)/parsing/nodes/alloc_redir.c \
	$(SRC_DIR)/parsing/nodes/error_handling.c \
	$(SRC_DIR)/parsing/nodes/free_msh.c \
	$(SRC_DIR)/parsing/nodes/free_nodes.c \
	$(SRC_DIR)/parsing/nodes/print_nodes.c \
	$(SRC_DIR)/parsing/nodes/print_on_cli_utils.c \
	$(SRC_DIR)/parsing/nodes/print_on_file_utils.c \
	$(SRC_DIR)/parsing/nodes/return_nodes.c \
	$(SRC_DIR)/parsing/tokens/allocate_tokens.c \
	$(SRC_DIR)/parsing/tokens/handle_expansions.c \
	$(SRC_DIR)/parsing/tokens/handle_expansion_utils.c \
	$(SRC_DIR)/parsing/tokens/handle_nonquoted.c \
	$(SRC_DIR)/parsing/tokens/handle_quoted.c \
	$(SRC_DIR)/parsing/tokens/print_tokens.c \
	$(SRC_DIR)/parsing/tokens/return_tokens.c \
	$(SRC_DIR)/parsing/tokens/tokenise_bounds.c \
	$(SRC_DIR)/parsing/tokens/tokenize_strings.c

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(DPRINTF) $(OBJ)
	@if [ ! -f $(LIBFT) ]; then \
		echo "Error: libft.a not found in $(LIBFT_DIR)"; exit 1; \
	fi
	@if [ ! -f $(DPRINTF) ]; then \
		echo "Error: libftdprintf.a not found in $(DPRINTF_DIR)"; exit 1; \
	fi
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(DPRINTF) $(LDFLAGS) -o $(NAME)

# Compile object files - cppflags is for realoine funcs to work
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) OBJ_DIR=$(LIBFT_OBJ_DIR) -C $(LIBFT_DIR)

# Build ft_dprintf
$(DPRINTF):
	@echo "Building libdprintf.a in $(DPRINTF_DIR)"
	$(MAKE) OBJ_DIR=$(DPRINTF_OBJ_DIR) -C $(DPRINTF_DIR)

# Clean rules
clean:
	$(MAKE) clean OBJ_DIR=$(LIBFT_OBJ_DIR) -C $(LIBFT_DIR)
	$(MAKE) clean OBJ_DIR=$(DPRINTF_OBJ_DIR) -C $(DPRINTF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean OBJ_DIR=$(LIBFT_OBJ_DIR) -C $(LIBFT_DIR)
	$(MAKE) fclean OBJ_DIR=$(DPRINTF_OBJ_DIR) -C $(DPRINTF_DIR)
	rm -f $(NAME)

re: fclean all

# Added to use minishell with valgrind and avoid copy/past all the time - cannot be used when the program is compiled with fsanitise
# leaks:
# 	valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re
