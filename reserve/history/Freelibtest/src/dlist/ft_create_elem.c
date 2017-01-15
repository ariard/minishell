/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create-elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:25:53 by ariard            #+#    #+#             */
/*   Updated: 2017/01/03 18:18:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_dlist		*ft_create_elem(void *data, void *key)
{
	t_dlist	*node;

	node = 0;
	node = (t_dlist *)malloc(sizeof(t_dlist));
	if (node != 0)
	{
		node->data = data;
		node->key = key;
		node->next = NULL;
		node->previous = NULL;
	}
	return (node);
}
