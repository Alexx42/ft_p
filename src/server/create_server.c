#include <server.h>

const t_handle_fun		handle_fun[] = {
	{"quit", handle_quit}
};

static int			analyze_data(t_server *server, char *buff)
{
	int			i;

	i = -1;
	while (++i < 1)
	{
		if (!ft_strcmp(buff, handle_fun[i].cmd))
			return (handle_fun[i].fn(server, buff));
	}
	return (EXIT_FAILURE);
}

static int			receive_data(t_server *server)
{
	char	buff[1024];
	size_t 	r;

	r = 0;
	while (42)
	{
		ft_bzero(buff, 1024);
		r = recv(server->csockfd, buff, sizeof(buff), 0);
		buff[r - 1] = '\0';
		if (analyze_data(server, buff) == EXIT_SUCCESS)
			send(server->csockfd, "SUCCESS", 7, 0);
		else
			send(server->csockfd, "FAILURE", 7, 0);
	}
	return (EXIT_SUCCESS);
}

static int			launch_server(t_server *server)
{
	pid_t		new_client;

	listen(server->sockfd, 42);
	while (42)
	{
		if ((server->csockfd = accept(server->sockfd, (struct sockaddr *)&(server->csin),
		&server->clen)) == -1)
			exit (0);
		printf("Connection accepted from %s:%d\n", inet_ntoa(server->csin.sin_addr), ntohs(server->csin.sin_port));
		if ((new_client = fork()) == 0)
		{
			close(server->sockfd);
			if ((receive_data(server)) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
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
		return (error_program(E_BIND));
	status = launch_server(&server);
	close(server.sockfd);
	return (status);
}
