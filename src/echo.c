/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:27:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/29 21:01:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_echo(char **arg, t_info *info)
{
	int 	fd;

	fd = 1;
	(void)info;
	if (!arg)
		return (1);
	if (info->file != 0)
		fd = info->file;
	arg++;
	if (*arg)
		ft_putarray_fd(arg, 32, 10, fd);
	else
		ft_putchar_fd(10, fd);
	return (1);
}
