/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_permission.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:16:17 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 18:16:33 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int				verify_permission(t_server *server, char **arr)
{
	int		i;

	i = 0;
	while (arr[++i])
	{
		if (!ft_strncmp(arr[i], "..", 2) && !ft_strcmp(server->path, "/"))
			arr[i] = ".";
	}
	return (EXIT_SUCCESS);
}