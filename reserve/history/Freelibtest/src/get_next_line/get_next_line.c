/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:05:43 by ariard            #+#    #+#             */
/*   Updated: 2016/12/31 00:25:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static t_gnl		ft_set_string(char *stock, const int fd)
{
	t_gnl			gnl;
	char			*tmp;

	gnl.check = NULL;
	gnl.ret = 1;
	gnl.string = ft_strdup(stock);
	while (gnl.check == NULL && gnl.ret > 0)
	{
		ft_memset(gnl.buf, 0, BUFF_SIZE + 1);
		gnl.ret = read(fd, gnl.buf, BUFF_SIZE);
		gnl.buf[BUFF_SIZE] = '\0';
		tmp = gnl.string;
		gnl.string = ft_strjoin(tmp, gnl.buf);
		ft_strdel(&tmp);
		gnl.check = ft_strchr(gnl.buf, 10);
	}
	return (gnl);
}

static int			ft_set_line(char **line, char *string)
{
	char			*tmp2;
	char			*tmp3;
	int				last;

	*line = ft_memalloc(sizeof(char));
	tmp2 = *line;
	tmp3 = string;
	while (*string != 10 && *string)
		string++;
	last = 0;
	if (*string == 0)
		last++;
	*string = '\0';
	*line = tmp3;
	ft_strdel(&tmp2);
	return (last);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stock;
	char			*tmp;
	int				last;
	t_gnl			gnl;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!stock)
		stock = ft_strnew(0);
	gnl = ft_set_string(stock, fd);
	if (*gnl.string == 0)
		return (gnl.ret);
	last = ft_set_line(line, gnl.string);
	while (*gnl.string != 10 && *gnl.string)
		gnl.string++;
	gnl.string++;
	if (*gnl.string && last == 0)
	{
		tmp = stock;
		stock = ft_strdup(gnl.string);
		ft_strdel(&tmp);
	}
	else
		ft_strdel(&stock);
	return (1);
}
