/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:39:39 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 15:57:11 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int						handle_put(t_server *server, char *arg)
{
	char		**arr;
	int			fd;
	char		buf[1024];
	int			size;
	t_server	newc;

	arr = ft_strsplit(arg, ' ');
	if (!arr[1] || arr[2])
		return (EXIT_FAILURE);
	init_connection(&newc);
	send(server->csockfd, &newc.sin.sin_port, sizeof(newc.sin.sin_port), 0);
	send(server->csockfd, &newc.sin.sin_addr.s_addr,
	sizeof(newc.sin.sin_addr.s_addr), 0);
	newc.csockfd = accept(newc.sockfd,
	(struct sockaddr *)&newc.sin, &newc.clen);
	if ((fd = open(arr[1], O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644)) == -1)
		return (EXIT_FAILURE);
	while ((size = read(newc.csockfd, buf, sizeof(buf))) > 0)
		write(fd, buf, size);
	printf(GRN"The command put has been executed by a client\n"RESET);
	free(arr);
	close(fd);
	close(newc.sockfd);
	return (EXIT_SUCCESS);
}
