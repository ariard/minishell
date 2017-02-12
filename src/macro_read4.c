/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_read4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:19:55 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 16:10:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_isendheredoc(char *buffer, t_info *info)
{
	t_dlist	*tmp;

	if (!*(info->delim))
		return (-1);
	tmp = *(info->delim);
	if (ft_strncmp(buffer, tmp->data, ft_strlen(tmp->data)) == 0)
	{
		info->heredocsize--;
		free(tmp->data);
		ft_list_rem_front(info->delim);
	}
	if (info->heredocsize == 0)
	{
		info->heredoc = 0;
		return (1);
	}
	return (0);
}
		
int			ft_endheredoc(char c)
{
	if (c == '&' || c == ';' || c == '|' || c == '>' || c == 13)
	   return (1);
	return (0);
}
