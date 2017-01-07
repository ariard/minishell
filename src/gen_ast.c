/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:50:59 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 21:30:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree			*ft_ast_insert_sequence(t_root *tree, t_btree *father, 
		t_dlist *operand, t_dlist *operator)
{
	t_btree		*tmp;

	if (!tree->root)
	{
		tmp = ft_btree_ins_right(tree, father, operator->key, operator->data);
	}
	else
		tmp = ft_btree_ins_right(tree, father, operator->key, operator->data);
	ft_btree_ins_left(tree, tmp, operand->key, operand->data);
	return (tmp);
}

t_btree			*ft_ast_insert_cmd(t_root *tree, t_btree *father,
		t_dlist *operand)
{
	t_btree		*tmp;

	tmp = ft_btree_ins_right(tree, father, operand->key, operand->data);
	return (tmp);
}
