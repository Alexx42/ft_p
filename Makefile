CLIENT = 		client
SERVER = 		server

OBJ = 			obj/
SRC = 			src/

CC = gcc
CFLAGS += 		-g3 -fsanitize=address -Wall -Werror -Wextra
CFLAGS += 		-I inc/ -I libft/

LIBFT_PATH =		libft/
LIBFT = 		libft/libft.a

SRCS_CLIENT =		main.c error.c create_client.c handle_quit.c handle_pwd.c handle_ls.c init_connection.c handle_put.c

SRCS_SERVER =		main.c error.c exec_cmd.c create_server.c handle_quit.c handle_pwd.c handle_ls.c init_connection.c handle_put.c

CLIENT_OBJ = $(addprefix $(OBJ)$(CLIENT)/, $(SRCS_CLIENT:.c=.o))
SERVER_OBJ = $(addprefix $(OBJ)$(SERVER)/, $(SRCS_SERVER:.c=.o))

all: $(CLIENT) $(SERVER)

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@echo "Compiling server..."
	@$(CC) $(CFLAGS) $(LIBFT) -o $@ $^
	@echo "Done"

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@echo "Compiling client..."
	@$(CC) $(CFLAGS) $(LIBFT) -o $@ $^
	@echo "Done"

$(SERVER_OBJ): $(OBJ)$(SERVER)/%.o: $(SRC)$(SERVER)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(CLIENT_OBJ): $(OBJ)$(CLIENT)/%.o: $(SRC)$(CLIENT)/%.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@echo "Compiling libft objects..."
	@make -C $(LIBFT_PATH)
	@echo "Done!"

clean:
	@echo "Cleaning the repo..."
	@make clean -C  $(LIBFT_PATH)
	@rm -rf $(CLIENT_OBJ)
	@rm -rf $(SERVER_OBJ)

fclean: clean
	@echo "Cleaning the repo..."
	@rm -rf $(CLIENT) $(SERVER)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

norminette:
	norminette inc/ src/
