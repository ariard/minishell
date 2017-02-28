/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:04:40 by ariard            #+#    #+#             */
/*   Updated: 2017/02/28 10:31:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static void			ft_list_ins_special(t_dlist **begin_list,
					t_dlist *node1, t_dlist *node2)
{
	if (!node2 || !node1)
		return ;
	else
	{
		if (!node1->previous)
			*begin_list = node2;
		else
			(node1->previous)->next = node2;
		node2->next = node1;
		node2->previous = node1->previous;
		node1->previous = node2;
	}
}

static t_dlist		*ft_list_rem_special(t_dlist **begin_list, t_dlist *node)
{
	if (!node || !*begin_list)
		return (0);
	if (node->next)
		(node->next)->previous = node->previous;
	if (node->previous)
		(node->previous)->next = node->next;
	else if (node->next)
		*begin_list = node->next;
	else
		*begin_list = NULL;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void				ft_insert_cmpsort(t_dlist **begin_list,
					int (*cmp)(const void *key1, const void *key2))
{
	t_dlist		*tmp;
	t_dlist		*tmp2;
	t_dlist		*to_sort;

	tmp = *begin_list;
	while (tmp->next)
	{
		if ((cmp)(tmp->key, (tmp->next)->key) > 0)
		{
			to_sort = ft_list_rem_special(begin_list, tmp->next);
			tmp2 = *begin_list;
			while (tmp2)
			{
				if ((cmp)(tmp2->key, to_sort->key) > 0)
				{
					ft_list_ins_special(begin_list, tmp2, to_sort);
					break ;
				}
				tmp2 = tmp2->next;
			}
		}
		else
			tmp = tmp->next;
	}
}

void				ft_insert_keysort(t_dlist **begin_list)
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
					ft_list_ins(tmp2, to_sort);
					break ;
				}
				tmp2 = tmp2->next;
			}
		}
		else
			tmp = tmp->next;
	}
}
