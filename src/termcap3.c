/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:13:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 21:21:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_go_home(t_screen *screen)
{
	while (screen->left != screen->cursor)
		ft_move_left(tgetstr("le", NULL), screen);
	return (1);
}

int			ft_go_end(t_screen *screen)
{
	while (screen->right != screen->cursor)
		ft_move_right(tgetstr("nd", NULL), screen);
	return (1);
}

int			ft_insert_substring(char *stream, char *insert, t_screen *screen)
{
	int		i;
	int		j;

	if (!insert || !stream)
		return (1);	
	i = screen->start - screen->left;
	j = 0;
	while (i++ < screen->cursor)
		ft_insert_char(stream, insert[j++], screen);
	ft_strdel(&screen->save);
	return (1);
}

int			ft_delete_substring(char *stream, t_screen *screen)
{
	int		i;

	if (!stream)
		return (1);
	i = screen->start - screen->left;
	while (i++ < screen->cursor)
		ft_delete_char(stream, screen);
	screen->edit = 0;
	return (1);
}
