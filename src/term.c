/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:51:12 by ariard            #+#    #+#             */
/*   Updated: 2017/02/21 10:38:52 by ariard           ###   ########.fr       */
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
			if (d == 'A')
				ft_move_up(screen);
			if (d == 'B')
				ft_move_down(screen);
			if (d == 'C')
				ft_move_right(screen);
			if (d == 'D')
				ft_move_left(screen);
			return (1);
		}
	}
	return (0);
}


static int	ft_process_input2(char c, char *buffer, t_screen *screen, 
		t_info *info)
{
	if (c == 12)
		ft_clear_screen(buffer, screen);
	if (c == 9)
		ft_complete_switch(buffer, info->list_bin, screen);
	return (1);
}

int			ft_process_input(char c, char *buffer, t_screen *screen,
		t_info *info)
{
	ft_set_info_screen(buffer, screen);
	if (ft_cursor(c, screen) == 1)
		return (1);
	ft_process_input2(c, buffer, screen, info);
	if (c == 17)
		ft_home(screen);
	if (c == 23)
		ft_end(screen);
	if (c == 1)
		ft_previous(buffer, screen);
	if (c == 19)
		ft_next(buffer, screen);
	if (c == 22)
		ft_isedit(screen);
	if (c == 25)
		ft_crop(buffer, screen);
	if (c == 16)
		ft_insert_string(buffer, screen);
	if (c == 5)
		ft_delete_string(buffer, screen);
	if (c == 127 && screen->cursor != 0)
		ft_delete_char(buffer, screen);
	if (c >= 32 && c < 127 && c != '\033')
		ft_insert_char(c, buffer, screen);
	return (0);
}
