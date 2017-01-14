/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termwrap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:08:04 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 17:03:55 by ariard           ###   ########.fr       */
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

void		ft_insert(char c)
{
	char	buf[2];

	ft_bzero(buf, 2);
	buf[0] = c;
	tputs(tgetstr("im", NULL), 0, &ft_puterm);
	tputs(tgetstr("ic", NULL), 0, &ft_puterm);
	tputs(buf, 0, &ft_puterm);
	tputs(tgetstr("ip", NULL), 0, &ft_puterm);
	tputs(tgetstr("ei", NULL), 0, &ft_puterm);
	ft_cursor_left();
}

void		ft_go_prev_line_first(void)
{
	tputs(tgetstr("up", NULL), 0, &ft_puterm);
	tputs(tgetstr("cr", NULL), 0, &ft_puterm);
}
