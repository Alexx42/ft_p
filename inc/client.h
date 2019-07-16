/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:57:35 by ale-goff          #+#    #+#             */
/*   Updated: 2019/07/15 20:32:18 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <libft.h>
# include <fcntl.h>
# include <sys/stat.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

# define SUCCESS 227
# define RECV	 412
# define CON	 413
# define ARG	 400
# define UNKWN_CMD 150
# define FILE_ERROR 401
# define PATH		414

# define PROTOCOL		"tcp"
# define E_UNKWN		"an error occured"
# define E_CONNECT		"connect failed"
# define E_READ			"read failed"
# define E_RECV			"received failed"

typedef struct			s_client
{
	int					sockfd;
	char				path[1024];
	char				init_path[1024];
	size_t				len;
	struct sockaddr_in	sin;
	struct protoent		*proto;
}						t_client;

int						error_usage(char *str);
int						error_program(char *str);
int						create_client(char *addr, int port);

int						handle_quit(t_client *client, char *arg);
int						handle_pwd(t_client *client, char *arg);
int						handle_ls(t_client *client, char *arg);
int						handle_put(t_client *client, char *arg);
int						handle_get(t_client *client, char *arg);
int						handle_cd(t_client *client, char *arg);

int						receive_data(t_client *newc, t_client *client);

int						verify_permission(t_client *client, char **arr);

int						count_directory_below(char *arr);
int						count_directory(char *arr);

typedef int				t_handle_func(t_client *client, char *arg);

typedef struct			s_handle_fun
{
	char				*cmd;
	uint8_t				size;
	t_handle_func		*fn;
}						t_handle_fun;

#endif
