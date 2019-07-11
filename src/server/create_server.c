#include <server.h>

int			create_server(int port)
{
	t_server		server;

	if ((server.proto = getprotobyname(PROTOCOL)) == 0)
		return (error_program(E_UNKWN));
	if ((server.sockfd = socket(AF_INET, SOCK_STREAM, server.proto->p_proto)) == -1)
		return (error_program(E_SOCKET));
	server.sin.sin_family = AF_INET;
	server.sin.sin_port = htonl(port);
	server.sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(server.sockfd, (const struct sockaddr *)&server.sin,
	sizeof(server.sin))) == -1)
		return (error_program(E_BIND));
	close(server.sockfd);
	return (EXIT_SUCCESS);
}
