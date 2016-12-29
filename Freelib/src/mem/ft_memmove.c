/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:49:04 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:35:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	if (s < d)
	{
		while (size)
		{
			size--;
			d[size] = s[size];
		}
	}
	else if (d < s)
		ft_memcpy(dest, src, size);
	return (dest);
}
