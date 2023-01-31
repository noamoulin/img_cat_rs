SRCS = ft_atoi.c ft_isalpha.c ft_itoa.c ft_lstdelone.c ft_lstnew.c ft_memcpy.c ft_putchar_fd.c ft_split.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_bzero.c ft_isascii.c ft_lstadd_back.c ft_lstiter.c ft_lstsize.c ft_memmove.c ft_putendl_fd.c ft_stralloc.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_calloc.c ft_isdigit.c ft_lstadd_front.c ft_lstlast.c ft_memchr.c ft_memrchr.c ft_putnbr_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_isalnum.c ft_isprint.c ft_lstclear.c ft_lstmap.c ft_memcmp.c ft_memset.c ft_putstr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c
OBJS = $(SRCS:.c=.o)

CODE_DIR = .
SRCS_DIR = $(CODE_DIR)/srcs
OBJS_DIR = $(CODE_DIR)/objs

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_PATHS = $(addprefix $(OBJS_DIR)/, $(OBJS))

CC = clang
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS)

%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
	$(CC) -c $< $(CFLAGS) -o $(OBJS_DIR)/$@

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean : 
	rm -rf $(OBJS_DIR)

re : clean all

.PHONY : all clean re
