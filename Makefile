NAME = minitalk

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CLIENT_FILE = mandatory/client.c

SERVER_FILE = mandatory/server.c

CLIENT_EXEC = client

SERVER_EXEC = server

all : $(NAME)

$(NAME) : $(CLIENT_EXEC) $(SERVER_EXEC)

$(CLIENT_EXEC) : ft_printf/libftprintf.a libft/libft.a $(CLIENT_FILE)
	$(CC) $(CFLAGS) $(CLIENT_FILE) -Lft_printf -lftprintf -Llibft -lft -o $(CLIENT_EXEC)

libft/libft.a :
	$(MAKE) -C libft bonus

ft_printf/libftprint.a :
	$(MAKE) -C ft_printf

clean :
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean

fclen : clean
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean

re : fclean all

.PHONY : all clean fclean re