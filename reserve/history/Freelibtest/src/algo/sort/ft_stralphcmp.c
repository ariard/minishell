/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralphcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:13:25 by ariard            #+#    #+#             */
/*   Updated: 2016/12/29 20:13:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int			ft_stralphcmp(const void *s1, const void *s2)
{
	const char *str1;
	const char *str2;

	str1 = s1;
	str2 = s2;
	while (*str1 || *str2)
	{
		if (*str1 > *str2)
			return (-1);
		if (*str1 < *str2)
			return (1);
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
