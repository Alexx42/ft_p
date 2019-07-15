#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

# define PROTOCOL		"tcp"
# define E_UNKWN		"an error occured"
# define E_SOCKET		"socket failed"
# define E_BIND			"bind failed"
# define E_ACCEPT		"accept failed"

typedef struct			s_server
{
	int					sockfd;
	int					csockfd;
	unsigned int		clen;
	char				*path;
	char				intial_path[1024];
	struct protoent		*proto;
	struct sockaddr_in	sin;
	struct sockaddr_in	csin;
}						t_server;

int						error_usage(char *str);
int						error_program(char *str);
int						create_server(int port);

int						handle_quit(t_server *server, char *arg);
int						handle_pwd(t_server *server, char *arg);
int						handle_ls(t_server *client, char *arg);


int						exec_cmd(char *cmd, char **arg, t_server *newc);

int						init_connection(t_server *server);

int						verify_permission(t_server *server, char **arr);

typedef int				handle_func(t_server *, char *);

typedef struct			s_handle_fun
{
	char				*cmd;
	uint8_t				size;
	handle_func			*fn;
}						t_handle_fun;



# endif
