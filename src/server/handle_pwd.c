/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:50:18 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/13 17:37:48 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int			handle_pwd(t_server *server, char *arg)
{
	(void)arg;
	size_t		len;

	len = ft_strlen(server->path);
	if ((send(server->csockfd, &len, sizeof(size_t), 0)) == -1)
		return (EXIT_FAILURE);
	if ((send(server->csockfd, server->path, ft_strlen(server->path), 0)) == -1)
		return (EXIT_FAILURE);
	printf(GRN"The command pwd has been executed by a client\n"RESET);
	return (EXIT_SUCCESS);
}