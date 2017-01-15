/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_get_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:40:23 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 16:39:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_btree		*ft_get_node(t_btree *root, void *key,
	int (*cmp)(const char *key1, const char *key2))
{
	t_btree		*tmp;

	if (root)
		if ((cmp)(key, root->key) == 0)
			return (root);
	if (root->left)
	{
		tmp = ft_get_node(root->left, key, cmp);
		if (tmp)
			return (tmp);
	}
	if (root->right)
	{
		tmp = ft_get_node(root->right, key, cmp);
		if (tmp)
			return (tmp);
	}
	return (NULL);
}
