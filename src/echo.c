/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:27:35 by ariard            #+#    #+#             */
/*   Updated: 2017/01/08 13:12:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_echo(char *arg, char **env)
{
	char	**print;

	(void)env;
	print = ft_strsplitptr(arg, &ft_isspace);
	print++;
	if (*print)
		ft_putarray(print, 32, 10);
	else
		ft_putchar(10);
	return (1);
}
