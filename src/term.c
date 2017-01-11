/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:51:12 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 01:05:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell.h"

static int			ft_cursor(char c, int min, int max)
{
	char	d;

	if (c == '033')
	{
		read(0, &c, 1)
		if (c == '[')
		{
			read(0, &d, 1);
			if (d == 'A')
				return (ft_move_cursor(tgetstr("up"), min, max));
			if (d == 'D')
				return (ft_move_cursor(tgetstr("le"), min, max));
			if (d == 'C')
				return (ft_move_cursor(tgetstr("nd"), min, max));
			if (d == 'B')
				return (ft_move_cursor(tgetstr("do"), min, max));
			else if (d == 0)
				return (0);	
		}
	}
	return (0);
}


int			ft_process_input(char c, int min, int max)
{
	if (ft_cursor(c, min, max) == 1)
		return (1);
	return (0);
}
