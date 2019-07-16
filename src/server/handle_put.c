/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:39:39 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 18:38:43 by ale-goff         ###   ########.fr       */
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
	if ((fd = open(ft_strcat(server->path, arr[1]), O_RDWR | O_CREAT
	| O_TRUNC | O_APPEND, 0644)) == -1)
	{
		server->intial_path[server->len] = '\0';
		return (EXIT_FAILURE);
	}
	server->intial_path[server->len] = '\0';
	while ((size = read(newc.csockfd, buf, sizeof(buf))) > 0)
		write(fd, buf, size);
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
	if (status == EXIT_SUCCESS)
		printf(GRN"The command put has been executed by a client\n"RESET);
	else
		printf(RED"The command put has encountered an error\n"RESET);
	free(arr);
	return (status);
}
