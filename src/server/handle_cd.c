/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:32:33 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 22:05:26 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static int				handle_cd_helper(t_server *server, char **arr)
{
	int		i;

	if (chdir(arr[1]) != 0)
	{
		send(server->csockfd, "401", 4, 0);
		return (EXIT_FAILURE);
	}
	send(server->csockfd, "227", 4, 0);
	if (!ft_strcmp(arr[1], "./") || !ft_strcmp(arr[1], "."))
		return (EXIT_SUCCESS);
	ft_strcat(server->intial_path, arr[1]);
	ft_strcat(server->intial_path, "/");
	ft_strcat(server->path, arr[1]);
	ft_strcat(server->path, "/");
	cut_path(server->intial_path);
	cut_path(server->path);
	i = -1;
	while (server->path[++i] == '/')
		;
	if (i == (int)ft_strlen(server->path))
		server->path = "/";
	return (EXIT_SUCCESS);
}

int						handle_cd(t_server *server, char *arg)
{
	char		**arr;
	int			status;

	arr = ft_strsplit(arg, ' ');
	verify_permission(server, arr);
	status = handle_cd_helper(server, arr);
	if (status == EXIT_SUCCESS)
		printf(GRN"The command cd has been executed by a client\n"RESET);
	else
		printf(RED"The command cd has encountered an error\n"RESET);
	free_arr(arr);
	return (status);
}
