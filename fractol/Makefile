NAME = fractol
CC = cc
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g
MLX_FLAGS = -lmlx -lX11 -lXext
LIBFT_PATH = libftp/
LIBFT_LIB = $(LIBFT_PATH)libft.a
LFLAGS = -Llibftp/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH) > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LFLAGS) -o fractol $(OBJS) $(LIBFT_LIB)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_PATH) > /dev/null 2>&1
	make fclean -C $(LIBFT_PATH) > /dev/null 2>&1

fclean: clean
	rm -rf fractol

re: fclean all

.PHONY: all clean fclean re libftp