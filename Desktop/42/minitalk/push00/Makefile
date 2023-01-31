CLIENT_PATH = srcs/client
SERVER_PATH = srcs/server

CLIENT = client
SERVER = server
NAME = minitalk
LIBFT = libs/libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER) : 
	@make -C $(SERVER_PATH) $(SERVER)
	@cp $(SERVER_PATH)/$(SERVER) .
	@clear

$(CLIENT) : 
	@make -C $(CLIENT_PATH) $(CLIENT)
	@cp $(CLIENT_PATH)/$(CLIENT) .
	@clear

$(LIBFT) :
	@make all -C libs/libft
	@clear

clean :
	@make clean -C $(CLIENT_PATH)
	@make clean -C $(SERVER_PATH)
	@make clean -C libs/libft
	@clear

fclean :
	@make fclean -C $(CLIENT_PATH)
	@make fclean -C $(SERVER_PATH)
	@make fclean -C libs/libft
	@rm -f $(SERVER) $(CLIENT)
	@clear

re : fclean all