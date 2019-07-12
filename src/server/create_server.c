#include <server.h>

int			launch_server(t_server *server)
{
	listen(server->sockfd, 42);
	if ((server->csockfd = accept(server->sockfd, (struct sockaddr *)&(server->csin),
	&server->clen)) == -1)
		return (error_program(E_ACCEPT));
	close(server->csockfd);
	return (EXIT_SUCCESS);
}

int			create_server(int port)
{
	t_server		server;
	int				status;

	if ((server.proto = getprotobyname(PROTOCOL)) == 0)
		return (error_program(E_UNKWN));
	if ((server.sockfd = socket(AF_INET, SOCK_STREAM, server.proto->p_proto)) == -1)
		return (error_program(E_SOCKET));
	server.sin.sin_family = AF_INET;
	server.sin.sin_port = htons(port);
	server.sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(server.sockfd, (const struct sockaddr *)&server.sin,
	sizeof(server.sin))) == -1)
	{
		perror(strerror(errno));
		return (error_program(E_BIND));
	}
	status = launch_server(&server);
	close(server.sockfd);
	return (status);
}
