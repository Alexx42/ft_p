/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:07:57 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 16:29:06 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int				init_connection(t_server *server)
{
	socklen_t			len;

	if ((server->sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return (error_program(E_SOCKET));
	server->sin.sin_port = 0;
	server->sin.sin_family = AF_INET;
	server->sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(server->sockfd, (const struct sockaddr *)&server->sin,
	sizeof(struct sockaddr))) == -1)
		return error_program(E_BIND);
	listen(server->sockfd, 0);
	len = sizeof(struct sockaddr_in);
	getsockname(server->sockfd, (struct sockaddr *)&server->sin, &len);
	return (EXIT_SUCCESS);
}