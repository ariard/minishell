/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cht_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:40:48 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 17:19:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_cht_init(t_cht *htb, int capacity,
		int (*h)(const void *key, int size), void (*destroy)(void *data))
{
	int		i;

	(void)destroy;
	htb->head = (t_dlist **)malloc(capacity * sizeof(t_dlist *));
	i = 0;
	while (i < capacity)
	{
		ft_list_init(&htb->head[i], destroy);
		i++;
	}
	htb->capacity = capacity;
	htb->size = 0;
	htb->h = h;
}
