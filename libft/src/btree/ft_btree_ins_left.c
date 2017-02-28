/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_ins_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 23:57:53 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 17:47:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_btree			*ft_btree_ins_left(t_root *tree, t_btree *father,
	void *key, void *data)
{
	t_btree	**position;
	t_btree	*tmp;

	if (!father)
	{
		if (tree->size == 0)
			position = &tree->root;
		else
			return (NULL);
	}
	if (father)
	{
		if (!father->left)
			position = &father->left;
		else
			return (NULL);
	}
	tmp = ft_btree_create_node(position, data, key);
	tree->size++;
	return (tmp);
}
