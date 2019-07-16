/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:42:01 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 22:16:44 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static int	handle_pwd_helper(t_client *client, char **arr)
{
	t_client		newc;
	ssize_t			r;
	char			buf[1024];

	ft_bzero(buf, sizeof(buf));
	if (receive_data(&newc, client) == RECV)
		return (RECV);
	if ((r = recv(newc.sockfd, buf, sizeof(buf), 0)) == -1)
		return (RECV);
	buf[r] = '\0';
	if (!arr[1])
	{
		ft_putendl(buf);
		return (SUCCESS);
	}
	close(newc.sockfd);
	return (ARG);
}

int			handle_pwd(t_client *client, char *arg)
{
	int				status;
	char			**arr;

	arr = ft_strsplit(arg, ' ');
	status = handle_pwd_helper(client, arr);
	free_arr(arr);
	return (status);
}
