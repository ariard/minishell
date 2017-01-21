/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:53:48 by ariard            #+#    #+#             */
/*   Updated: 2017/01/21 17:41:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isend(int c, char *buffer, char *buffquote, t_screen *screen,
		t_info *info)
{
	if (c == 13 && screen->quote == 0 && info->heredoc != 1) 
		return (1);
	if (c == 13 && (screen->quote != 0 || info->heredoc == 1))
	{
		ft_insert(10);
		ft_insert_str("> ", screen);
		screen->cursor = 0;
		screen->vertical = 1;
		screen->left = ft_strlen(">");
		ft_strcat(buffquote, buffer);
		if (info->heredoc == 1)
			ft_strcat(buffquote, "\n");
		ft_bzero(buffer, 1024);
	}
	return (0);
}

int			ft_isquote(int c, char *buffer, char *buffquote, t_screen *screen)
{
	if (c == '"' && screen->quote == 0)
		return (2);
	if (c == 39 && screen->quote == 0)
		return (1);
	if (c == '"' && screen->quote == 2 )
	{
		ft_return_buffquote(buffer, buffquote, 2);
		return (0);
	}
	if (c == 39 && screen->quote == 1)
	{
		ft_return_buffquote(buffer, buffquote, 1);
		return (0);
	}
	return (screen->quote);
}

int			ft_iscol(void)
{
	struct	winsize w;
	
	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int			ft_isbeginline(int n, t_screen *screen)
{
	n += (screen->left + screen->col);
	if (n == screen->col * screen->vertical)
		return (2);
	return (0);
}

int			ft_isendline(int n, t_screen *screen)
{
	n += screen->left;
	if (n == screen->col * screen->vertical)
		return (1);
	return (0);
}
