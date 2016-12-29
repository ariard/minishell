/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:53:04 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:34:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*p1;
	const unsigned char		*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
