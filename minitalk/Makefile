SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)
RM = rm -rf
OBJ_DIR = obj
LIBFT_DIR = libftper
LIBFT = $(LIBFT_DIR)/libft.a
LFLAGS = -L$(LIBFT_DIR) -lft

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(OBJ_DIR)/server.o
OBJS_CLIENT = $(OBJ_DIR)/client.o

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: $(CLIENT) $(SERVER)

$(OBJ_DIR)/server.o: server.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c server.c -o $(OBJ_DIR)/server.o
	@echo "$(GREEN)Compiling server... $(RESET)"

$(OBJ_DIR)/client.o: client.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c client.c -o $(OBJ_DIR)/client.o
	@echo "$(GREEN)Compiling client... $(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null 2>&1

$(CLIENT) $(SERVER): $(OBJS_SERVER) $(OBJS_CLIENT) $(LIBFT)
	@echo "$(GREEN)Linking... $(RESET)"
	@$(CC) $(CFLAGS) -o server $(OBJS_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) -o client $(OBJS_CLIENT) $(LIBFT)
	@echo "$(GREEN)Compiled successfully!$(RESET)"


clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Cleaning... $(RESET)"
	@make clean -C $(LIBFT_DIR) > /dev/null 2>&1

fclean: clean
	@$(RM) server client
	@make fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(RED)Fcleaning... $(RESET)"

re: fclean all

.PHONY: all clean fclean re