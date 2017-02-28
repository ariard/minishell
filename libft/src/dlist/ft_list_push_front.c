/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:45:52 by ariard            #+#    #+#             */
/*   Updated: 2017/01/20 16:00:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_list_push_front(t_dlist **begin_list, void *data,
		void *key)
{
	t_dlist	*node;

	node = ft_create_elem(data, key);
	if (node != 0)
	{
		node->next = *begin_list;
		*begin_list = node;
		node->previous = NULL;
		if (node->next)
			(node->next)->previous = node;
	}
}
