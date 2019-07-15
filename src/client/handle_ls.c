/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:57:17 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 17:46:37 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int				handle_ls(t_client *client, char *arg)
{
	(void)arg;
	char			buf[4096];
	unsigned short	port;
	unsigned long	s_addr;
	t_client		newc;
	size_t			r;

	ft_bzero(buf, 4096);
	if (recv(client->sockfd, &port, sizeof(unsigned short), 0) == -1)
		return (EXIT_FAILURE);
	if (recv(client->sockfd, &s_addr, sizeof(newc.sin.sin_addr.s_addr), 0) == -1)
		return (EXIT_FAILURE);
	init_connection(&newc, port, s_addr);
	if (connect(newc.sockfd, (const struct sockaddr *)&newc.sin, sizeof(newc.sin)) == -1)
		return (error_program(E_CONNECT));
	while ((r = read(newc.sockfd, buf, sizeof(buf))) > 0)
	{
		write(client->sockfd, buf, r);
	}
	close(newc.sockfd);
	return (EXIT_SUCCESS);
}