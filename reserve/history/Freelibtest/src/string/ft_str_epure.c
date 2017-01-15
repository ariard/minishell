/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_epure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:12:51 by ariard            #+#    #+#             */
/*   Updated: 2017/01/15 16:18:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include <stdio.h>

static int			ft_count_pattern(char *str, char *pattern)
{
	int		len;
	char	*tmp;
	int		size;

	size = 0;
	tmp = str;
	len = ft_strlen(pattern);
	while (*tmp)
	{
		if (ft_strncmp(tmp, pattern, len) == 0)
		{
			size++;
			tmp += len;
		}
		tmp++;
	}
	return (size);
}

char		*ft_str_epure(char *str, char *pattern)
{
	int		len;
	char	*new;
	char	*tmp;

	tmp = str;
	len = ft_strlen(pattern);
	new = ft_memalloc(sizeof(char) * (ft_strlen(str) - 
				(len * ft_count_pattern(str, pattern)) + 1));
	tmp = new;
	while (*str)
	{
		if (ft_strncmp(str, pattern, len) == 0)
			str += len;
		else
			*new++ = *str++;
	}
	*new = 0;
	return (tmp);
}
