/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:09:16 by ariard            #+#    #+#             */
/*   Updated: 2016/11/30 20:51:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	n = ft_strlen(little);
	if (*little == 0)
		return (char *)(big);
	while (*big && len)
	{
		if (n > len)
			return (0);
		if (*big == *little)
			if (ft_strncmp(big, little, n) == 0)
				return (char *)(big);
		big++;
		len--;
	}
	return (0);
}
