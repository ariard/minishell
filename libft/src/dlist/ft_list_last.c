/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 02:03:15 by ariard            #+#    #+#             */
/*   Updated: 2017/01/16 15:24:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_dlist	*ft_list_last(t_dlist **begin_list)
{
	if (*begin_list)
	{
		while ((*begin_list)->next)
			*begin_list = (*begin_list)->next;
	}
	return (*begin_list);
}
