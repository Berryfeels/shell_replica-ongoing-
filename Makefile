NAME  = minishell

# Compiler
CC      = cc
CFLAGS  = -g -Werror -Wextra -Wall -fsanitize=address

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

# Find all .c files recursively in SRC_PATH
SRC = $(shell find $(SRC_PATH) -type f -name "*.c")

# Object directories
OBJ_PATH = src/obj/

# Map .c files to corresponding .o files in OBJ_PATH
OBJS = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

# Rule to create object directories
$(OBJ_PATH):
	@echo "Creating object directories..."
	@mkdir -p $(OBJ_PATH)

# Rules
all: $(LIBFT) $(PRINTF) $(DPRINTF) $(NAME)

# Create .o files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@echo "Compiling $< -> $@"
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

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
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lprintf -L$(DPRINTF_PATH) -ldprintf -lreadline

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
