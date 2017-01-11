/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:07:55 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 23:43:35 by ariard           ###   ########.fr       */
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
