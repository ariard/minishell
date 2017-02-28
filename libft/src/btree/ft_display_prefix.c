/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:40:48 by ariard            #+#    #+#             */
/*   Updated: 2017/02/13 17:11:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_display_prefix(t_btree *root)
{
	if (root)
	{
		if (root->key)
		{
			ft_putstr((char *)root->key);
			ft_putstr("\n|\n");
		}
		else
			ft_putstr("null key");
	}
	if (root->left)
		ft_display_prefix(root->left);
	if (root->right)
		ft_display_prefix(root->right);
}
