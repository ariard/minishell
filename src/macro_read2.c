/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:56:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 23:15:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_set_info_screen(char *stream, t_screen *screen)
{
	int		n;

	n = 1;
	screen->col = ft_iscol();
	screen->amplitude = (int)ft_strlen(stream);
	screen->down = screen->amplitude + screen->left / screen->col;
	return (1);
}

int			ft_overflow(char *stream, int line, t_screen *screen)
{
	if ((int)ft_strlen(stream) + screen->left  >= screen->col * line
		&& screen->cursor < (int)ft_strlen(stream))
		return (1);
	return (0);
}
