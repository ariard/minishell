/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:33:07 by ariard            #+#    #+#             */
/*   Updated: 2017/01/03 14:51:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

typedef struct		s_gnl
{
	int				ret;
	char			*check;
	char			*string;
	size_t			len;
	char			buf[BUFF_SIZE + 1];
}					t_gnl;

int					get_next_line(const int fd, char **line);

int					ft_getchar(const int fd, char *c);

#endif
