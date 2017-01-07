/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:23:08 by ariard            #+#    #+#             */
/*   Updated: 2017/01/07 18:23:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_execute_regular(char *path, t_btree *node, char **env)
{
	char	**arg;
	pid_t	status;

	arg = ft_node_argis(node);
	status = fork();
	if (status == 0)
		execve(path, arg, env);
	if (status > 0)
		wait(0);
	return (1);
}

int			ft_execute_pipe(char *path, t_btree *node, char **env)
{
	(void)path;
	(void)node;
	(void)env;
	return (1);
}

/*void		ft_execute_cmd(char	*path, t_btree *node, t_btree *father, 
		char **env)
{
	char	**arg;
	pid_t	status;
	int		fd[2];
	static int	i;

	(void)father;
	if (!i)
		i = 0;
	arg = ft_node_argis(node);
	if (i == 0)
	{
	fd[0] = open("/dev/stdout", O_RDONLY);
	fd[1] = open("/dev/stdin", O_WRONLY);
	pipe(fd);
	status = fork();
	if (status == 0)
	{
		close(fd[0]);
		close(1);
		dup(fd[1]);
		execve(path, arg, env);
	}
	if (status > 0)
	{
		wait(0);
		close(fd[1]);
		close(0);
		dup(fd[0]);
	}
	}
	if (i > 0)
		execve(path, arg, env);
	i++;
}*/
