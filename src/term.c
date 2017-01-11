/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:51:12 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 16:48:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

static int			ft_cursor(int c, char *stream, t_screen *screen)
{
	int 	d;

	d = '\0';
	(void)stream;
	if (c == '\033')
	{
		read(0, &c, 1);
		if (c == '[')
		{
			read(0, &d, 1);
//			if (d == 'A')
//				return (ft_move_cursor(tgetstr("up"), min, max));
			if (d == 'D')
				return (ft_move_left(tgetstr("le", NULL), screen));
			if (d == 'C')
				return (ft_move_right(tgetstr("nd", NULL), screen));
//			if (d == 'B')
//				return (ft_move_cursor(tgetstr("do"), min, max));
//			else
//			{
//				ft_process_input(c, stream, screen);
//				if (d != 0)
//					ft_process_input(d, stream, screen);
//				return (0);
//			}
		}
	}
	return (0);
}


int			ft_process_input(int c, char *stream, t_screen *screen)
{
	if (ft_cursor(c, stream, screen) == 1)
		return (1);
	if (c != 13 && c != '\033')
	{
		ft_insert_char((char *)&c);
		screen->cursor += 1;
		ft_strncat(stream, (char *)&c, 1);
	}
	return (0);
}
