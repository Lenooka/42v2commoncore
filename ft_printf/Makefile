NAME			=	libftprintf.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
SRC				=	ft_printf_chars.c ft_printf_nmbr.c ft_printf_up.c ft_printf.c
OBJ_DIR			=	obj
OBJS			=	$(SRC:%.c=$(OBJ_DIR)/%.o)
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
					ar rcs $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					rm -rf $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					rm -rf $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft