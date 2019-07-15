/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:35:02 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:35:05 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int			main(int ac, char **av)
{
	int status;

	if (ac != 2)
		status = error_usage(av[0]);
	else
		status = create_server(ft_atoi(av[1]));
	return (status);
}
