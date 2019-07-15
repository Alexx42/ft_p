/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:15:03 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:31:18 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int				init_connection(t_client *client, unsigned short port,
				unsigned long s_addr)
{
	client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	client->sin.sin_family = AF_INET;
	client->sin.sin_port = port;
	client->sin.sin_addr.s_addr = s_addr;
	return (EXIT_SUCCESS);
}
