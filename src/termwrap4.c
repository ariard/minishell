/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termwrap4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 00:21:14 by ariard            #+#    #+#             */
/*   Updated: 2017/01/18 16:35:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_start_edit(void)
{
	tputs(tgetstr("so", NULL), 0, &ft_puterm);
}

void		ft_end_edit(void)
{
	tputs(tgetstr("se", NULL), 0, &ft_puterm);
}

void		ft_clear(void)
{
	tputs(tgetstr("cl", NULL), 0, &ft_puterm);
}

void		ft_delete_line(void)
{
	tputs(tgetstr("dl", NULL), 0, &ft_puterm);
}
