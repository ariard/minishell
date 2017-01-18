/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termwrap3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:26:32 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 17:09:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_go_last_char(t_screen *screen)
{
	int		i;

	i = 0;
	tputs(tgetstr("cr", NULL), 0, &ft_puterm);
	while (i++ != screen->col)
		ft_cursor_right();;
}

void		ft_go_last_line(t_screen *screen)
{
	int		level;

	level = screen->vertical;
	while (level++ != screen->down)
		ft_go_next_line();
}

void		ft_cursor_up(void)
{
	tputs(tgetstr("up", NULL), 0, &ft_puterm);
}

void		ft_cursor_down(int column, t_screen *screen)
{
	int		i;
	int		last;

	(void)screen;
	i = 0;
	last = ft_lastcolumn(screen);
	tputs(tgetstr("do", NULL), 0, &ft_puterm);
	if (screen->vertical + 1 == screen->down)
		if (column > last)
			column = last;
	while (i++ != column)
		ft_cursor_right();
}
