/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 19:02:24 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 22:54:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_agence_down(char *stream, t_screen *screen)
{
	int			level;

	level = screen->down;
	if (ft_overflow(stream, level, screen) == 1)
		ft_putstr("overflow");
}
