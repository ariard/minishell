/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:13:11 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 23:42:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_go_home(t_screen *screen)
{
	tputs(tgetstr("se", NULL), 0, &ft_puterm);
	while (screen->left != screen->cursor)
		ft_move_left(tgetstr("le", NULL), screen);
	return (1);
}

int			ft_go_end(t_screen *screen, char *stream)
{
	while (screen->right != screen->cursor)
		ft_move_right(tgetstr("nd", NULL), screen, stream);
	return (1);
}

int			ft_insert_substring(char *stream, char *insert, t_screen *screen)
{
	int		i;
	int		j;

	if (!insert || !stream)
		return (1);	
	i = ft_strlen(insert);
	j = 0;
	while (i--)
		ft_insert_char(stream, insert[j++], screen);
	ft_strdel(&screen->save);
	return (1);
}

int			ft_delete_substring(char *stream, t_screen *screen)
{
	int		i;

	if (!stream)
		return (1);
	i = screen->cursor;
	while (i-- != screen->start + screen->left)
		ft_delete_char(stream, screen);
	screen->edit = 0;
	return (1);
}
