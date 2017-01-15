/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:18:05 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 17:33:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

int				ft_atoi(const char *str)
{
	long long	nb;
	int			i;
	int			sign;

	nb = 0;
	i = 0;
	while (str[i] == 32 || str[i] == 9 || str[i] == 11 ||
			str[i] == 10 || str[i] == 12 || str[i] == 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i];
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (sign == '-')
		nb *= -1;
	return (nb);
}
