/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:53:48 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 21:20:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isend(int c, int quote, t_screen *screen)
{
	(void)screen;
	if (c == 13 && quote == 0)
		return (1);
	if (c == 13 && quote != 0)
		tputs("\n> ", 1, &ft_puterm);
	return (0);
}

int			ft_isquote(int c, int quote)
{
	if (c == '"' && quote == 0)
		return (2);
	if (c == 39 && quote == 0)
		return (1);
	if (c == '"' && quote == 2)
		return (0);
	if (c == 39 && quote == 1)
		return (0);
	return (quote);
}

int			ft_isedit(int c, t_screen *screen)
{
	if (c == 22 && screen->edit == 0)
	{
		screen->start = screen->cursor - screen->left;
		screen->edit = 1;
	}
	if (c == 22 && screen->edit == 1)
		screen->edit = 0;
	return (1);
}
