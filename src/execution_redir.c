/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:47:35 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 18:20:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_get_fdfiles(t_btree *node, t_btree *father)
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

int			ft_get_fdfiles2(t_btree *node, t_btree *father)
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

int			ft_redir_out(char *path, t_btree *node, t_btree *father,
			t_info *info)
{
	char	**arg;
	pid_t	status;

	if (!node || !path)
		return (0);
	arg = ft_getarg(node, info);
	if (ft_builtin(ft_node_nameis(node), arg, info))
		status = -1;
	else
		status = fork();
	if (status == 0)
	{
		signal(SIGINT, ft_sigint_handler_child);
		if (ft_isfddir(arg))
			ft_fddir(arg, info, 0);
		info->file = ft_get_fdfiles(node, father);
		dup2(info->file, 1);
		execve(path, arg, info->env);
	}
	if (status > 0)
		waitpid(status, 0, WUNTRACED | WCONTINUED);
	ft_exit_redir(info, arg);
	return (1);
}

int			ft_redir_in(char *path, t_btree *node, t_btree *father,
		t_info *info)
{
	char	**arg;
	pid_t	status;

	if (!node || !path)
		return (0);
	arg = ft_getarg(node, info);
	if (ft_builtin(ft_node_nameis(node), arg, info))
		status = -1;
	else
		status = fork();
	if (status == 0)
	{
		signal(SIGINT, ft_sigint_handler_child);
		if (ft_isfddir(arg))
			ft_fddir(arg, info, 1);
		info->file = ft_get_fdfiles2(node, father);
		dup2(info->file, 0);
		execve(path, arg, info->env);
	}
	if (status > 0)
		waitpid(status, 0, WUNTRACED | WCONTINUED);
	ft_exit_redir(info, arg);
	return (1);
}

int			ft_app_redir_out(char *path, t_btree *node, t_btree *father,
		t_info *info)
{
	char	**arg;
	pid_t	status;

	if (!node || !path)
		return (0);
	arg = ft_getarg(node, info);
	if (ft_builtin(ft_node_nameis(node), arg, info))
		status = -1;
	else
		status = fork();
	if (status == 0)
	{
		signal(SIGINT, ft_sigint_handler_child);
		if (ft_isfddir(arg))
			ft_fddir(arg, info, 0);
		info->file = ft_get_fdfiles(node, father);
		ft_read_file(info);
		dup2(info->file, 1);
		execve(path, arg, info->env);
	}
	if (status > 0)
		waitpid(status, 0, WUNTRACED | WCONTINUED);
	ft_exit_redir(info, arg);
	return (1);
}
