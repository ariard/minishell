/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:13:50 by ariard            #+#    #+#             */
/*   Updated: 2016/11/28 14:19:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_list_reverse(t_dlist **begin_list)
{
	t_dlist		*current;
	t_dlist		*tmp1;
	t_dlist		*tmp2;

	current = *begin_list;
	while (current)
	{
		tmp1 = current->next;
		current->next = current->previous;
		current->previous = current;
		tmp2 = current;
		current = tmp1;
	}
	*begin_list = tmp2;
}
