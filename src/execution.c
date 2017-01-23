/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:23:08 by ariard            #+#    #+#             */
/*   Updated: 2017/01/23 17:57:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_execute_regular(char *path, t_btree *node, char **env,
	t_info *info)
{
	char	**arg;
	pid_t	status;	

	if (info->quote == 1)
		arg = ft_quoteis(node);	
	else
		arg = ft_node_argis(node);
	status = fork();
	if (status == 0)
	{
		signal(SIGINT, ft_sigint_handler_child);
		if (ft_isaggregation(arg) == 1)
			ft_execute_aggregation(arg);
		execve(path, arg, env);
	}
	if (status > 0)
		wait(0);
	if (info->pipe == 1)
		ft_close_pipe(info);
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
