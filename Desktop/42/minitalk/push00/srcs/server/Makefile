CFILES = server main
SRCS = $(addsuffix .c, $(CFILES))
OBJS = $(addsuffix .o, $(CFILES))

CODE_DIR = .
SRCS_DIR = $(CODE_DIR)/srcs
OBJS_DIR = $(CODE_DIR)/objs

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = server

LIBFT_PATH = ../../libs/libft
LINKS = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS_PATHS) $(LINKS) -o $(NAME)
		@clear

%.o : $(SRCS_DIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $(OBJS_DIR)/$@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean : 
	@rm -rf $(OBJS_DIR)
	@clear

fclean : clean
	$(RM) $(NAME)
	@clear

re : fclean all

.PHONY : all clean fclean re
