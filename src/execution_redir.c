/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:45:41 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 23:46:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_get_fdfiles(t_btree *node, t_btree *father)
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

static int		ft_get_fdfiles2(t_btree *node, t_btree *father)
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

int				ft_execute_redir_out(char *path, t_btree *node, t_btree *father,
		char **env)
{
	char	**arg;
	pid_t	status;
	int		files;

	arg = ft_node_argis(node);
	if ((files = ft_get_fdfiles(node, father)) == -1)
		return (-1);
	status = fork();
	if (status == 0)
	{
		close(1);
		dup(files);
		execve(path, arg, env);
	}
	if (status > 0)
		wait(0);
	return (1);
}

int			ft_execute_redir_in(char *path, t_btree *node, t_btree *father,
		char **env)
{
	char	**arg;
	pid_t	status;
	int		files;

	arg = ft_node_argis(node);
	if ((files = ft_get_fdfiles2(node, father)) == -1)
		return (-1);
	status = fork();
	if (status == 0)
	{
		dup2(files, 0);
		execve(path, arg, env);
	}
	if (status > 0)
		wait(0);
	return (1);
}
