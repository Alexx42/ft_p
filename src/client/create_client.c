#include <client.h>

int				create_client(char *addr, int port)
{
	t_client	client;

	if ((client.proto = getprotobyname(PROTOCOL)) == 0)
		return (error_program(E_UNKWN));
	client.sockfd = socket(AF_INET, SOCK_STREAM, client.proto->p_proto);
	client.sin.sin_family = AF_INET;
	client.sin.sin_port = htons(port);
	client.sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(client.sockfd, (const struct sockaddr *)&client.sin,
	sizeof(client.sin)) == -1)
		return (error_program(E_CONNECT));
	write(client.sockfd, "HELLO\n", 6);
	close(client.sockfd);
	return (EXIT_SUCCESS);
}