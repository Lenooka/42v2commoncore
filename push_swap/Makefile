NAME = push_swap
CC = cc
SRCS = print_utils.c utils2.c utils.c sort_three_five.c sort_lis.c operations.c operations3.c operations2.c init_check.c free_handle.c rot_choice.c sort_push.c main.c
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
OBJ_DIR = obj
OBJS = $(OBJ_DIR)/print_utils.o $(OBJ_DIR)/utils2.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/sort_three_five.o \
       $(OBJ_DIR)/sort_lis.o $(OBJ_DIR)/operations.o $(OBJ_DIR)/operations3.o $(OBJ_DIR)/operations2.o \
       $(OBJ_DIR)/init_check.o $(OBJ_DIR)/free_handle.o $(OBJ_DIR)/rot_choice.o $(OBJ_DIR)/sort_push.o \
       $(OBJ_DIR)/main.o
LIBFT_PATH = ./libftp/
LIBFT_LIB = $(LIBFT_PATH)libft.a
LFLAGS = -L$(LIBFT_PATH) -lft -lreadline
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling...$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "$(GREEN)Linking ...$(RESET)"
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) 
	@echo "$(GREEN)Compiled successfully!$(RESET)"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Cleaning...$(RESET)"
	@make clean -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "$(GREEN)Done!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH) > /dev/null 2>&1
	@echo "$(RED)Fcleaning...$(RESET)"
	@echo "$(GREEN)Done!$(RESET)"

re: fclean all

.PHONY: all clean fclean re libftp

