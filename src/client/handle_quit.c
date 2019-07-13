/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:14:43 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/12 21:15:39 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int				handle_quit(t_client *client, char *arg)
{
	(void)arg;
	printf("Disconnected from server\n");
	close(client->sockfd);
	exit (0);
	return (EXIT_SUCCESS);
}