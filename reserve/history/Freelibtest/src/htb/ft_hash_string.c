/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:35:24 by ariard            #+#    #+#             */
/*   Updated: 2017/01/03 18:04:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int				ft_hash_string(const void *key, int size)
{
	const char	*ptr;
	unsigned 	int		tmp;
	unsigned 	int		val;

	val = 0;
	ptr = key;
	while (*ptr != '\0')
	{
		val = (val << 4) + (*ptr);
		if ((tmp = (val & 0xf0000000)))
		{
			val = val ^ (tmp >> 24);
			val = val ^ tmp;
		}
		ptr++;
	}
	return (val % size);
}
