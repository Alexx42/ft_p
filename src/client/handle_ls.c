/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:57:17 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 16:09:34 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int				handle_ls(t_client *client, char *arg)
{
	char			buf[4096];
	t_client		newc;
	size_t			r;

	(void)arg;
	ft_bzero(buf, 4096);
	if (receive_data(&newc, client) == RECV)
		return (RECV);
	while ((r = read(newc.sockfd, buf, sizeof(buf))) > 0)
		write(1, buf, r);
	close(newc.sockfd);
	return (SUCCESS);
}
