/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:41:02 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 19:18:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_next_line(t_screen *screen)
{
	ft_go_next_line();
	screen->vertical++;
}

void		ft_prev_line(t_screen *screen)
{
	ft_go_prev_line(screen);
	screen->vertical--;
}

void		ft_home(t_screen *screen)
{
	int		i;
	int		j;

	i = screen->left;
	j = screen->vertical;
	if (j == 1)
		ft_go_line_first();
	while (j-- != 1)
		ft_go_prev_line_first();
	while (i--)
		ft_cursor_right();
	screen->cursor = 0;
	screen->vertical = 1;
}

void		ft_end(t_screen *screen)
{
	int		i;
	int		j;

	i = (screen->col * (screen->down - 1)) - screen->left;
	j = screen->vertical;
	if (j == screen->down)
		ft_go_line_first();
	while (j++ != screen->down)
		ft_go_next_line();
	while (i++ != screen->amplitude)
		ft_cursor_right();
	screen->cursor = screen->amplitude;
	screen->vertical = screen->down;
}

void		ft_previous(char *buffer, t_screen *screen)
{
	ft_move_left(screen);
	while (buffer[screen->cursor] == ' ' && screen->cursor != 0)
		ft_move_left(screen);
	while (buffer[screen->cursor] != ' ' && screen->cursor != 0)
		ft_move_left(screen);
}
