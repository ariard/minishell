/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:37:58 by ariard            #+#    #+#             */
/*   Updated: 2017/02/28 14:45:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_derr(char *str)
{
	ft_putstr_fd("ariard: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": is a directory\n", 2);
	return (1);
}

int				ft_distribute_execution(t_btree *node, t_btree *father,
				t_info *info, t_root *tree)
{
	t_entry		*entry;
	int			ret;

	ret = 0;
	if (ft_full_path(info->generic))
		ret = ft_execute_cmd(node, father, tree, info);
	ret = (ft_isdir(info->generic) && ret == 0) ? ft_derr(info->generic) : ret;
	ret = (ft_redir(info->prev_father) && ret == 0) ? 1 : ret;
	entry = (ret == 0) ? ft_add_bin(info->generic, info) : NULL;
	if (!entry && ret == 0 && open(info->generic, O_RDONLY) > 0)
		ret = ft_error_access(info->generic);
	if (!entry && ret == 0)
		ret = ft_semantic_error(info->generic, info);
	else if (entry)
	{
		info->previous_path = entry->path;
		ft_strdel(&info->generic);
		info->generic = entry->path;
		if (entry->perm == -1)
			return (ret = ft_permission_error(info->generic, info->env));
		else if (entry->perm == 0)
			return (ret = ft_execute_cmd(node, father, tree, info));
	}
	ft_strdel(&info->generic);
	return (0);
}
