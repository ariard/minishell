/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:23:08 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 19:57:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_execute_regular(char *path, t_btree *node, char **env,
		int isinpipe)
{
	char	**arg;
	pid_t	status;
	int		nb;

	arg = ft_node_argis(node);
	status = fork();
	if (status == 0)
		execve(path, arg, env);
	if (status > 0)
		wait(0);
	if (isinpipe == 1)
	{	
		close(0);
		nb = open("/dev/stdout", O_WRONLY);	
		isinpipe = 0;
	}
	return (1);
}

int			ft_execute_pipe(char *path, t_btree *node, char **env)
{
	char	**arg;
	pid_t	status;
	int		fd[2];

	arg = ft_node_argis(node);
	fd[0] = open("/dev/stdout", O_RDONLY);
	fd[1] = open("/dev/stdin", O_WRONLY);
	pipe(fd);
	status = fork();
	if (status == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(path, arg, env);
	}
	if (status > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(0);	
	}
	return (1);
}
