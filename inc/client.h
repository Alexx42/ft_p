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

# define PROTOCOL		"tcp"
# define E_UNKWN		"an error occured"
# define E_CONNECT		"connect failed"

typedef struct			s_client
{
	int					sockfd;
	struct sockaddr_in	sin;
	struct protoent		*proto;
}						t_client;

int						error_usage(char *str);
int						error_program(char *str);
int						create_client(char *addr, int port);

#endif