/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:24:02 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 12:21:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_char(char *buffer, t_screen *screen)
{
	int		end;

	if ((end = ft_isbeginline(screen->cursor, screen)))
		ft_prev_line(screen);
	else
		ft_cursor_left();
	ft_delete();
	screen->cursor--;
	ft_str_delchr(buffer, screen->cursor);
	if (end)
	{
		ft_insert(' ');
		ft_cursor_right();
	}
	if (ft_underflow(screen))
		ft_push_up(buffer, screen);
}

void		ft_insert_char(char c, char *buffer, t_screen *screen)
{
	if (ft_overflow(screen))
		ft_push_down(buffer, screen);	
	ft_insert(c);
	ft_cursor_right();
	screen->cursor++;
	ft_str_inschr(buffer, c, screen->cursor);
	if (ft_isendline(screen->cursor, screen))
		ft_next_line(screen);
}

void		ft_move_right(t_screen *screen)
{
	int		begin;

	if (screen->cursor == screen->amplitude)
		return ;
	ft_cursor_right();
	screen->cursor++;
	if ((begin = ft_isendline(screen->cursor, screen)))
		ft_next_line(screen);
}

void		ft_move_left(t_screen *screen)
{
	int		end;

	if (screen->cursor == 0)
		return ;
	if ((end = ft_isbeginline(screen->cursor, screen)))
		ft_prev_line(screen);
	else
		ft_cursor_left();
	screen->cursor--;
}

void		ft_next(char *buffer, t_screen *screen)
{
	ft_move_right(screen);
	while (buffer[screen->cursor] != ' ' && screen->cursor != screen->amplitude)
		ft_move_right(screen);
	while (buffer[screen->cursor] == ' ' && screen->cursor != screen->amplitude)
		ft_move_right(screen);
	if (screen->cursor != screen->amplitude)
		ft_move_left(screen);
}
