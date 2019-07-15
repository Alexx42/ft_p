/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:39:39 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:44:33 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int						handle_put(t_server *server, char *arg)
{
	char		**arr;
	t_server	newc;
	int			fd;

	arr = ft_strsplit(arg, ' ');
	fd = open(arr[1], O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0644);
	init_connection(&newc);
	send(server->csockfd, &newc.sin.sin_port,
	sizeof(newc.sin.sin_port), 0);
	send(server->csockfd, &newc.sin.sin_addr.s_addr,
	sizeof(newc.sin.sin_addr.s_addr), 0);
	accept(newc.sockfd, (struct sockaddr *)&newc.sin,
	&newc.clen);
	
	free(arr);
	return (EXIT_SUCCESS);
}