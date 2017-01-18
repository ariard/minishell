/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_operator2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:12:09 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 18:48:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_islistand(t_btree *father)
{
	t_token		*token;

	if (!father)
		return (-1);
	token = father->data;
	if (ft_strcmp(token->name, "&&") == 0)
		return (1);
	return (0);
}

int			ft_islistor(t_btree *father)
{
	t_token		*token;

	if (!father)
		return (-1);
	token = father->data;
	if (ft_strcmp(token->name, "||") == 0)
		return (1);
	return (0);
}
