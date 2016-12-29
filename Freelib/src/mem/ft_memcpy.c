/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:39:04 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:34:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char		*p2;
	unsigned char			*p1;

	p1 = dst;
	p2 = src;
	while (n--)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	return (dst);
}
