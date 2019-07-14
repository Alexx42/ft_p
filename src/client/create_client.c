#include <client.h>

const t_handle_fun		handle_fun[] = {
	{"ls", 2, handle_ls},
	{"pwd", 3, handle_pwd},
	{"quit", 4, handle_quit}
};

static int		analyze_data(t_client *client, char *buff)
{
	uint8_t		i;

	i = -1;
	while (++i < 3)
	{
		if (!ft_strncmp(buff, handle_fun[i].cmd, handle_fun[i].size))
			return (handle_fun[i].fn(client, buff));
	}
	return (EXIT_FAILURE);
}

static int		launch_client(t_client *client)
{
	char		buff[1024];
	size_t		r;

	while (42)
	{
		ft_bzero(buff, 1024);
		ft_putstr(RESET "Client -> ");
		r = read(0, buff, sizeof(buff));
		buff[r - 1] = '\0';
		write(client->sockfd, buff, r);
		analyze_data(client, buff);
		if (recv(client->sockfd, buff, 8, 0) < 0)
			return (error_program(E_RECV));
		else if (!ft_strcmp("SUCCESS", buff))
			ft_putendl(GRN "SUCCESS" RESET);
		else
			ft_putendl(RED "FAILURE" RESET);
	}
	return (EXIT_SUCCESS);
}

int				create_client(char *addr, int port)
{
	t_client	client;
	int			status;

	if ((client.proto = getprotobyname(PROTOCOL)) == 0)
		return (error_program(E_UNKWN));
	ft_bzero((char *)&client.sin, sizeof(client.sin));
	client.sockfd = socket(AF_INET, SOCK_STREAM, client.proto->p_proto);
	client.sin.sin_family = AF_INET;
	client.sin.sin_port = htons(port);
	client.sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(client.sockfd, (const struct sockaddr *)&client.sin,
	sizeof(client.sin)) == -1)
		return (error_program(E_CONNECT));
	status = launch_client(&client);
	close(client.sockfd);
	return (status);
}