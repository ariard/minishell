/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:53:48 by ariard            #+#    #+#             */
/*   Updated: 2017/02/27 20:44:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isend(int c)
{
	if (c == 13)
		return (1);
	return (0);
}

int			ft_iscol(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int			ft_isbeginline(int n, t_screen *screen)
{
	n += (screen->left + screen->col);
	if (n == screen->col * screen->vertical)
		return (2);
	return (0);
}

int			ft_isendline(int n, t_screen *screen)
{
	n += screen->left;
	if (n == screen->col * screen->vertical)
		return (1);
	return (0);
}
