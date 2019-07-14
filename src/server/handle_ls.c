/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:55:06 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/13 21:10:53 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int				handle_ls(t_server *server, char *arg)
{
	int		status;
	char	**arr;

	status = 0;
	arr = ft_strsplit(arg, ' ');
	printf(GRN "The command ls has been executed by a client\n"RESET);
	status = exec_cmd("/bin/ls", arr, server);
	free(arr);
	return (status);
}