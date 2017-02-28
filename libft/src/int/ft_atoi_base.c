/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:16:11 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 17:49:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int		ft_atoi_base(char *s, size_t size_base)
{
	unsigned long long int	nb;
	int						rank;

	if (!s || size_base < 2)
		return (0);
	nb = 0;
	rank = ft_strlen(s) - 1;
	while ((*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'f') ||
			(*s >= 'A' && *s <= 'F'))
	{
		if (*s >= '0' && *s <= '9')
			nb += (*s++ - '0') * ft_recursive_power(size_base, rank--);
		else if (*s >= 'a' && *s <= 'f')
			nb += (*s++ - 'W') * ft_recursive_power(size_base, rank--);
		else if (*s >= 'A' && *s <= 'F')
			nb += (*s++ - '7') * ft_recursive_power(size_base, rank--);
	}
	return (nb);
}
