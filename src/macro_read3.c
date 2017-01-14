/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:27:07 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 23:49:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_iscolumn(t_screen *screen)
{
	int		col;

	col = (screen->cursor + screen->left) - ((screen->vertical - 1) * screen->col);
	return (col);
}

int			ft_lastcolumn(t_screen *screen)
{
	int		col;

	col = (screen->amplitude + screen->left) - ((screen->down - 1) * screen->col);
	return (col);
}

int			ft_isedit(t_screen *screen)
{
	if (screen->edit == 1)
		screen->edit = 0;
	else if (screen->edit == 0)
	{
		screen->edit = 1;
		screen->start = screen->cursor;
	}
	return (1);
}
