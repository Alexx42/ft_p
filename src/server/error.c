#include <server.h>


int		error_usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putstr(" <port>\n");
	return (EXIT_FAILURE);
}
