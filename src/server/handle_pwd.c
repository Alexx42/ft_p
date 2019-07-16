/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:50:18 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 22:13:26 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static int	handle_pwd_helper(t_server *server, char **arr)
{
	t_server	newc;
	int			status;

	status = EXIT_SUCCESS;
	init_connection(&newc);
	send(server->csockfd, &newc.sin.sin_port,
	sizeof(newc.sin.sin_port), 0);
	send(server->csockfd, &newc.sin.sin_addr.s_addr,
	sizeof(newc.sin.sin_addr.s_addr), 0);
	newc.csockfd = accept(newc.sockfd, (struct sockaddr *)&newc.sin,
	&newc.clen);
	if (!arr[1] && (send(newc.csockfd, server->path,
	ft_strlen(server->path), 0)) == -1)
		status = EXIT_FAILURE;
	else if (arr[1])
		status = EXIT_FAILURE;
	close(newc.sockfd);
	close(newc.csockfd);
	return (status);
}

int			handle_pwd(t_server *server, char *arg)
{
	char		**arr;
	int	 		status;

	arr = ft_strsplit(arg, ' ');
	status = handle_pwd_helper(server, arr);
	if (status == EXIT_SUCCESS)
		printf(GRN"The command pwd has been executed by a client\n"RESET);
	else
		printf(RED"The command pwd has encountered an error\n"RESET);
	free_arr(arr);
	return (status);
}
