/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:13:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 17:10:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_push_down_all(char *buffer, t_screen *screen)
{
	int		level;

	(void)buffer;
	ft_save_cursor();
	ft_go_last_line(screen);
	if (screen->amplitude + screen->left + 1 >= screen->col * screen->down)
	{
		ft_go_next_line();
		screen->down++;
	}
	level = screen->down;
	while (level != 1)
	{
		ft_insert(ft_lastchar(buffer, level - 1, screen));
		level--;
		ft_go_prev_line_first();
	}
	ft_return_cursor();
}
























/*
int			ft_go_end(t_screen *screen, char *stream)
{
	while (screen->right != screen->cursor)
		ft_move_right(tgetstr("nd", NULL), screen, stream);
	return (1);
}

int			ft_insert_substring(char *stream, char *insert, t_screen *screen)
{
	int		i;
	int		j;

	if (!insert || !stream)
		return (1);	
	i = ft_strlen(insert);
	j = 0;
	while (i--)
		ft_insert_char(stream, insert[j++], screen);
	ft_strdel(&screen->save);
	return (1);
}

int			ft_delete_substring(char *stream, t_screen *screen)
{
	int		i;

	if (!stream)
		return (1);
	i = screen->cursor;
	while (i-- != screen->start + screen->left)
		ft_delete_char(stream, screen);
	screen->edit = 0;
	return (1);
}*/
