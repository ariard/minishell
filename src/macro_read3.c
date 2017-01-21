/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:27:07 by ariard            #+#    #+#             */
/*   Updated: 2017/01/21 17:32:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_iscolumn(t_screen *screen)
{
	int		col;

	col = (screen->cursor + screen->left) - ((screen->vertical - 1) * screen->col);
	return (col);
}

int			ft_lastcolumn(t_screen *screen)
{
	int		col;

	col = (screen->amplitude + screen->left) - ((screen->down - 1) * screen->col);
	return (col);
}

int			ft_isedit(t_screen *screen)
{
	if (screen->edit == 1)
		screen->edit = 0;
	else if (screen->edit == 0)
	{
		screen->edit = 1;
		screen->start = screen->cursor;
	}
	return (1);
}

void		ft_return_buffquote(char *buffer, char *buffquote, int n)
{
	char	db[2];
	char	*tmp;
	char	c;

	ft_bzero(db, 2);
	db[0] = 34;
	c = 13;
	ft_strcat(buffquote, buffer);
	ft_strcat(buffquote, "\n"); 
	if (n == 1)
		tmp = ft_str_epure(buffquote, "'");
	if (n == 2)
		tmp = ft_str_epure(buffquote, db);
	ft_bzero(buffer, 1024);
	ft_strcpy(buffer, tmp);
}

int			ft_isinheredoc(char *buffer, t_info *info)
{
	char	*tmp;

	tmp = buffer;
	while (*(tmp + 1))
		tmp++;
	tmp--;
	while (*tmp && *tmp != '>' && *tmp != ';' && *tmp != '&')
	{

		if (*tmp == '<')
			if (*(tmp - 1))
				if (*(tmp - 1) == '<')
				{
					info->heredoc = 1;
					return (1);
				}	
		tmp--;
	}
	return (0);
}
