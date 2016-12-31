/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_analyzer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:32:40 by ariard            #+#    #+#             */
/*   Updated: 2016/12/31 15:25:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_scan_stream(char *tab)
{
	int			only_spaces;
	int			len;

	only_spaces = 0;
	len = ft_strlenchr(tab, '#');
	while (*tab)
	{
		if (*tab == '#')
		{
			while (*tab)
			{
				*tab = '\0';
				tab++;
			}
			break;
		}
		only_spaces = ft_isspace(*tab);
		tab++;
	}
	if (only_spaces == len)
	   return (1);
	return (0);	
}

void			ft_lex_analyze(char	*tab)
{
	if (ft_scan_stream(tab))
		return ;
	ft_putstr(tab);
	ft_putstr("\n");
}
