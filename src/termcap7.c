/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:29:02 by ariard            #+#    #+#             */
/*   Updated: 2017/02/26 19:19:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_delete_even_prompt(char *buffer, char *pattern, t_screen *screen)
{
	int		i;

	screen->col = ft_iscol();
	if (screen->col == 0)
		screen->col = 1;
	if (buffer && pattern)
		screen->down = ((ft_strlen(buffer) + 22 + ft_strlen(pattern))
			/ screen->col) + 1;
	screen->vertical = screen->down;
	ft_go_last_line(screen);
	ft_go_last_char(screen);
	i = screen->down;
	while (i--)
	{
		ft_delete_line();
		if (i != 0)
			ft_go_prev_line_first();
	}
	i = screen->col;
	while (i--)
		ft_cursor_left();
	return ;
}
