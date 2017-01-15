/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:57:22 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 19:34:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_list_swap(t_dlist **begin_list, t_dlist *node1, t_dlist *node2)
{
	if (!node1 || !node2)
		return ;
	if (node2->next)
		(node2->next)->previous = node1;
	if (node1->previous)
		(node1->previous)->next = node2;
	else
		*begin_list = node2;
	node2->previous = node1->previous;
	node1->next = node2->next;
	node2->next = node1;
	node1->previous = node2;
}
