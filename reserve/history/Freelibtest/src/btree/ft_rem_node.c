/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:48:28 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 16:08:18 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static void		ft_set_father(t_root *tree, t_btree *father, t_btree *tmp)
{
	if (father->right)
		if ((tree->cmp)(tmp->key, (father->right)->key) == 0)
		{
			if (tmp->right)
				father->right = tmp->right;
			else
				father->right = tmp->left;
		}
	if (father->left)
		if ((tree->cmp)(tmp->key, (father->left)->key) == 0)
		{
			if (tmp->right)
				father->left = tmp->right;
			else
				father->left = tmp->left;
		}
}

static void		ft_set_children(t_btree *right, t_btree *left)
{
	t_btree		*tmp;
	t_btree		*previous;

	tmp = right;
	while (tmp)
	{
		previous = tmp;
		tmp = tmp->left;
	}
	previous->left = left;
}

t_btree			*ft_btree_rem_node(t_root *tree, void *key)
{
	t_btree	*father;
	t_btree	*tmp;

	father = ft_get_father(tree->root, NULL, key, tree->cmp);
	tmp = ft_get_node(tree->root, key, tree->cmp);
	if (!tmp)
		return (NULL);
	if (father)
		ft_set_father(tree, father, tmp);
	else if (!father && tmp)
	{
		if (tmp->right)
			tree->root = tmp->right;
		else
			tree->root = tmp->left;
	}
	if (tmp->left)
		if (tmp->right)
			ft_set_children(tmp->right, tmp->left);
	tmp->right = NULL;
	tmp->left = NULL;
	return (tmp);
}
