/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:02:24 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 15:12:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_insert_str(char *str, t_screen *screen)
{
	int		i;

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

static void		ft_goto_pos(int pos, t_screen *screen)
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
