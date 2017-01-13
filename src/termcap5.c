/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:16:14 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 17:58:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"minishell.h"

void		ft_cursor_left(void)
{
	tputs(tgetstr("le", NULL), 0, &ft_puterm);
}

void		ft_cursor_right(void)
{
	tputs(tgetstr("nd", NULL), 0, &ft_puterm);
}

void		ft_go_cursor(int pos, t_screen *screen)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	ft_return_home();
	while (i++ != pos)
	{
		if (ft_isendline(screen, i, j) == 1)
		{
			j++;
			ft_go_next_line();
		}
		ft_cursor_right();
	}
	ft_cursor_right();
}
