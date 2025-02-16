SERVER = server
CLIENT = client
CC = cc
LIBFT_DIR = libftper
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra -g -I$(LIBFT_DIR)
COBJ = $(CSRC:.c=.o)
CSRC = client.c
SOBJ = $(SSRC:.c=.o)
SSRC = server.c
GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

all: $(CLIENT) $(SERVER)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(SERVER): $(SOBJ) $(LIBFT)
		@cc  -o $(SERVER) $(SOBJ) $(LIBFT)

$(CLIENT): $(COBJ) $(LIBFT) 
		@cc  -o $(CLIENT) $(COBJ) $(LIBFT) 
clean:
	@rm -rf $(COBJ) $(SOBJ) 
	@make -C $(LIBFT_DIR) clean 

fclean: clean
	@rm -rf $(SERVER) 
	@rm -rf $(CLIENT) 
	@make -C $(LIBFT_DIR) fclean 

re: fclean $(NAME)

.PHONY: all clean fclean re