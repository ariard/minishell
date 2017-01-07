/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_analyzer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:32:40 by ariard            #+#    #+#             */
/*   Updated: 2017/01/05 19:27:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_scan_stream(char *stream)
{
	int			only_spaces;
	int			len;

	only_spaces = 0;
	len = ft_strlenchr(stream, '#');
	while (*stream)
	{
		if (*stream == '#')
		{
			while (*stream)
			{
				*stream = '\0';
				stream++;
			}
			break;
		}
		only_spaces += ft_isspace(*stream);
		stream++;
	}
	if (only_spaces == len)
	   return (1);
	return (0);	
}

t_dlist			**ft_lex_analyze(char *stream)
{
	t_dlist		**list_token;

	if (ft_scan_stream(stream))
		return (NULL);
	list_token = ft_lexer(stream);
	return (list_token);	
}
