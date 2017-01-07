/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:54:04 by ariard            #+#    #+#             */
/*   Updated: 2017/01/06 15:53:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			*ft_detect_pattern(char *stream)
{
	char	*lexem;
	int		ret;

	lexem = ft_strnew(1024);
	if ((ret = ft_isspace(*stream)))
		return (NULL);
	if ((ret = ft_isoperator(stream)))
		return (ft_strncpy(lexem, stream, ret));
	if ((ret = ft_isoperand(stream)))
		return (ft_strncpy(lexem, stream, ret));
	return (NULL);
}

static t_token		*ft_gen_token(char *lexem)
{
	t_token			*token;

	token = ft_memalloc(sizeof(t_token));
	token->name = ft_strdup(ft_strtrim(lexem)); 
	if (ft_isoperator(lexem))
		token->id = ft_strdup("operator");
	else if (ft_isoperand(lexem))
		token->id = ft_strdup("operand");
	else
		token->id = ft_strdup("null");
	return (token);
}

t_dlist				**ft_lexer(char *stream)
{
	char	*lexem;
	t_dlist	**list_token;
	int		id;

	list_token = ft_memalloc(sizeof(t_dlist));
	*list_token = NULL;
	id = 0;
	while (*stream)
	{
		lexem = ft_detect_pattern(stream);
		if (lexem)
		{
			ft_list_push_back(list_token, ft_gen_token(lexem), ft_itoa(id));
			id++;
		}
		if (lexem)
			stream += ft_strlen(lexem);
		else
			stream++;
	}
	return (list_token);
}
