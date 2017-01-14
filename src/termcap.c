/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:24:02 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 15:44:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_char(t_screen *screen)
{
	int		end;

	if ((end = ft_isbeginline(screen->cursor, screen)))
		ft_prev_line(screen);
	else
		ft_cursor_left();
	ft_delete();
	screen->cursor--;
	if (end)
	{
		ft_insert(' ');
		ft_cursor_right();
	}
}

void		ft_insert_char(char c, t_screen *screen)
{
	ft_insert(c);
	ft_cursor_right();
	screen->cursor++;
	if (ft_isendline(screen->cursor, screen))
		ft_next_line(screen);
}

void		ft_move_right(t_screen *screen)
{
	int		begin;

	ft_cursor_right();
	screen->cursor++;
	if ((begin = ft_isendline(screen->cursor, screen)))
		ft_next_line(screen);
}

void		ft_move_left(t_screen *screen)
{
	int		end;

	if ((end = ft_isbeginline(screen->cursor, screen)))
		ft_prev_line(screen);
	else
		ft_cursor_left();
	screen->cursor--;
}








































/*int		ft_clear_screen(void)
{
	char	*res;

	res = tgetstr("cl", NULL);
	if (res == NULL)
		return (-1);
	tputs(res, 0, &ft_puterm);
	return (1);
}*/


/*
int		ft_go_left(char *stream, t_screen *screen)
{
	tputs(tgetstr("se", NULL), 0, &ft_puterm);
	ft_move_left(tgetstr("le", NULL), screen);
	while (screen->left != screen->cursor)
	{
		ft_move_left(tgetstr("le", NULL), screen);
		if (stream[screen->cursor - screen->left] == ' ')
		{
			ft_move_right(tgetstr("nd", NULL), screen, stream);
			break;
		}

	}
	return (1);
}

int		ft_go_right(char *stream, t_screen *screen)
{
	while (screen->right != screen->cursor)
	{
		ft_move_right(tgetstr("nd", NULL), screen, stream);
		if (stream[screen->cursor - screen->left] == ' ')
		{
			ft_move_right(tgetstr("nd", NULL), screen, stream);
			break;
		}
	}
	return (1);
}*/
