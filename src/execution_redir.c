/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:47:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/27 16:10:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_get_fdfiles(t_btree *node, t_btree *father)
{
	t_btree		*tmp;
	char		*files;
	int			fd;
	mode_t		mode;

	if (!father)
		return (-1);
	tmp = ft_goto_nxt_operand(node, father);
	files = ft_node_nameis(tmp);
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if ((fd = open(files, O_CREAT | O_RDWR, mode)) == -1)
		return (-1);
	return (fd);
}

int		ft_get_fdfiles2(t_btree *node, t_btree *father)
{
	t_btree		*tmp;
	char		*files;
	int			fd;
	mode_t		mode;

	if (!father)
		return (-1);
	tmp = ft_goto_nxt_operand(node, father);
	files = ft_node_nameis(tmp);
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if ((fd = open(files, O_RDWR, mode)) == -1)
		return (-1);
	return (fd);
}

int				ft_redir_out(char *path, t_btree *node, t_btree *father,
		t_info *info)
{
	char	**arg;
	pid_t	status;

	(void)father;
	if (info->quote == 1)
		arg = ft_quoteis(node);
	else
		arg = ft_node_argis(node);
	status = fork();
	if (ft_builtin(node, info->env))
		status = -1;
	else
		status = fork();
	if (status == 0)
	{
		if (ft_isaggregation(arg) == 1)
			ft_execute_aggregation(arg);
		if (ft_isfddir(arg))
			ft_fddir(arg, info, 0);
		close(1);
		dup(info->file);
		execve(path, arg, info->env);
	}
	if (status > 0)
		wait(0);
	if (info->pipe == 1)
		ft_close_pipe(info);
	return (1);
}

int			ft_redir_in(char *path, t_btree *node, t_btree *father,
		t_info *info)
{
	char	**arg;
	pid_t	status;

	(void)father;
	if (info->quote == 1)
		arg = ft_quoteis(node);
	else
		arg = ft_node_argis(node);
	if (ft_builtin(node, info->env))
		status = -1;
	else
		status = fork();
	if (status == 0)
	{
		if (ft_isaggregation(arg) == 1)
			ft_execute_aggregation(arg);
		if (ft_isfddir(arg))
			ft_fddir(arg, info, 1);
		dup2(info->file, 0);
		execve(path, arg, info->env);
	}
	if (status > 0)
		wait(0);
	if (info->pipe == 1)
		ft_close_pipe(info);
	return (1);
}

int			ft_app_redir_out(char *path, t_btree *node, t_btree *father,
		t_info *info)
{
	char	**arg;
	pid_t	status;
	char	*line;

	(void)father;
	if (info->quote == 1)
		arg = ft_quoteis(node);
	else
		arg = ft_node_argis(node);
	line = NULL;
	while (get_next_line(info->file, &line));
	if (ft_builtin(node, info->env))
		status = -1;
	else
		status = fork();
	if (status == 0)
	{
		if (ft_isaggregation(arg) == 1)
			ft_execute_aggregation(arg);
		if (ft_isfddir(arg))
			ft_fddir(arg, info, 0);
		dup2(info->file, 1);
		execve(path, arg, info->env);
	}
	if (status > 0)
		wait(0);
	if (info->pipe == 1)
		ft_close_pipe(info);
	return (1);
}
