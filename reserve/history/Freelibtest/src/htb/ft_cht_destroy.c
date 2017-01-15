/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cht_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:43:56 by ariard            #+#    #+#             */
/*   Updated: 2017/01/04 19:43:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_cht_destroy(t_cht *htb, void (*destroy)(void *data))
{
	int		i;

	i = 0;
	while (i < htb->capacity)
		ft_list_clear(&htb->head[i++], destroy);
	free(htb->head);
	ft_memset(htb, 0, htb->capacity);
}
