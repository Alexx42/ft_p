/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:32:45 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 20:50:56 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static int				handle_cd_helper(t_client *client, char **arr)
{
	char		buf[1024];

	if (!arr[1] || arr[2])
		return (ARG);
	if ((recv(client->sockfd, buf, 4, 0)) == -1)
		return (RECV);
	return (ft_atoi(buf));
}

int						handle_cd(t_client *client, char *arg)
{
	int		status;
	char	**arr;

	arr = ft_strsplit(arg, ' ');
	status = handle_cd_helper(client, arr);
	free(arr);
	return (status);
}