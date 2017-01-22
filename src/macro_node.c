/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:17:20 by ariard            #+#    #+#             */
/*   Updated: 2017/01/21 21:23:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_node_typeis(t_btree *node)
{
	t_token		*token;

	if (!node)
		return (-1);
	token = node->data;
	if (ft_strcmp(token->id, "operator") == 0)
		return (0);
	if (ft_strcmp(token->id, "operand") == 0)
		return (1);
	return (-1);
}

int			ft_node_islast(int size, char *s)
{
	if (!s)
		return (-1);
	if (size == ft_atoi(s) + 1)
		return (1);
	return (0);
}

char		*ft_node_nameis(t_btree *node)
{
	t_token		*token;

	if (!node)
		return (NULL);
	if (ft_node_typeis(node) == 0)
		return (NULL);
	token = node->data;
	return (ft_strduptr(token->name, &ft_isspace));
}

char		**ft_node_argis(t_btree *node)
{
	t_token		*token;
	char		**arg;
	char		*to_split;

	if (!node)
		return (NULL);
	token = node->data;
	arg = ft_memalloc(sizeof(char *));
	to_split = ft_strdup(token->name);
	arg = ft_strsplitptr(to_split, &ft_isspace);
	return (arg);
}

int			ft_nodeisleft(t_btree *node, t_btree *father)
{
	if (!father || !node)
		return (0);
	if (father->left)
		if (ft_strcmp((father->left)->key, node->key) == 0)
			return (1);
	if (father->right)
		if (ft_strcmp((father->right)->key, node->key) == 0)
			return (-1);
	return (0);
}	
