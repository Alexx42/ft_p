/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:39:39 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 18:01:46 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static int				handle_put_server(t_server *server, char **arr)
{
	int			fd;
	char		buf[1024];
	int			size;
	t_server	newc;

	if (!arr[1] || arr[2])
		return (EXIT_FAILURE);
	if (recv(server->csockfd, buf, 4, 0) == -1)
		return (EXIT_FAILURE);
	if (ft_atoi(buf) != 227)
		return (EXIT_FAILURE);
	init_connection(&newc);
	accept_con(server, &newc);
	if ((fd = open(arr[1], O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644)) == -1)
		return (EXIT_FAILURE);
	while ((size = read(newc.csockfd, buf, sizeof(buf))) > 0)
		write(fd, buf, size);
	printf(GRN"The command put has been executed by a client\n"RESET);
	close(fd);
	close(newc.sockfd);
	return (EXIT_SUCCESS);
}

int						handle_put(t_server *server, char *arg)
{
	char		**arr;
	int			status;

	arr = ft_strsplit(arg, ' ');
	status = handle_put_server(server, arr);
	free(arr);
	return (status);
}
