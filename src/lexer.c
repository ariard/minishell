/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 14:54:04 by ariard            #+#    #+#             */
/*   Updated: 2017/02/13 18:28:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ft_token_free(void	*data)
{
	t_token			*token;

	token = data;
	ft_strdel(&token->name);
	ft_strdel(&token->id);
	free(token);
}
	
static char			*ft_detect_pattern(char *stream, t_info *info)
{
	char	*lexem;
	int		ret;

	lexem = ft_strnew(1024);
	if ((ret = ft_isspace(*stream)))
		return (lexem);
	if ((ret = ft_isoperator(stream)))
		return (ft_strncpy(lexem, stream, ret));
	if ((ret = ft_isoperand(stream, info)))
		return (ft_strncpy(lexem, stream, ret));
	return (lexem);
}

static t_token		*ft_gen_token(char *lexem, t_info *info)
{
	t_token			*token;

	token = ft_memalloc(sizeof(t_token));
	token->name = ft_strtrim(lexem); 
	if (ft_isoperator(lexem))
		token->id = ft_strdup("operator");
	else if (ft_isoperand(lexem, info))
		token->id = ft_strdup("operand");
	else
		token->id = ft_strdup("null");
	return (token);
}

t_dlist				**ft_lexer(char *stream, t_info *info)
{
	char	*lexem;
	t_dlist	**list_token;
	int		id;

	list_token = ft_memalloc(sizeof(t_dlist));
	*list_token = NULL;
	id = 0;
	while (*stream && *stream != '\n')
	{
		lexem = ft_detect_pattern(stream, info);
		if (ft_strlen(lexem) > 0)
		{
			ft_list_push_back(list_token, ft_gen_token(lexem, info), ft_itoa(id));
			id++;
		}
		if (ft_strlen(lexem) > 0)
			stream += ft_strlen(lexem);
		else
			stream++;
		ft_strdel(&lexem);
	}
	return (list_token);
}
