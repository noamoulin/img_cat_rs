CFILES = render fract-ol complex mendelbrot julia main
SRCS = $(addsuffix .c, $(CFILES))
OBJS = $(addsuffix .o, $(CFILES))

CODE_DIR = code
SRCS_DIR = $(CODE_DIR)/srcs
OBJS_DIR = $(CODE_DIR)/objs

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))

MLX_PATH = $(CODE_DIR)/mlx

CC = clang
CFLAGS = -Wall -Wextra #-Werror
LINKS = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -lXext -lX11 -lm -lpthread
NAME = fract-ol

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS_PATHS) $(LINKS) -o $(NAME)

%.o : $(SRCS_DIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $(OBJS_DIR)/$@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean : 
	$(RM) $(OBJS_PATHS)
	@rmdir $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

#### REGLES PERSO ####

run : all
	@./$(NAME)

call : all
	@clear

cclean : clean
	@clear

cfclean : fclean
	@clear

cre : cfclean call

.PHONY : all clean fclean re
