/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 18:01:33 by ariard            #+#    #+#             */
/*   Updated: 2017/01/04 22:20:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_dlist		*ft_list_find(t_dlist **begin_list, void *data_ref, int (*cmp)())
{
	while (*begin_list)
	{
		if (cmp((*begin_list)->data, data_ref) == 0)
			return (*begin_list);
		*begin_list = (*begin_list)->next;
	}
	return (0);
}
