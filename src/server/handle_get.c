/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:02:47 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 20:31:37 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static int		handle_get_helper(t_server *server, char **arr)
{
	t_server	newc;
	char		buf[1024];
	int			size;
	int			fd;

	if (!arr[1] || arr[2])
		return (EXIT_FAILURE);
	if (!ft_strcmp(arr[1], "./") && send(server->csockfd, "401", 4, 0))
		return (EXIT_FAILURE);
	if ((fd = open(ft_strcat(server->intial_path, arr[1]), O_RDONLY)) == -1)
	{
		send(server->csockfd, "401", 4, 0);
		server->intial_path[server->len] = '\0';
		return (EXIT_FAILURE);
	}
	server->intial_path[server->len] = '\0';
	send(server->csockfd, "227", 4, 0);
	init_connection(&newc);
	accept_con(server, &newc);
	while ((size = read(fd, buf, sizeof(buf))) > 0)
		write(newc.csockfd, buf, size);
	close(fd);
	close(newc.sockfd);
	close(newc.csockfd);
	return (EXIT_SUCCESS);
}

int				handle_get(t_server *server, char *arg)
{
	int			status;
	char		**arr;

	arr = ft_strsplit(arg, ' ');
	verify_permission(server, arr);
	status = handle_get_helper(server, arr);
	if (status == EXIT_SUCCESS)
		printf(GRN"The command get has been executed by a client\n"RESET);
	else
		printf(GRN"The command get has encountered an error\n"RESET);
	free(arr);
	return (status);
}
