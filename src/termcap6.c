/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:02:24 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 00:06:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_insert_str(char *str, t_screen *screen)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_insert(str[i]);
		ft_cursor_right();
		i++;
		if (ft_isendline(i, screen))
			ft_next_line(screen);
	}
}

void		ft_goto_pos(int pos, t_screen *screen)
{
	int		i;

	i = screen->amplitude;
	while (i != pos)
	{
		i--;
		if (i == 0)
			return ;
		ft_cursor_left();
		if (ft_isbeginline(i, screen))
			ft_prev_line(screen);
	}
}

void		ft_clear_screen(char *buffer, t_screen *screen)
{
	int		vertical;
	char	*prompt;

	vertical = screen->vertical;
	prompt = "ariard-1.0$> ";
	ft_clear();
	ft_insert_str(prompt, screen);
	screen->vertical = 1;
	ft_insert_str(buffer, screen);
	screen->vertical = screen->down;
	ft_goto_pos(screen->cursor, screen);
	screen->vertical = vertical;
}

void		ft_delete_all(t_screen *screen)
{
	int		i;
	int		end;

	ft_go_last_line(screen);
	ft_go_last_char(screen);
	i = screen->down * screen->col; 
	screen->vertical = screen->down;
	while (i != 14)
	{
		if ((end = ft_isbeginline(i, screen)))
			ft_prev_line(screen);
		else
			ft_cursor_left();
		ft_delete();
		i--;
		if (end)
		{
			ft_insert(' ');
			ft_cursor_right();
		}
	}
}

void		ft_swap_buffer(char *buffer, char *newbuffer, t_screen *screen)
{
	int		i;
	int		j;

	if (!newbuffer)
		return ;
	ft_delete_all(screen);
	screen->cursor = 0;
	ft_bzero(buffer, 1024);
	i = 0;
	j = ft_strlen(newbuffer);
	while (i < j)
		ft_insert_char(newbuffer[i++], buffer, screen);
}
