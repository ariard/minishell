/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:51:12 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 15:30:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

static int			ft_cursor(int c, t_screen *screen)
{
	int 	d;

	d = '\0';
	if (c == '\033')
	{
		read(0, &c, 1);
		if (c == '[')
		{
			read(0, &d, 1);
			if (d == 'D')
				ft_move_left(screen);
			if (d == 'C')
				ft_move_right(screen);
			return (1);
		}
	}
	return (0);
}

int			ft_process_input(char c, char *stream, t_screen *screen)
{
	screen->col = ft_iscol();
	screen->down = ((int)ft_strlen(stream) + screen->left) / screen->col;
	ft_set_info_screen(stream, screen);
	if (ft_cursor(c, screen) == 1)
		return (1);
	if (c == 26)
		ft_putnbr(screen->cursor);
	if (c == 25)
		ft_putnbr(screen->vertical);
	if (c == 24)
		ft_putnbr(screen->left);
	if (c == 127 && screen->cursor != 0)
		ft_delete_char(screen);
	if (c != 13 && c != 127 && c != '\033')
		ft_insert_char(c, screen);
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
