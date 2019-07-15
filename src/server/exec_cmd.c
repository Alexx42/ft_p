/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:43:14 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/14 17:40:50 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int				wait4_fork(pid_t pid)
{
	int			s;
	struct rusage us;

	wait4(pid, &s, 0, &us);
	if (WEXITSTATUS(s))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				exec_cmd(char *cmd, char **arg, t_server *server, t_server *newc)
{
	pid_t		pid;
	int			status;

	(void)server;
	status = EXIT_SUCCESS;
	if ((pid = fork()) == 0)
	{
		dup2(newc->csockfd, 1);
		close(newc->csockfd);
		execv(cmd, arg);
		status = EXIT_FAILURE;
		exit(1);
	}
	else if (pid > 0)
	{
		if (wait4_fork(pid) == EXIT_FAILURE)
			status = 1;
	}
	else
		status = EXIT_FAILURE;
	return (status);
}