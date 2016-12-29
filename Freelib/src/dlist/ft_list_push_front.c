/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:45:52 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 20:00:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_list_push_front(t_dlist **begin_list, void *data,
		t_dlist *(*create)(void *))
{
	t_dlist	*node;

	node = (create)(data);
	if (node != 0)
	{
		node->next = *begin_list;
		*begin_list = node;
		node->previous = NULL;
	}
}
