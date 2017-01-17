/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:29:02 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 00:12:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_even_prompt(t_screen *screen)
{
	int		i;
	int		end;

	ft_go_last_line(screen);
	ft_go_last_char(screen);
	i = 20 * screen->col; 
	screen->vertical = screen->down;
	while (i != 0)
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
