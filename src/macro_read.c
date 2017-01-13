/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:53:48 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 21:48:43 by ariard           ###   ########.fr       */
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

int			ft_iscol(void)
{
	struct	winsize w;
	
	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int			ft_isbeginline(t_screen *screen, int n, int line)
{
	n += (screen->left + screen->col);
	if (n == screen->col * line)
		return (2);
	return (0);
}

int			ft_isendline(t_screen *screen, int n, int line)
{
	n += (screen->left);
	if (n == screen->col * line)
		return (1);
	return (0);
}
