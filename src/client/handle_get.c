/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:02:22 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 17:59:31 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static int		handle_get_helper(char **arr, t_client *client)
{
	char		buf[1024];
	int			fd;
	t_client	newc;
	int			len;

	if (!arr[1] || arr[2])
		return (ARG);
	if (recv(client->sockfd, buf, 4, 0) == -1)
		return (RECV);
	if (ft_atoi(buf) != SUCCESS)
		return (FILE_ERROR);
	receive_data(&newc, client);
	if ((fd = open(arr[1], O_RDONLY | O_CREAT | O_APPEND |
	O_CREAT, 0644)) == -1)
		return (FILE_ERROR);
	while ((len = read(newc.sockfd, buf, sizeof(buf))) > 0)
		write(fd, buf, len);
	close(newc.sockfd);
	close(fd);
	return (SUCCESS);
}

int				handle_get(t_client *client, char *arg)
{
	char		**arr;
	int			status;

	arr = ft_strsplit(arg, ' ');
	status = handle_get_helper(arr, client);
	free(arr);
	return (status);
}
