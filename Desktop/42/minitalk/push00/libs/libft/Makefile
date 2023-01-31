NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

BASE_DIR = srcs/base
PRINTF_DIR = srcs/ft_printf

all:
	@make -C $(BASE_DIR)
	@make -C $(PRINTF_DIR)
	$(AR) $(NAME) $(BASE_DIR)/objs/*.o $(PRINTF_DIR)/objs/*.o

clean:
	@make clean -C $(BASE_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
