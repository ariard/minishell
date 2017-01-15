/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cht_lookup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:49:20 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 22:26:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		*ft_cht_lookup(const t_cht *htb, void *data,
		int (*match)(const char *key1, const char *key2))
{
	int		bucket;
	t_dlist	*tmp;

	bucket = htb->h(data, htb->capacity);
	tmp = htb->head[bucket];
	while (tmp)
	{
		if (tmp->key)
			if (((match)(data, tmp->key)) == 0)
				return (tmp->data);
		tmp = tmp->next;
	}
	return (NULL);
}
