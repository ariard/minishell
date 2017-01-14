/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:07:55 by ariard            #+#    #+#             */
/*   Updated: 2017/01/14 23:53:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_crop(char *buffer, t_screen *screen)
{
	if (screen->start <= screen->cursor)
		screen->saved = ft_str_copy(buffer, screen->start, screen->cursor);
	else if (screen->start > screen->cursor)
		screen->saved = ft_str_copy(buffer, screen->cursor, screen->start);
	screen->edit = 0;
}

void		ft_insert_string(char *buffer, t_screen *screen)
{
	int		i;
	int		j;

	if (!screen->saved)
		return ;
	i = 0;
	j = ft_strlen(screen->saved);
	while (i < j)
		ft_insert_char(screen->saved[i++], buffer, screen);
	ft_strdel(&screen->saved);
}

void		ft_delete_string(char *buffer, t_screen *screen)
{
	int		i;
	int		j;

	i = screen->start;
	j = screen->cursor;
	while (i++ != j)
		ft_delete_char(buffer, screen);
	screen->edit = 0;
}
