/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:51 by ariard            #+#    #+#             */
/*   Updated: 2016/11/28 14:41:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void			ft_list_cycle(t_dlist **begin_list)
{
	t_dlist		*tmp;

	tmp = ft_list_last(begin_list);
	tmp->next = *begin_list;
	(*begin_list)->previous = tmp;
}
