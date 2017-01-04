/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 22:09:47 by ariard            #+#    #+#             */
/*   Updated: 2017/01/04 22:46:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_syntax_error(t_dlist *list_token)
{
	t_token		*token;

	if (list_token)
		if (list_token->data)
		{
			token = list_token->data;
			ft_putstr("ariard : syntax error near unexpected token '");
			ft_putstr(token->name);
			ft_putstr("'\n");
		}
	return (-1);
}
