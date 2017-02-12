/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:54:40 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 16:21:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_extract_buff_auxi(char *buffer, t_info *info)
{
	char	*tmp;
	char	*new;

	tmp = buffer;
	new = ft_strnew(1024);
	while (*tmp && *tmp != '\n')
		tmp++;
	if (*tmp == '\n')
	{
		tmp++;
		if (*tmp)
			ft_strcpy(new, tmp);	
	}
	ft_strdel(&info->buff_auxi);
	info->buff_auxi = new;
}

char		*ft_extract_file(char *eof, char *buffer, t_info *info)
{
	char	*tmp;
	char	*new;
	int		len;
	
	new = ft_strnew(1024);
	tmp = new;
	if (info->previous_eof)
	{
		while (ft_strncmp(buffer, info->previous_eof,
			ft_strlen(info->previous_eof)))
			buffer++;
		len = ft_strlen(info->previous_eof) + 1;
		while (len--)
			buffer++;	
	}
	while (ft_strncmp(buffer, eof, ft_strlen(eof)) != 0)
	{
		*new++ = *buffer;
		*buffer++ = 0;
	}
	return (tmp);
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
