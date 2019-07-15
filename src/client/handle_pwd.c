/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:42:01 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:29:03 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int			handle_pwd(t_client *client, char *arg)
{
	unsigned short	port;
	unsigned long	s_addr;
	t_client		newc;
	ssize_t			r;
	char			buf[1024];

	(void)arg;
	ft_bzero(buf, sizeof(buf));
	if (recv(client->sockfd, &port, sizeof(unsigned short), 0) == -1)
		return (RECV);
	if (recv(client->sockfd, &s_addr,
	sizeof(newc.sin.sin_addr.s_addr), 0) == -1)
		return (RECV);
	init_connection(&newc, port, s_addr);
	if (connect(newc.sockfd, (const struct sockaddr *)&newc.sin,
	sizeof(newc.sin)) == -1)
		return (EXIT_FAILURE);
	if ((r = recv(newc.sockfd, buf, sizeof(buf), 0)) == -1)
		return (RECV);
	buf[r] = '\0';
	ft_putendl(buf);
	close(newc.sockfd);
	return (SUCCESS);
}
