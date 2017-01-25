/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:47:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/25 18:46:39 by ariard           ###   ########.fr       */
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
		char **env, t_info *info)
{
	char	**arg;
	pid_t	status;

	(void)father;
	arg = ft_node_argis(node);
	status = fork();
	if (status == 0)
	{
		close(1);
		dup(info->file);
		execve(path, arg, env);
	}
	if (status > 0)
		wait(0);
	return (1);
}

int			ft_redir_in(char *path, t_btree *node, t_btree *father,
		t_info *info)
{
	char	**arg;
	pid_t	status;

	(void)father;
	arg = ft_node_argis(node);
	status = fork();
	if (status == 0)
	{
		dup2(info->file, 0);
		execve(path, arg, info->env);
	}
	if (status > 0)
		wait(0);
	return (1);
}

int			ft_app_redir_out(char *path, t_btree *node, t_btree *father,
		char **env, t_info *info)
{
	char	**arg;
	pid_t	status;
	char	*line;

	(void)father;
	arg = ft_node_argis(node);
	line = NULL;
	while (get_next_line(info->file, &line));
	status = fork();
	if (status == 0)
	{
		dup2(info->file, 1);
		execve(path, arg, env);
	}
	if (status > 0)
		wait(0);
	return (1);
}
