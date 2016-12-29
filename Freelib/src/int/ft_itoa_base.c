/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:40:49 by ariard            #+#    #+#             */
/*   Updated: 2016/12/11 17:45:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

char		*ft_itoa_base(unsigned long long int nb,
		size_t size_base, char new[])
{
	char	*base;
	int		index;
	int		len;

	if (!new || size_base < 2)
		return (0);
	ft_bzero(new, 128);
	base = "0123456789abcdef";
	len = 0;
	if ((nb) == 0)
		new[len] = '0';
	while (nb)
	{
		index = nb % size_base;
		new[len++] = base[index];
		nb = nb / size_base;
	}
	new[len] = 0;
	ft_strrev(new);
	return (new);
}
