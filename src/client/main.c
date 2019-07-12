#include <client.h>

int		main(int ac, char **av)
{
	int		status;

	if (ac != 3)
		status = error_usage(av[0]);
	else
		status = create_client(av[1], ft_atoi(av[2]));
	return (0);
}
