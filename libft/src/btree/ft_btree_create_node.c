/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 23:57:06 by ariard            #+#    #+#             */
/*   Updated: 2017/01/16 20:57:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_btree		*ft_btree_create_node(t_btree **position, void *data, void *key)
{
	t_btree	*node;

	node = ft_memalloc(sizeof(t_btree));
	node->data = data;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	if (position)
		*position = node;
	return (node);
}
