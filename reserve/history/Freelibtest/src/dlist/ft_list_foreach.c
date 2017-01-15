/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 16:27:08 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 19:19:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_list_foreach(t_dlist **begin_list, void (*f)(void *))
{
	while (*begin_list)
	{
		f((*begin_list)->data);
		*begin_list = (*begin_list)->next;
	}
}
