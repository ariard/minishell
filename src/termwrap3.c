/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termwrap3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 19:26:32 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 20:09:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_go_last_char(t_screen *screen)
{
	int		i;

	i = 0;
	tputs(tgetstr("cr", NULL), 0, &ft_puterm);
	while (i++ != screen->col)
		ft_cursor_right();;
}

void		ft_go_last_line(t_screen *screen)
{
	int		level;

	level = screen->vertical;
	while (level++ != screen->down)
		ft_go_next_line();
}
