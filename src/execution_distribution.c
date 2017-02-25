/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:37:58 by ariard            #+#    #+#             */
/*   Updated: 2017/02/25 17:09:42 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_distribute_execution(t_btree *node, t_btree *father, t_info *info,
				t_root *tree, char *operand)
{
	t_entry		*entry;

	ft_putstr_fd("DISTRIBUTE EXECUTION\n", 3);
	if (ft_full_path(operand))
		return (ft_execute_cmd(operand, node, father, tree, info));
	if (operand[0] == '/')
		return (ft_existence_error("ariard", operand));
	if (ft_redir(info->prev_father))
		return (1);
	entry = ft_add_bin(operand, info);
	if (!entry) 
		return (ft_semantic_error(operand));
	else if (entry)
	{
		info->previous_path = entry->path;
		if (entry->perm == -1)
			return (ft_permission_error(operand, info->env));
		else if (entry->perm == 0)
			return (ft_execute_cmd(entry->path, node, father, tree, info)); 
	}
	return (0);	
}
