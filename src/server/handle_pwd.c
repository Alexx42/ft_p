/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:50:18 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:30:12 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int			handle_pwd(t_server *server, char *arg)
{
	t_server	newc;
	char		**arr;

	(void)arg;
	arr = ft_strsplit(arg, ' ');
	init_connection(&newc);
	send(server->csockfd, &newc.sin.sin_port,
	sizeof(newc.sin.sin_port), 0);
	send(server->csockfd, &newc.sin.sin_addr.s_addr,
	sizeof(newc.sin.sin_addr.s_addr), 0);
	newc.csockfd = accept(newc.sockfd, (struct sockaddr *)&newc.sin,
	&newc.clen);
	if (!arr[1] && (send(newc.csockfd, server->path,
	ft_strlen(server->path), 0)) == -1)
		return (EXIT_FAILURE);
	else if (arr[1])
		send(newc.csockfd, "pwd: too many arguments", 23, 0);
	printf(GRN"The command pwd has been executed by a client\n"RESET);
	free(arr);
	close(newc.sockfd);
	close(newc.csockfd);
	return (EXIT_SUCCESS);
}
