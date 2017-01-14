/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termwrap1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:06:24 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 21:00:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_save_cursor(void)
{
	tputs(tgetstr("sc", NULL), 0, &ft_puterm);
}

void			ft_return_cursor(void)
{
	tputs(tgetstr("rc", NULL), 0, &ft_puterm);
}

void			ft_delete(void)
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
