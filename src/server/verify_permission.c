/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_permission.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:16:17 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 22:01:37 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static void		cut_path_helper2(char *arr, int s, int e)
{
	s++;
	while (arr[e])
	{
		arr[s] = arr[e];
		s++;
		e++;
	}
	arr[s] = '\0';
}

static void		cut_path_helper(char *arr, int i)
{
	int i_tmp;

	i_tmp = i - 3;
	while (--i_tmp >= 0)
	{
		if (arr[i_tmp] == '/')
			break ;
	}
	i_tmp == -1 ? i_tmp++ : 0;
	if (ft_strncmp(arr + i_tmp, "../", 3) && ft_strncmp(arr + i_tmp, "..\0", 3))
		cut_path_helper2(arr, i_tmp, i);
}

void			cut_path(char *arr)
{
	int			i;

	i = -1;
	while (arr[++i])
	{
		if ((!ft_strncmp(arr + i, "../", 3) ||
		!ft_strncmp(arr + i, "..\0", 3)) && i >= 3)
			cut_path_helper(arr, i + 2);
	}
}

int				verify_permission(t_server *server, char **arr)
{
	int		i;
	int		count;

	i = 0;
	(void)server;
	while (arr[++i])
	{
		cut_path(arr[1]);
		count = count_directory_below(arr[1]);
		if (arr[i][0] == '/')
			arr[i] += 1;
		else if (count > count_directory(server->path))
			arr[i] = "./";
	}
	return (EXIT_SUCCESS);
}
