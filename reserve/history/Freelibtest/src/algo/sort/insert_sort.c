/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:04:40 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 20:35:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_insert_cmpsort(t_dlist **begin_list,
		int (*cmp)(const void *key1, const void *key2))
{
	t_dlist		*tmp;
	t_dlist		*tmp2;
	t_dlist		*to_sort;

	tmp = *begin_list;
	while (tmp->next)
	{
		if ((cmp)(tmp->sort, (tmp->next)->sort) > 0)
		{
			to_sort = ft_list_rem(begin_list, tmp->next);
			tmp2 = *begin_list;
			while (tmp2)
			{
				if ((cmp)(tmp2->name, to_sort->name) > 0)
				{
					ft_list_ins(begin_list, tmp2, to_sort);
					break ;
				}
				tmp2 = tmp2->next;
			}
		}
		else
			tmp = tmp->next;
	}
}

void		ft_insert_keysort(t_dlist **begin_list)
{
	t_dlist		*tmp;
	t_dlist		*tmp2;
	t_dlist		*to_sort;

	tmp = *begin_list;
	while (tmp->next)
	{
		if (tmp->key > (tmp->next)->key)
		{
			to_sort = ft_list_rem(begin_list, tmp->next);
			tmp2 = *begin_list;
			while (tmp2)
			{
				if (tmp2->key > to_sort->key)
				{
					ft_list_ins(begin_list, tmp2, to_sort);
					break ;
				}
				tmp2 = tmp2->next;
			}
		}
		else
			tmp = tmp->next;
	}
}
