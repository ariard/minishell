/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:56:58 by ariard            #+#    #+#             */
/*   Updated: 2017/01/13 18:09:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_set_info_screen(char *stream, t_screen *screen)
{
	int		n;

	n = 1;
	screen->col = ft_iscol();
	screen->down = ((int)ft_strlen(stream) + screen->left) / screen->col;
	while (screen->cursor + screen->left >= (screen->col) * n)
		n++;
	screen->vertical = n;
	return (1);
}
