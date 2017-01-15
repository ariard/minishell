/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:52:14 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 17:22:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return (void *)(p);
		p++;
	}
	return (NULL);
}
