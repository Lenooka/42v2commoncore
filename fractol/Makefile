NAME = fractol
CC = cc
SRCS = main.c atoi_float.c exit_clear.c zoom_handle.c color_utils.c cla_check.c mandelbrot_start.c  start_julia.c
CFLAGS = -Werror -Wall -Wextra -g 
RM = rm -rf
OBJ_DIR = obj
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/cla_check.o $(OBJ_DIR)/mandelbrot_start.o $(OBJ_DIR)/start_julia.o $(OBJ_DIR)/atoi_float.o $(OBJ_DIR)/exit_clear.o $(OBJ_DIR)/zoom_handle.o $(OBJ_DIR)/color_utils.o
MLX_FLAGS = -lmlx -lX11 -lXext -lm
LIBFT_PATH = libftper/
LIBFT_LIB = $(LIBFT_PATH)libft.a
LFLAGS = -L$(LIBFT_PATH) -lft
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling... $(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "$(GREEN)Linking... $(RESET)"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	@echo "$(GREEN)Compiled successfully!$(RESET)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Cleaning... $(RESET)"
	@make clean -C $(LIBFT_PATH) > /dev/null 2>&1

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "$(RED)Fcleaning... $(RESET)"

re: fclean all

.PHONY: all clean fclean re libftp
