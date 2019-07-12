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

# define PROTOCOL		"tcp"
# define E_UNKWN		"an error occured"
# define E_SOCKET		"socket failed"
# define E_BIND			"bind failed"
# define E_ACCEPT		"accept failed"

typedef struct			s_server
{
	int 				port;
	int					sockfd;
	int					csockfd;
	struct protoent		*proto;
	struct sockaddr_in	sin;
	struct sockaddr_in	csin;
	unsigned int		clen;
}						t_server;

int						error_usage(char *str);
int						error_program(char *str);
int						create_server(int port);

# endif
