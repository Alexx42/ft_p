/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:55:06 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 17:46:04 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int				handle_ls(t_server *server, char *arg)
{
	int			status;
	char		**arr;
	t_server	newc;

	status = 0;
	init_connection(&newc);
	send(server->csockfd, &newc.sin.sin_port, sizeof(newc.sin.sin_port), 0);
	send(server->csockfd, &newc.sin.sin_addr.s_addr, sizeof(newc.sin.sin_addr.s_addr), 0);
	arr = ft_strsplit(arg, ' ');
	printf(GRN "The command ls has been executed by a client\n"RESET);
	newc.csockfd = accept(newc.sockfd, (struct sockaddr *)&newc.sin, &newc.clen);
	status = exec_cmd("/bin/ls", arr, server, &newc);
	close(newc.csockfd);
	close(newc.sockfd);
	free(arr);
	return (status);
}