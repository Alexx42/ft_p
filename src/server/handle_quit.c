/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:21:14 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/12 20:27:01 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int			handle_quit(t_server *server, char *arg)
{
	(void)arg;
	printf("Disconnected from %s:%d\n",
	inet_ntoa(server->csin.sin_addr), ntohs(server->csin.sin_port));
	close(server->csockfd);
	exit (0);
	return (EXIT_SUCCESS);
}