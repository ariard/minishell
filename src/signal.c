/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:59:03 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 20:36:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_interrupt(char c, char *buffer, t_screen *screen, t_info *info)
{
	if (c == 3)
	{
		ft_bzero(buffer, 1024);
		return (1);
	}
	if (c == 4 && ft_strlen(buffer) == 0 && screen->quote == 0 
		&& info->heredoc == 0)
	{
		ft_putstr("exit");
		exit(0);
	}
	else if (c == 4 && ft_strlen(buffer) == 0 && screen->quote != 0)
	{
		ft_putstr_fd("\nariard : syntax eror : unexpected end of file", 2);
		ft_bzero(buffer, 1024);
		screen->quote = 0;
		return (1);
	}
	else if (c == 4 && ft_strlen(buffer) == 0 && info->heredoc != 0)
	{
		ft_bzero(buffer, 1024);
		info->heredoc = 0;
		return (1);
	}
	return (0);
}

void	ft_sigint_handler(int signo)
{
	(void)signo;
	ft_putchar(10);
}
