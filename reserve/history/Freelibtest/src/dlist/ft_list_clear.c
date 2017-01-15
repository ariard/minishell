/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 15:43:15 by ariard            #+#    #+#             */
/*   Updated: 2017/01/02 20:32:19 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_list_clear(t_dlist **begin_list,
		void (*destroy)(void *))
{
	t_dlist	*tmp;

	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		destroy(*begin_list);
		*begin_list = NULL;
		*begin_list = tmp;
	}
	begin_list = NULL;
}
