/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_termcap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:38:29 by ariard            #+#    #+#             */
/*   Updated: 2017/01/11 16:45:11 by ariard           ###   ########.fr       */
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
