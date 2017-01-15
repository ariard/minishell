/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:16:14 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 14:27:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"minishell.h"

static void		ft_change_char(char *buffer, int tmp, t_screen *screen)
{
	int			end;
	int			c;

	c = buffer[tmp];
	if ((end = ft_isbeginline(tmp, screen)))
			ft_prev_line(screen);
	else
		ft_cursor_left();
	ft_delete();
	if (end)
	{
		ft_insert(' ');
		ft_cursor_right();
	}
	ft_insert(c);
	ft_cursor_right();
	if (ft_isendline(tmp, screen))
		ft_next_line(screen);
}

static void		ft_highlights_ahead(char *buffer, t_screen *screen)
{
	int			i;

	ft_start_edit();
	i = screen->start;
	while (i != screen->cursor)
	{
		ft_change_char(buffer, i, screen);
		if (i == screen->amplitude)
			return ;
		ft_cursor_right();
		if (ft_isendline(i, screen))
			ft_next_line(screen);
		i++;
	}
	ft_end_edit();
}	

void		ft_highlights_edit(char *buffer, t_screen *screen)
{
	ft_highlights_ahead(buffer, screen);
}
