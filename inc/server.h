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


int		error_usage(char *str);
int		create_server(int port);

# endif
