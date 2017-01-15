/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:22:30 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 16:26:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_btree_destroy(t_btree *root)
{
	if (root)
	{
		ft_btree_destroy(root->left);
		ft_btree_destroy(root->right);
		root->left = NULL;
		root->right = NULL;
		root->data = NULL;
		root->key = NULL;
		free(root);
		root = NULL;
	}
}
