/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:41:02 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 21:49:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_move_left(char *cmd, t_screen *screen, char *stream)
{
	if (ft_overflow(stream, screen->vertical, screen))
		if (1 >= screen->cursor)
			return (1);
	if (0 >= screen->cursor)
		return (1);
	if (ft_isbeginline(screen, screen->cursor, screen->vertical) == 2)
	{
		screen->vertical--;
		ft_go_prev_line(screen);
	}
	else
	{
		tputs(cmd, 0, &ft_puterm);
		screen->cursor--;
	}
	return (1);
}

int			ft_move_right(char *cmd, t_screen *screen, char *stream)
{
	if (ft_isendline(screen, screen->cursor, screen->vertical))
	{
		ft_go_next_line();
		screen->vertical++;
	}
	else
	{
		if (screen->cursor >= (int)ft_strlen(stream))
			return (1);
		tputs(cmd, 0, &ft_puterm);
		screen->cursor += 1;
	}
	return (1);
}

int			ft_move_up(char *cmd, t_screen *screen)
{
	if (screen->vertical <= 0)
		return (1);
	tputs(cmd, 0, &ft_puterm);
	screen->cursor -= (screen->col);
	return (1);
}

int			ft_move_down(char *cmd, t_screen *screen)
{
	return (1);
	if (screen->vertical >= screen->down) 
		return (1);
	tputs(cmd, 0, &ft_puterm);
	return (1);
}
