/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_postfix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:07:52 by ariard            #+#    #+#             */
/*   Updated: 2017/02/13 17:18:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void		ft_apply_postfix(t_btree *root, void (*apply)(void *))
{
	if (root)
	{
		ft_apply_postfix(root->left, apply);
		ft_apply_postfix(root->right, apply);
		(apply)(root);
	}
}
