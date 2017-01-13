/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:13:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 18:25:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_save_home(void)
{
	tputs(tgetstr("sc", NULL), 0, &ft_puterm);
}

void			ft_return_home(void)
{
	tputs(tgetstr("rc", NULL), 0, &ft_puterm);
	tputs(tgetstr("sc", NULL), 0, &ft_puterm);
}

void			ft_erase(void)
{
	tputs(tgetstr("dm", NULL), 0, &ft_puterm);
	tputs(tgetstr("dc", NULL), 0, &ft_puterm);
	tputs(tgetstr("ed", NULL), 0, &ft_puterm);
}

void			ft_go_next_line(void)
{
	tputs(tgetstr("do", NULL), 0, &ft_puterm);
	tputs(tgetstr("cr", NULL), 0, &ft_puterm);
}

void			ft_go_prev_line(t_screen *screen)
{
	int			i;

	i = 0;
	tputs(tgetstr("up", NULL), 0, &ft_puterm);
	tputs(tgetstr("cr", NULL), 0, &ft_puterm);
	while (i++ != screen->col)
		ft_cursor_right();
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
