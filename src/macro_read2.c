/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:56:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/20 15:32:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_set_info_screen(char *buffer, t_screen *screen)
{
	int		n;

	n = 1;
	screen->col = ft_iscol();
	screen->amplitude = (int)ft_strlen(buffer);
	if (screen->col == 0)
		screen->col = 1;
	screen->down = ((screen->amplitude + screen->left) / screen->col) + 1;
	return (1);
}

int			ft_overflow(t_screen *screen)
{
	if (screen->amplitude + screen->left >= screen->col * 
			screen->vertical && screen->cursor < screen->amplitude)
		return (1);
	return (0);
}

int			ft_underflow(t_screen *screen)
{
	if (screen->amplitude + screen->left > screen->col * 
			screen->vertical && screen->cursor < screen->amplitude)
		return (1);
	return (0);
}

char		ft_lastchar(char *buffer, int line, t_screen *screen)
{
	int		pos;

	pos = (screen->col - screen->left - 1) + (screen->col * (line - 1));
	return (buffer[pos]);
}

char		ft_firstchar(char *buffer, int line, t_screen *screen)
{
	int		pos;

	pos = (screen->col - screen->left - 1) + (screen->col * line);
	return (buffer[pos]);
}
