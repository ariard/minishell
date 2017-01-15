/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cht_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:55:05 by ariard            #+#    #+#             */
/*   Updated: 2017/01/04 19:53:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_cht_insert(t_cht *htb, void *data, void *key,
		int (*match)(const char *key1, const char *key2))
{
	int		bucket;

	if (ft_cht_lookup(htb, key, match))
		return ;
	bucket = htb->h(key, htb->capacity);
	ft_list_push_back(&htb->head[bucket], data, key);
	htb->size++;
}
