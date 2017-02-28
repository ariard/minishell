/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_sort_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:24:57 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:52:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_btree		*ft_btree_sort_ins(t_root *tree, void *data, void *key)
{
	t_btree *tmp;

	if (tree->root == NULL)
		tree->root = ft_btree_create_node(NULL, data, key);
	else
	{
		tmp = tree->root;
		while (1)
		{
			while ((tree->cmp)(tmp->key, key) < 0)
			{
				if (tmp->left == NULL)
					return (ft_btree_create_node(&tmp->left, data, key));
				tmp = tmp->left;
			}
			if (tmp->right)
				tmp = tmp->right;
			else
				return (ft_btree_create_node(&tmp->right, data, key));
		}
	}
	return (NULL);
}
