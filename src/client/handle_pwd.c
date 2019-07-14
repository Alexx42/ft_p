/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:42:01 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/13 17:28:03 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int			handle_pwd(t_client *client, char *arg)
{
	ssize_t		r;
	size_t		len;
	char		buf[1024];

	(void)arg;
	ft_bzero(buf, sizeof(buf));
	if (recv(client->sockfd, &len, sizeof(size_t), 0) == -1)
		return (EXIT_FAILURE);
	if ((r = recv(client->sockfd, buf, len, 0)) == -1)
	{
		write(2, "NO DATA RECEIVED\n", 17);
		return (EXIT_FAILURE);
	}
	buf[r] = '\0'; 
	ft_putendl(buf);
	return (EXIT_SUCCESS);
}