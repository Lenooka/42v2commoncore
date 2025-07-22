NAME = megaphone
CC = c++ 
SRC = megaphone.cpp
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
OBJ_D = obj
OBJS = $(OBJ_D)/megaphone.o
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: $(NAME)

$(OBJ_D)/%.o: %.cpp | $(OBJ_D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling...$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Compiled successfully!$(RESET)"

$(OBJ_D):
	@mkdir -p $(OBJ_D)

clean:
	@$(RM) $(OBJ_D)
	@echo "$(RED)Cleaning... $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Fcleaning... $(RESET)"

re: fclean all

.PHONY: all clean fclean re