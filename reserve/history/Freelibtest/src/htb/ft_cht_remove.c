/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cht_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:00:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/02 20:38:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		*ft_cht_remove(t_cht *htb, void *data,
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
			{
				htb->size--;
				return (ft_list_rem(&htb->head[bucket], tmp));
			}
		tmp = tmp->next;
	}
	return (NULL);
}
