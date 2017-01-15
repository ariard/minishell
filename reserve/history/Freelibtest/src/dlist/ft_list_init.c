/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:38:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 16:48:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_list_init(t_dlist **begin_list, void (*destroy)(void *data))
{
	if (destroy && *begin_list)
		destroy(*begin_list);
	begin_list = NULL;
}
