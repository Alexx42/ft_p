#include <server.h>

int		error_usage(char *str)
{
	printf("usage: %s <addr> <port>\n", str);
	return (EXIT_FAILURE);
}

int		error_program(char *str)
{
	printf("server: error: %s\n", str);
	return (EXIT_FAILURE);
}
