/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:51:12 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 22:39:09 by ariard           ###   ########.fr       */
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
///				return (ft_move_up(tgetstr("up", NULL), screen));
			if (d == 'D')
				return (ft_move_left(tgetstr("le", NULL), screen, stream));
			if (d == 'C')
				return (ft_move_right(tgetstr("nd", NULL), screen, stream));
//			if (d == 'B')
//				return (ft_move_down(tgetstr("do", NULL), screen));
		}
	}
	return (0);
}

int			ft_process_input(char c, char *stream, t_screen *screen)
{
	screen->col = ft_iscol();
	screen->down = ((int)ft_strlen(stream) + screen->left) / screen->col;
	ft_set_info_screen(stream, screen);
	if (ft_cursor(c, stream, screen) == 1)
		return (1);
	if (c == 26)
		ft_putnbr(screen->cursor);
	if (c == 25)
		ft_putnbr(screen->vertical);
	if (c == 24)
		ft_putnbr(screen->left);
	if (c == 2)
	{
		ft_return_home();
		return (1);
	}
	if (c == 5)
	{
		ft_go_cursor((150), screen);
		return (1);
	}
	if (c == 4)
	{
		ft_erase_all(stream, screen);
		return (1);
	}
	if (c == 127 && screen->cursor != 0) 
		ft_delete_char(stream, screen);
	if (c != 13 && c != 127 && c != '\033')
		ft_insert_char(stream, c, screen);
	return (0);
}

































//	if (c == 1)
//		return (ft_go_home(screen));
//	if (c == 19)
//		return (ft_go_end(screen, stream));
//	if (c == 17)
//		return (ft_go_left(stream, screen));
//	if (c == 23)
//		return (ft_go_right(stream, screen));
//	if (c == 22)
//		return (ft_isedit(c, screen));
//	if (c == 25 && screen->edit == 1)
//		screen->save = ft_crop(stream, screen);
//	if (c == 16 && screen->edit == 0)
//		return (ft_insert_substring(stream, screen->save, screen));
//	if (c == 4 && screen->edit == 1)
//		return (ft_delete_substring(stream, screen));
