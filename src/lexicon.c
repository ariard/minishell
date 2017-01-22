/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 15:47:32 by ariard            #+#    #+#             */
/*   Updated: 2017/01/21 21:23:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_aggregation(char *stream)
{
	if (*stream)
		if (*(stream + 1))
		{
			if ((*stream == '>' || *stream == '<') && *(stream + 1) == '&')
				return (1);
		}	
	return (-1);
}

int			ft_isoperator(char *stream)
{
	if (*(stream + 1))
	{
		if (*stream == '&' && *(stream + 1) == '&')
			return (2);
		if (*stream == '>' && *(stream + 1) == '>')
			return (2);
		if (*stream == '|' && *(stream + 1) == '|')
			return (2);
		if (*stream == '<' && *(stream + 1) == '<')
			return (2);
	}
	if (*stream == '|')
		return (1);
	if (*stream == ';')
		return (1);
	if (*stream == '>' && ft_aggregation(stream) == -1)
		return (1);
	if (*stream == '<' && ft_aggregation(stream) == -1)
		return (1);
	return (0);
}

int			ft_isoperand(char *stream)
{
	int		ret;

	ret = 0;
	while (*stream != ';' && *stream != '|' && *stream && *stream != '\n')
	{
		if (*stream == '>' || *stream == '<')
		{
			if (ft_aggregation(stream) == -1)
				break;
			else
			{
				stream++;
				ret++;
			}
		}
		stream++;
		ret++;
	}
	return (ret);
}
