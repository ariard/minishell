/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:07:55 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 19:16:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_crop(char *stream, t_screen *screen)
{

	screen->edit = 0;
	return (ft_str_copy(stream, screen->start, screen->cursor - screen->left));
}

int			ft_isedit(int c, t_screen *screen)
{
	if (c == 22 && screen->edit == 1)
		screen->edit = 0;
	else if (c == 22 && screen->edit == 0)
	{
		screen->start = screen->cursor - screen->left;
		screen->edit = 1;
	}
	return (1);
}

void		ft_erase_all(char *stream, t_screen *screen)
{
	size_t		i;
	int			j;
	int			pos;

	i = 0;
	j = 1;
	pos = screen->cursor;
	ft_return_home();
	while (i++ != ft_strlen(stream))
	{
		if (ft_isendline(screen, i, j) == 1)
		{
			j++;
			ft_go_next_line();
		}
		ft_erase();
	}
	ft_cursor_left();
	ft_erase();
	ft_return_home();
}

int			ft_put_again(char *stream, t_screen *screen)
{
	char	buf[2];
	int		last;

	ft_bzero(buf, 2);
	last = (screen->col * (screen->vertical + 1) + 1 - screen->left); 
	buf[0] = stream[last];
	tputs(tgetstr("sc", NULL), 0, &ft_puterm);
	tputs(tgetstr("do", NULL), 0, &ft_puterm);
	tputs(tgetstr("cr", NULL), 0, &ft_puterm);
	tputs(tgetstr("im", NULL), 0, &ft_puterm);
	tputs(tgetstr("ic", NULL), 0, &ft_puterm);
	tputs(buf, 0, &ft_puterm);
	tputs(tgetstr("ip", NULL), 0, &ft_puterm);
	tputs(tgetstr("ei", NULL), 0, &ft_puterm);
	tputs(tgetstr("rc", NULL), 0, &ft_puterm);
	return (1);
}
	
