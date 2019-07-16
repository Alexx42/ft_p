/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:42:01 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 16:10:03 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int			handle_pwd(t_client *client, char *arg)
{
	t_client		newc;
	ssize_t			r;
	char			buf[1024];

	(void)arg;
	ft_bzero(buf, sizeof(buf));
	if (receive_data(&newc, client) == RECV)
		return (RECV);
	if ((r = recv(newc.sockfd, buf, sizeof(buf), 0)) == -1)
		return (RECV);
	buf[r] = '\0';
	ft_putendl(buf);
	close(newc.sockfd);
	return (SUCCESS);
}
