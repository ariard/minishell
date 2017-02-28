/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 23:04:54 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:38:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*dst && size != 0)
	{
		dst++;
		i++;
		size--;
	}
	if (size == 0)
		return (i + ft_strlen(src));
	j = 0;
	while (*src)
	{
		if (size != 1)
		{
			*dst++ = *src;
			size--;
		}
		src++;
		j++;
	}
	*dst = '\0';
	return (i + j);
}
