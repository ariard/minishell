/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:13:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 15:14:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_push_down(char *buffer, t_screen *screen)
{
	int		level;

	ft_save_cursor();
	ft_go_last_line(screen);
	level = screen->down;
	while (level != screen->vertical)
	{
		ft_insert(ft_lastchar(buffer, level - 1, screen));
		level--;
		ft_go_prev_line_first();
	}
	ft_return_cursor();
}

void		ft_push_up(char *buffer, t_screen *screen)
{
	int		level;

	ft_save_cursor();
	level = screen->vertical;
	while (level != screen->down)
	{
		ft_go_last_char(screen);
		ft_insert(ft_firstchar(buffer, level - 1, screen));
		level++;
		ft_go_next_line();
		ft_delete();
	}
	ft_return_cursor();
}

void		ft_move_up(t_screen *screen)
{
	int		diff;

	if (screen->vertical == 1)
		return ;
	ft_cursor_up();
	screen->vertical--;
	screen->cursor -= screen->col;
	diff = screen->cursor;
	if (diff < 0)
	{
		diff *= -1;
		while (diff--)
			ft_cursor_right();
	}
	if (screen->cursor < 0)
		screen->cursor = 0;
}

void		ft_move_down(t_screen *screen)
{
	int		column;
	int		last;

	if (screen->vertical == screen->down)
		return ;
	column = ft_iscolumn(screen);
	last = ft_lastcolumn(screen);
	ft_cursor_down(column, screen);
	screen->vertical++;
	if (column > last && screen->vertical == screen->down)
		screen->cursor += (last + (screen->col - column));
	else
		screen->cursor += screen->col;
}
