/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_termcap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:38:29 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 18:07:12 by ariard           ###   ########.fr       */
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

int		ft_insert_char(char *str)
{
	tputs(tgetstr("im", NULL), 0, &ft_puterm);
	tputs(tgetstr("ic", NULL), 0, &ft_puterm);
	tputs(str, 0, &ft_puterm);
	tputs(tgetstr("ip", NULL), 0, &ft_puterm);
	tputs(tgetstr("ei", NULL), 0, &ft_puterm);
	return (1);
}

int		ft_delete_char(t_screen *screen)
{
	(void)screen;
//	if (screen->right <= screen->cursor) 
//		return (1);
	tputs(tgetstr("dm", NULL), 0, &ft_puterm);
	tputs(tgetstr("dc", NULL), 0, &ft_puterm);
	tputs(tgetstr("ed", NULL), 0, &ft_puterm);
	return (1);
}
