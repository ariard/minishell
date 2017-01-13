/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_operand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:10:26 by ariard            #+#    #+#             */
/*   Updated: 2017/01/12 19:16:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isregular(t_btree *father)
{
	t_token		*token;

	if (!father)
		return (-1);
	token = father->data;
	if (ft_strcmp(token->name, ";") == 0)
		return (1);
	return (0);
}

int			ft_ispipe(t_btree *father)
{
	t_token		*token;

	if (!father)
		return (-1);
	token = father->data;
	if (ft_strcmp(token->name, "|") == 0)
		return (1);
	return (0);
}

int			ft_isredir_out(t_btree *father)
{
	t_token		*token;

	if (!father)
		return (-1);
	token = father->data;
	if (ft_strcmp(token->name, ">") == 0)
		return (1);
	return (0);
}

int			ft_isredir_in(t_btree *father)
{
	t_token		*token;

	if (!father)
		return (-1);
	token = father->data;
	if (ft_strcmp(token->name, "<") == 0)
		return (1);
	return (0);
}

int			ft_isappredir_out(t_btree *father)
{
	t_token		*token;

	if (!father)
		return (-1);
	token = father->data;
	if (ft_strcmp(token->name, ">>") == 0)
		return (1);
	return (0);
}
