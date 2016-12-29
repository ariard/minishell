/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:47:35 by ariard            #+#    #+#             */
/*   Updated: 2016/11/30 21:06:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (*s2 == 0 || *s1 == 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (*s1 != '\0' && *s2 != '\0' && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	if ((*s1 && *s2 == '\0' && n) || (*s1 == '\0' && *s2 && n))
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
