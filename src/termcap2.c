/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:41:02 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 16:58:21 by ariard           ###   ########.fr       */
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

void		ft_go_last_line(t_screen *screen)
{
	int		level;

	level = 1; 
	while (level++ != screen->down)
		ft_go_next_line();
}
