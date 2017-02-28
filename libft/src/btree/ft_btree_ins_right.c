/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_ins_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 23:58:30 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 17:48:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_btree			*ft_btree_ins_right(t_root *btree_root, t_btree *father,
		void *key, void *data)
{
	t_btree	**position;
	t_btree	*tmp;

	if (!father)
	{
		if (btree_root->size == 0)
			position = &btree_root->root;
		else
			return (NULL);
	}
	if (father)
	{
		if (!father->right)
			position = &father->right;
		else
			return (NULL);
	}
	tmp = ft_btree_create_node(position, data, key);
	btree_root->size++;
	return (tmp);
}
