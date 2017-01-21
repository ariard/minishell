/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:54:40 by ariard            #+#    #+#             */
/*   Updated: 2017/01/21 17:44:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_extract_buff_auxi(char *buffer, t_info *info)
{
	char	*tmp;

	tmp = buffer;
	while (*tmp && *tmp != '\n')
		tmp++;
	if (*tmp == '\n')
	{
		tmp++;
		if (*tmp)
			ft_strcpy(info->buff_auxi, tmp);
	}
}	

void		ft_add_heredoc(char *buffer, t_info *info)
{
	char	*buf;
	char	*tmp;
	char	c;

	buf = ft_strnew(1024);
	tmp = buffer;
	c = '\0';
	while (*(tmp + 1))
		tmp++;
	tmp--;
	while (*(tmp - 1) && *(tmp - 1) != '<')
		tmp--;
	while (*tmp && ft_isspace(*tmp) == 1)
		tmp++;
	while (*tmp && ft_isalnum(*tmp) == 1)
	{
		c = *tmp;
		ft_strncat(buf, &c, 1);
		tmp++;
	}
	ft_list_push_back(info->delim, ft_strdup(buf), NULL);
	info->heredocsize++;
	ft_strdel(&buf);
}
