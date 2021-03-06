/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 21:17:20 by ariard            #+#    #+#             */
/*   Updated: 2017/01/06 15:33:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_nodeis(t_btree *node)
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

char	**ft_node_argis(t_btree *node)
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
