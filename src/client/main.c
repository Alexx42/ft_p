/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:36:53 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:36:56 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int		main(int ac, char **av)
{
	int		status;

	if (ac != 3)
		status = error_usage(av[0]);
	else
		status = create_client(av[1], ft_atoi(av[2]));
	return (0);
}
