/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 22:23:08 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 17:18:19 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_execute_regular(char *path, t_btree *node, t_info *info)
{
	char	**arg;
	pid_t	status;

	if (!node || !path)
		return (0);
	if (info->quote == 1)
		arg = ft_quoteis(node);
	else
		arg = ft_node_argis(node);
	if (ft_builtin(ft_node_nameis(node), arg, info))
		status = -1;
	else
		status = fork();
	if (status == 0)
	{
		signal(SIGINT, ft_sigint_handler_child);
		execve(path, arg, info->env);
	}
	if (status > 0)
		waitpid(status, 0, WUNTRACED | WCONTINUED);
	if (info->pipe == 1)
		ft_close_pipe(info);
	if (arg)
		ft_tabdel(arg);
	return (1);
}

char		**ft_getarg(t_btree *node, t_info *info)
{
	if (info->quote == 1)
		return (ft_quoteis(node));
	else
		return (ft_node_argis(node));
}

void		ft_exit_redir(t_info *info, char **arg)
{
	if (info->pipe == 1)
		ft_close_pipe(info);
	if (arg)
		ft_tabdel(arg);
}

void		ft_read_file(t_info *info)
{
	char	*line;

	while (get_next_line(info->file, &line))
		;
}

int			ft_execute_pipe(char *path, t_btree *node, t_info *info)
{
	char	**arg;
	pid_t	status;
	int		fd[2];

	arg = ft_getarg(node, info);
	pipe(fd);
	status = fork();
	if (status == 0)
	{
		signal(SIGINT, ft_sigint_handler_child);
		close(fd[0]);
		dup2(fd[1], 1);
		if (ft_builtin(ft_node_nameis(node), arg, info))
			exit(0);
		else
			execve(path, arg, info->env);
	}
	if (status > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	info->status = status;
	if (arg)
		ft_tabdel(arg);
	return (1);
}
