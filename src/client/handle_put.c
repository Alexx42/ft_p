/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:38:45 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 15:57:16 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int				receive_data(t_client *newc, t_client *client)
{
	unsigned short		port;
	unsigned long		s_addr;

	if (recv(client->sockfd, &port, sizeof(unsigned short), 0) == -1)
		return (RECV);
	if (recv(client->sockfd, &s_addr,
	sizeof(newc->sin.sin_addr.s_addr), 0) == -1)
		return (RECV);
	init_connection(newc, port, s_addr);
	if (connect(newc->sockfd, (const struct sockaddr *)&newc->sin,
	sizeof(newc->sin)) == -1)
		return (EXIT_FAILURE);
	return (SUCCESS);
}

int				handle_put(t_client *client, char *arg)
{
	int			fd;
	char		**arr;
	char		buf[1024];
	int			len;
	t_client	newc;

	arr = ft_strsplit(arg, ' ');
	if (!arr[1] || arr[2])
		return (ARG);
	receive_data(&newc, client);
	if ((fd = open(arr[1], O_RDONLY, 0644)) == -1)
		return (FILE_ERROR);
	while ((len = read(fd, buf, sizeof(buf))) > 0)
		write(newc.sockfd, buf, len);
	close(newc.sockfd);
	return (SUCCESS);
}
