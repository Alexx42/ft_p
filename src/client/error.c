/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 23:36:45 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:36:49 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int		error_usage(char *str)
{
	printf("usage: %s <addr> <port>\n", str);
	return (EXIT_FAILURE);
}

int		error_program(char *str)
{
	printf("server: error: %s\n", str);
	return (EXIT_FAILURE);
}
