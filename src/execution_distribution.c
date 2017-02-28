/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:37:58 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:29:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_distribute_execution(t_btree *node, t_btree *father,
				t_info *info, t_root *tree)
{
	t_entry		*entry;
	int			ret;

	ret = 0;
	entry = NULL;
	if (ft_full_path(info->generic))
		ret = ft_execute_cmd(node, father, tree, info);
	else if (ft_redir(info->prev_father))
		ret = 1;
	if (ret == 0)
		entry = ft_add_bin(info->generic, info);
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
