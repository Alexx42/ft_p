#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <libft.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

# define SUCCESS 227
# define RECV	 412
# define UNKWN_CMD 150

# define PROTOCOL		"tcp"
# define E_UNKWN		"an error occured"
# define E_CONNECT		"connect failed"
# define E_READ			"read failed"
# define E_RECV			"received failed"

typedef struct			s_client
{
	int					sockfd;
	struct sockaddr_in	sin;
	struct protoent		*proto;
}						t_client;

int						error_usage(char *str);
int						error_program(char *str);
int						create_client(char *addr, int port);

int						handle_quit(t_client *client, char *arg);
int						handle_pwd(t_client *client, char *arg);
int						handle_ls(t_client *client, char *arg);
int						handle_put(t_client *client, char *arg);

int						init_connection(t_client *client,
						unsigned short port, unsigned long s_addr);

typedef int				handle_func(t_client *, char *);

typedef struct			s_handle_fun
{
	char				*cmd;
	uint8_t				size;
	handle_func			*fn;
}						t_handle_fun;


#endif