/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:54:04 by ariard            #+#    #+#             */
/*   Updated: 2016/12/31 16:32:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_detect_pattern(char *stream)
{
	char	*lexem;
	int		ret;

	(void)stream;
	lexem = ft_strnew(1024);
	if ((ret = ft_isoperator(stream)))
		return (ft_strncpy(lexem, stream, ret));
	if ((ret = ft_isoperand(stream)))
		return (ft_strncpy(lexem, stream, ret));
	return (NULL);
}

void		ft_lexer(char *stream)
{
	char	*lexem;

	while (*stream)
	{
		lexem = ft_detect_pattern(stream);
		//		ft_match_pattern();
		//		ft_gen_lexemes;
		if (lexem)
			stream += ft_strlen(lexem);
		else
			stream++;
	}
}
