/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:41:02 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 17:41:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_move_left(char *cmd, t_screen *screen)
{
	if (0 >= screen->cursor)
		return (1);
	if (ft_isbeginline(screen, screen->cursor, screen->vertical))
		ft_go_prev_line(screen);
	else
		tputs(cmd, 0, &ft_puterm);
	screen->cursor -= 1;
	return (1);
}

int			ft_move_right(char *cmd, t_screen *screen)
{
	if (screen->cursor >= 350)
		return (1);
	if (ft_isendline(screen, screen->cursor, screen->vertical))
		ft_go_next_line();
	else
		tputs(cmd, 0, &ft_puterm);
	screen->cursor += 1;
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
