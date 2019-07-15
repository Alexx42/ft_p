/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:43:14 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 23:30:53 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int				wait4_fork(pid_t pid)
{
	int					s;
	struct rusage		us;

	wait4(pid, &s, 0, &us);
	return (EXIT_SUCCESS);
}

int				exec_cmd(char *cmd, char **arg, t_server *newc)
{
	pid_t		pid;
	int			status;

	status = EXIT_SUCCESS;
	if ((pid = fork()) == 0)
	{
		dup2(newc->csockfd, 1);
		dup2(newc->csockfd, 2);
		close(newc->csockfd);
		execv(cmd, arg);
		exit(1);
	}
	else if (pid > 0)
		wait4_fork(pid);
	else
		status = EXIT_FAILURE;
	return (status);
}
