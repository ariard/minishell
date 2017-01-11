/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:41:02 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 23:53:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_move_left(char *cmd, t_screen *screen)
{
	if (screen->left >= screen->cursor)
		return (1);
	tputs(cmd, 0, &ft_puterm);
	screen->cursor -= 1;
	return (1);
}

int			ft_move_right(char *cmd, t_screen *screen, char *stream)
{
	(void)stream;
	if (screen->right <= screen->cursor)
		return (1);
	tputs(cmd, 0, &ft_puterm);
	screen->cursor += 1;
	return (1);
}

int			ft_move_up(char *cmd, t_screen *screen)
{
	(void)screen;
	tputs(cmd, 0, &ft_puterm);
	return (1);
}

int			ft_move_down(char *cmd, t_screen *screen)
{
	(void)screen;
	tputs(cmd, 0, &ft_puterm);
	return (1);
}
