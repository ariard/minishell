/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:20:46 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 20:30:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_bubble_cmpsort(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2))
{
	t_dlist		*tmp;

	tmp = *begin_list;
	while (tmp->next)
	{
		if (((cmp)(tmp->sort, (tmp->next)->sort)) < 0)
		{
			ft_list_swap(begin_list, tmp, tmp->next);
			tmp = *begin_list;
		}
		else
			tmp = tmp->next;
	}
}

void		ft_bubble_keysort(t_dlist **begin_list)
{
	t_dlist		*tmp;

	tmp = *begin_list;
	while (tmp->next)
	{
		if (tmp->key > (tmp->next)->key)
		{
			ft_list_swap(begin_list, tmp, tmp->next);
			tmp = *begin_list;
		}
		else
			tmp = tmp->next;
	}
}
