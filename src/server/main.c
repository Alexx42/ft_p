#include <server.h>


int			main(int ac, char **av)
{
	int status;

	status = 0;
	if (ac != 2)
		status = error_usage(av[0]);
	else
		status = create_server(ft_atoi(av[1]));
	return (status);
}
