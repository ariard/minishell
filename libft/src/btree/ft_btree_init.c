/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 23:56:27 by ariard            #+#    #+#             */
/*   Updated: 2017/02/13 17:07:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_btree_init(t_root *btree_root,
		int (*cmp) (const char *key1, const char *key2))
{
	btree_root->cmp = cmp;
	btree_root->size = 0;
	btree_root->root = NULL;
}
