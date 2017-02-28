/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_get_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:40:23 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 22:00:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_btree		*ft_get_father(t_btree *root, t_btree *father, void *key,
	int (*cmp)(const char *key1, const char *key2))
{
	t_btree		*tmp;

	if (root)
		if ((cmp)(key, root->key) == 0)
			return (father);
	if (root->left)
	{
		tmp = ft_get_father(root->left, root, key, cmp);
		if (tmp)
			return (tmp);
	}
	if (root->right)
	{
		tmp = ft_get_father(root->right, root, key, cmp);
		if (tmp)
			return (tmp);
	}
	return (NULL);
}
