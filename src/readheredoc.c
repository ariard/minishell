/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readheredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:08:03 by ariard            #+#    #+#             */
/*   Updated: 2017/01/19 17:29:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_add_heredoc(char *buffer, t_info *info)
{
	char	*buf;
	char	*tmp;
	char	c;

	buf = ft_strnew(1024);
	tmp = buffer;
	c = '\0';
	if (*tmp == '&' || *tmp == ';' || *tmp == '|' || *tmp == '>')
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
	ft_strdel(&buf);
}

void		ft_read_heredoc(char *buffer, t_info *info)
{
	char	*tmp;
	int		len;

	(void)info;
	tmp = buffer;
	len = 0;
	while (*tmp)
	{
		if (ft_endheredoc(*tmp) || *(tmp + 1) == 0)
		{
			if (ft_isinheredoc(tmp) == 1)
				ft_add_heredoc(tmp, info);
			tmp++;
		}
		tmp++;
	}
}
