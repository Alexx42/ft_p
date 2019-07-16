/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:28:41 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 20:29:47 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int		count_directory_below(char *arr)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (arr[++i])
	{
		if (!ft_strncmp(arr + i, "../", 3) || !ft_strncmp(arr + i, "..\0", 3))
		{
			i += 2;
			count++;
		}
	}
	return (count);
}

int		count_directory(char *arr)
{
	int		i;
	int		count;

	if (!ft_strcmp(arr, "/"))
		return (0);
	i = -1;
	count = 0;
	while (arr[++i])
	{
		if (arr[i] == '/')
			count++;
	}
	return (count);
}
