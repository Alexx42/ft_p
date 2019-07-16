/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:38:45 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 18:03:13 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static int		handle_put_helper(t_client *client, char **arr)
{
	char		buf[1024];
	int			len;
	t_client	newc;
	int			fd;

	if (!arr[1] || arr[2])
		return (ARG);
	if ((fd = open(arr[1], O_RDONLY)) == -1)
	{
		send(client->sockfd, "401", 4, 0);
		return (FILE_ERROR);
	}
	send(client->sockfd, "227", 4, 0);
	receive_data(&newc, client);
	while ((len = read(fd, buf, sizeof(buf))) > 0)
		write(newc.sockfd, buf, len);
	close(newc.sockfd);
	return (SUCCESS);
}

int				handle_put(t_client *client, char *arg)
{
	char		**arr;
	int			status;

	arr = ft_strsplit(arg, ' ');
	status = handle_put_helper(client, arr);
	free(arr);
	return (status);
}
