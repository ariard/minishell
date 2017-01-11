/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_termcap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:38:29 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 23:50:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int		ft_clear_screen(void)
{
	char	*res;

	res = tgetstr("cl", NULL);
	if (res == NULL)
		return (-1);
	tputs(res, 0, &ft_puterm);
	return (1);
}*/

int		ft_insert_char(char *stream, char c, t_screen *screen)
{
	tputs(tgetstr("im", NULL), 0, &ft_puterm);
	tputs(tgetstr("ic", NULL), 0, &ft_puterm);
	tputs(&c, 0, &ft_puterm);
	tputs(tgetstr("ip", NULL), 0, &ft_puterm);
	tputs(tgetstr("ei", NULL), 0, &ft_puterm);
	screen->cursor += 1;
	ft_str_inschr(stream, (int)c, screen->cursor - screen->left);
	return (1);
}

int		ft_delete_char(char	*stream, t_screen *screen)
{
	ft_move_left(tgetstr("le", NULL), screen);
	tputs(tgetstr("dm", NULL), 0, &ft_puterm);
	tputs(tgetstr("dc", NULL), 0, &ft_puterm);
	tputs(tgetstr("ed", NULL), 0, &ft_puterm);
	ft_str_delchr(stream, screen->cursor - screen->left);
	return (1);
}

int		ft_go_left(char *stream, t_screen *screen)
{
	tputs(tgetstr("se", NULL), 0, &ft_puterm);
	ft_move_left(tgetstr("le", NULL), screen);
	while (screen->left != screen->cursor)
	{
		ft_move_left(tgetstr("le", NULL), screen);
		if (stream[screen->cursor - screen->left] == ' ')
		{
			ft_move_right(tgetstr("nd", NULL), screen, stream);
			break;
		}

	}
	return (1);
}

int		ft_go_right(char *stream, t_screen *screen)
{
	while (screen->right != screen->cursor)
	{
		ft_move_right(tgetstr("nd", NULL), screen, stream);
		if (stream[screen->cursor - screen->left] == ' ')
		{
			ft_move_right(tgetstr("nd", NULL), screen, stream);
			break;
		}
	}
	return (1);
}
