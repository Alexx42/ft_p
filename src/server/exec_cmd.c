/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:43:14 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/13 22:58:41 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

int 			read_fd(int fd, off_t size, int dst)
{
	char		buf[4096];

	ft_bzero(buf, 4096);
	read(fd, buf, size);
	if ((send(dst, buf, size, 0)) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				wait4_fork(pid_t pid)
{
	int			s;
	struct rusage us;

	wait4(pid, &s, 0, &us);
	if (WEXITSTATUS(s))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				exec_cmd(char *cmd, char **arg, t_server *server)
{
	pid_t		pid;
	int			status;
	struct stat buf;

	status = EXIT_SUCCESS;
	if ((pid = fork()) == 0)
	{
		dup2(server->csockfd, 1);
		close(server->csockfd);
		if (execv(cmd, arg) == -1)
			status = EXIT_FAILURE;
		exit(0);
	}
	else if (pid > 0)
	{
		if (wait4_fork(pid) == EXIT_FAILURE)
			status = 1;
		if (!status)
		{
			fstat(1, &buf);
			read_fd(1, buf.st_size, server->csockfd);
		}
	}
	else
	{
		status = EXIT_FAILURE;
	}
	return (status);
}