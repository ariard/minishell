/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi_execution2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:57:21 by ariard            #+#    #+#             */
/*   Updated: 2017/01/25 18:30:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_check_permission(char *path)
{
	int		fd;

	fd = open(path, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (1);
	else
		close(fd);
	return (0);
}

int			ft_execute_all_dir(t_btree *node, t_btree *father, t_info *info,
		t_root *tree)
{
	char	*path;
	t_btree	*tmp;
	int		ret;

	ret = 0;
	if (!(tmp = ft_goto_nxt_operand(node, father)))
		return (ret);
	path = ft_node_nameis(tmp);
	ft_multidir(node, father, info, tree);
	if (ft_check_permission(path) == 1 && tmp)
	{
		if (info->ismultidir == 1)
			info->ismultidir = -2;
		return(ft_file_error(path));
	}
	if (ft_isredir_out(father) && tmp)
		ft_flush(tmp);
	info->file = ft_get_fdfiles(node, father);
	if (info->ismultidir == 2)
		ret = ft_execute_operand(info->heritance, info->heritancefather, info,
			tree);
	else if (info->ismultidir == 0)
		ret = ft_execute_operand(node, father, info, tree);
	return (ret);
}
