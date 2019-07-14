/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:57:17 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/13 23:01:43 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int				handle_ls(t_client *client, char *arg)
{
	(void)arg;
	char		buf[4096];
	size_t		size;

	ft_bzero(buf, 4096);
	if ((size = recv(client->sockfd, buf, 4095, 0))
		return (EXIT_FAILURE);
	buf[size] = '\0';
	write(1, buf, size);
	return (EXIT_SUCCESS);
}