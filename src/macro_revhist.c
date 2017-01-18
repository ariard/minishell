/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_revhist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:32:17 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 15:05:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_read_cursor(char c)
{
	if (c == '\033')
	{
		read(0, &c, 1);
		if (c == '[')
		{
			read(0, &c, 1);
			if (c == 'A')
				return (1);
			if (c == 'B')
				return (1);
			if (c == 'C')
				return (1);
			if (c == 'D')
				return (1);
		}
	}
	return (0);
}

void		ft_save_screen(t_screen *new_screen, t_screen *screen)
{
	new_screen->cursor = screen->cursor;
	new_screen->vertical = screen->vertical;
	new_screen->left = screen->left;
	new_screen->amplitude = screen->amplitude;
	new_screen->start = screen->start;
	new_screen->edit = screen->edit;
	new_screen->down = screen->down;
	new_screen->col = screen->col;
	new_screen->quote = screen->quote;
	new_screen->match = screen->match;
	new_screen->saved = screen->saved;
}

int			ft_set_info_new_screen(char *buffer, t_screen *screen)
{
	int		n;

	n = 1;
	screen->col = ft_iscol();
	screen->amplitude = (int)ft_strlen(buffer);
	if (screen->col == 0)
		screen->col = 1;
	screen->down = ((screen->amplitude + 2) / screen->col) + 1;
	return (1);
}

void		ft_update_pattern(char *pattern)
{
	char	*tmp;
	int		len;
	
	tmp = ft_strdup(pattern);
	ft_bzero(pattern, 1024);
	if ((len = (ft_strlen(tmp) - 1)) >= 0)
		ft_strncpy(pattern, tmp, ft_strlen(tmp) - 1);
	ft_strdel(&tmp);
}
